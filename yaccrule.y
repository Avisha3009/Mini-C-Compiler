%{
  #include <string.h>
  #include <cstring>
  #include <vector>
  #include "codegen.cpp"
  #define EMPTY -1
  using namespace std;
  extern FILE* yyin;
  extern int lineno;
  extern int colum;
  extern char *stream;
  int yylex(void);
  void yyerror(const char *);
  extern int nextInstr;
  int type;
  vector<YYSTYPE::BackpatchList*> breaklist;
  int break_current    = -1;
  extern bool assign ;
  int offset = 0;
  int widtharray[10] = {0,4,4,4,4,4,4,4,4,1};
  
%}

%token WHILE DO IF ELSE
%token SWITCH
%token CASE DEFAULT
%token INT FLOAT BOOL UNSIGNED SIGNED
%token ASSIGN PLUSEQ MINUSEQ TIMESEQ DIVIDEQ
%token PLUS MINUS TIMES DIVIDE EXP
%token OR AND NOT
%token EQ NEQ LT LEQ GT GEQ
%token LP RP
%token LB RB
%token COMMA
%token SEMICOLON COLON
%token DOUBLENUM INTNUM TRUE FALSE ID
%token PLUSPLUS MINUSMINUS
%token BREAK

%union{
  int type;

  struct marks{
    int instr;
  }mark;

  struct BackpatchList{
    int ins;
    BackpatchList *next;
  };

  struct info{
    char *addr;
    short  type;
    BackpatchList *tlist;
    BackpatchList *flist;
  }exp;

  struct nextL{
      int instr; /*Instruction number */
      BackpatchList *nextList; /*Linked list of Backpatch*/
  }List;
  
//Linked list of switch instruction which have to backpatch
  struct switchL{
    int instr;     /*Instruction number*/
    int lineno;    /*Line number where this list was found*/
    switchL *next; /*Next pointer of switch list*/
    bool stype;    /*default or case statement*/
    char *val;     /*Case value*/
  };
  switchL *switchList;
  char *str;
}

%type<str> RELOP
%type<type> var_type declaration init_declarator_list
%type<exp>  assignment_expression unary_expression postfix_expression primary_expression ID
logical_OR_expression logical_AND_expression 
equality_expression relational_expression Literals exponentiation_expression multiplicative_expression
additive_expression

%type<mark> marker
%type<List> statement Next selection_statement compound_statement iteration_statement jump_statement statement_list
%type<switchList> switch_statement case_list default_statement

%start Program
%%
Program:
  external_declaration{}
  |Program external_declaration{}
;

external_declaration:
  function
  |declaration_list 
;

//Function without argument
function:
  var_type ID LP  RP compound_statement{
	  backpatch($5.nextList,nextInstr);
	  genCode("return",0);
  }
;

compound_statement:
   LB statement_list RB{$$.nextList = $2.nextList;}
;

statement_list:
  statement_list marker statement {
    backpatch($1.nextList,$2.instr);
    $$.nextList = $3.nextList;
  }
  |statement {$$.nextList = $1.nextList;}
  |{$$.nextList = NULL;}
;

statement:
  expression_list {
    $$.nextList=NULL;
  }
  |declaration_list {
    $$.nextList=NULL;
  }
  |compound_statement {
    $$.nextList = $1.nextList;
  }
  |selection_statement {
    $$.nextList = $1.nextList;
  }
  |iteration_statement {
    $$.nextList = $1.nextList;
  }
  |jump_statement {
    $$.nextList = NULL;
  }
;

expression_list:
  SEMICOLON 
  |expression SEMICOLON
;

declaration_list:
  declaration
  |declaration_list declaration
;
declaration:
   var_type init_declarator_list SEMICOLON
;
var_type:
  INT {type = 1;}
  |SIGNED {type = 2;}
  |SIGNED INT {type= 3;}
  |UNSIGNED {type = 4;}
  |UNSIGNED INT { type=5;}
  |FLOAT {type=6;}
  |SIGNED FLOAT{type=7; }
  |UNSIGNED FLOAT{type=8; }
  |BOOL { type=9;}
;
init_declarator_list:
  ID {
  	InsertId($1.addr,lineno,type,offset);
  	offset+=widtharray[type];
  }
  |ID ASSIGN assignment_expression {
  	InsertId($1.addr,lineno,type,offset);
  	offset+=widtharray[type];
  	genCode($1.addr,$3.addr);
  }
  |init_declarator_list COMMA ID {
  	InsertId($3.addr,lineno,type,offset);
  	offset+=widtharray[type];
  }
  |init_declarator_list COMMA ID ASSIGN assignment_expression {
  	InsertId($3.addr,lineno,type,offset);
  	offset+=widtharray[type];
  	genCode($3.addr,$5.addr);
  }
;

//Selection statement e.g. switch(E){ }
selection_statement:
	SWITCH LP Next assignment_expression RP LB break_marker switch_statement RB Next {
	  YYSTYPE::switchL *l=NULL;
	  int in=nextInstr;
	  while($8!=NULL){
	    if($8->stype == true) {
        //if case stmt
        //cout<<$4.addr<<endl;
	      genCode("if",$4.addr," == ",$8->val,"goto",$8->instr);
        //cout<<$4.addr<<endl;

	    }
	    else {
	       l = $8;
	    }
	    $8=$8->next;
	  }
	  if(l!=NULL) {
	    genCode("goto",l->instr);
	    delete l;
	  }
	  backpatch($3.nextList,in); //Backpatch start of switch_statement
	  backpatch($10.nextList,nextInstr);//Backpatch end of switch_statement
	  backpatch(breaklist[break_current],nextInstr); //Backpatch break statement(s)
	  break_current--;
	}
;


/**Switch statement */
switch_statement:
  case_list{$$=$1;}
  |case_list default_statement {
  	$$ = mergeSwitchList($1,$2);
  }
  |default_statement case_list {
  	$$ = mergeSwitchList($1,$2);
  }
  |case_list default_statement case_list {
  	$$ = mergeSwitchList(mergeSwitchList($1,$2),$3);
  }
;
default_statement:
  DEFAULT COLON marker statement_list {
    $$=makeList($3.instr,false,NULL,EMPTY);
  }
;
case_list:
  CASE Literals COLON  marker statement_list {
    $$=makeList($4.instr,true,$2.addr,lineno);
  }
  |case_list CASE Literals COLON marker statement_list {
    $$ = makeList($5.instr,true,$3.addr,lineno);
    int line;
    if( (line=IsDuplicateCaseLabel($1,$3.addr)) != -1 ){
      AddError("duplicate case label",lineno,ERROR);
      AddError("previously used here",line,ERROR);
    }
    $$ = mergeSwitchList($1,$$);
  }
;
//break statement
jump_statement:
   BREAK SEMICOLON {
    if(break_current!=EMPTY){
      genCode("goto",EMPTY);
      
      breaklist[break_current]=mergeList(makeList(nextInstr-1),breaklist[break_current]);
      //cout<<"here";
      
    }
    else {
      AddError("break is not in switch statement",lineno,ERROR);
    }
  }
;
Next: {
  $$.nextList = makeList(nextInstr);
  genCode("goto",EMPTY);
  $$.instr = nextInstr;
}
;
break_marker: {
  break_current++;
  breaklist.push_back(NULL);
}
;

/*Iteration statement*/
iteration_statement:
  DO marker break_marker statement WHILE LP assignment_expression RP SEMICOLON {
      if($7.tlist  ==  NULL  && $7.flist  ==  NULL ){
        $7.tlist = makeList(nextInstr);
        genCode("if",$7.addr,"!=","0","goto",EMPTY);
        $7.flist = makeList(nextInstr);
        genCode("goto",EMPTY);
      }
      $$.nextList = $7.flist;
	    backpatch(breaklist[break_current],nextInstr); 
      backpatch($7.tlist,$2.instr);
      break_current--;
    }
;

/*Expression list a=b,a=b+c;a+=b+=c;**/
expression:
  assignment_expression 
  |expression COMMA assignment_expression 
;

/**Assignment expression e.g. constants , */
assignment_expression:
  logical_OR_expression {
      $$.addr  = $1.addr;
      $$.type  = $1.type;
      $$.tlist = $1.tlist;
      $$.flist = $1.flist;
  }
  |assignment_expression ASSIGN assignment_expression {
      genCode($1.addr,$3.addr);
      $$.flist = NULL;
      $$.tlist = NULL;
  }
  |assignment_expression PLUSEQ assignment_expression {
      $$.flist = NULL;
      $$.tlist = NULL;
      $$.addr  = newTemp();
      genCode($$.addr  ,$1.addr,"+",$3.addr);
      genCode($1.addr,$$.addr );
      $$.addr  = $1.addr;
  }
  |assignment_expression MINUSEQ assignment_expression {
      $$.flist = NULL;
      $$.tlist = NULL;
      $$.addr  = newTemp();
      genCode($$.addr  ,$1.addr,"-",$3.addr);
      genCode($1.addr,$$.addr );
      $$.addr  = $1.addr;
  }
  |assignment_expression TIMESEQ assignment_expression {
      $$.flist = NULL;
      $$.tlist = NULL;
      $$.addr  = newTemp();
      genCode($$.addr  ,$1.addr,"*",$3.addr);
      genCode($1.addr,$$.addr );
      $$.addr  = $1.addr;
  }
  |assignment_expression DIVIDEQ assignment_expression {
       $$.flist = NULL;
       $$.tlist = NULL;
        $$.addr  = newTemp();
        genCode($$.addr  ,$1.addr,"/",$3.addr);
        genCode($1.addr,$$.addr );
        $$.addr  = $1.addr;
  }
;

logical_OR_expression:
  logical_AND_expression {
      $$.addr  = $1.addr;
      $$.type  = $1.type;
      $$.flist = $1.flist;
      $$.tlist = $1.tlist;
  }
  |logical_OR_expression {
	    if($1.tlist  ==  NULL  && $1.flist   ==  NULL ){
	        genCode("if",$1.addr,"!=","0","goto",EMPTY);
	            genCode("goto",EMPTY);
	            $1.tlist = makeList(nextInstr-2);
	            $1.flist = makeList(nextInstr-1);
	    }
    }OR marker logical_AND_expression {
      if($5.tlist  ==  NULL  && $5.flist   ==  NULL ){
        genCode("if",$5.addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            $5.tlist = makeList(nextInstr-2);
            $5.flist = makeList(nextInstr-1);
      }
      backpatch($1.flist,$4.instr);
      $$.flist = $5.flist;
      $$.tlist = mergeList($1.tlist,$5.tlist);
  }
;

logical_AND_expression:
  equality_expression {
    $$.addr  = $1.addr;
    $$.type  = $1.type;
    $$.flist = $1.flist;
    $$.tlist = $1.tlist;
  }
  |logical_AND_expression {
        if($1.tlist  ==  NULL  && $1.flist   ==  NULL ){
          genCode("if",$1.addr,"!=","0","goto",EMPTY);
          genCode("goto",EMPTY);
          $1.tlist = makeList(nextInstr-2);
          $1.flist = makeList(nextInstr-1);
    	  }
    }AND marker equality_expression {
      if($5.tlist  ==  NULL  && $5.flist   ==  NULL ){
        genCode("if",$5.addr,"!=","0","goto",EMPTY);
        genCode("goto",EMPTY);
        $5.tlist = makeList(nextInstr-2);
        $5.flist = makeList(nextInstr-1);
      }
      backpatch($1.tlist,$4.instr);
      $$.tlist = $5.tlist;
      $$.flist = mergeList($1.flist,$5.flist);
      }
;

equality_expression:
  relational_expression {
      $$.addr   = $1.addr;
      $$.type   = $1.type;
      $$.tlist  = $1.tlist;
      $$.flist  = $1.flist;
  }
  |equality_expression EQ relational_expression {
      $$.tlist = makeList(nextInstr);
      $$.flist = makeList(nextInstr+1);
      genCode("if",$1.addr," == ",$3.addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
  |equality_expression NEQ relational_expression {
      $$.tlist = makeList(nextInstr);
      $$.flist = makeList(nextInstr+1);
      genCode("if",$1.addr,"!=",$3.addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
;

relational_expression:
  additive_expression {
    $$.addr   = $1.addr;
    $$.type   = $1.type;
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
  }
  |relational_expression RELOP  additive_expression {
      $$.tlist = makeList(nextInstr);
      $$.flist = makeList(nextInstr+1);
      genCode("if",$1.addr,$2,$3.addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
;

RELOP:
     GT  {$$=(char*)">";}
   | GEQ {$$ =(char*)">=";}
   | LT  {$$ =(char*)"<";}
   | LEQ {$$ =(char*)"<=";}
;

additive_expression:
  multiplicative_expression {
      $$.addr   = $1.addr;
      $$.type   = $1.type;
      $$.tlist  = $1.tlist;
      $$.flist  = $1.flist;
  }
  |additive_expression PLUS multiplicative_expression {
      $$.addr   = newTemp();
      $$.type   = $1.type;
      $$.tlist  = NULL;
      $$.flist  = NULL;
      genCode($$.addr  ,$1.addr,"+",$3.addr);
  }
  |additive_expression MINUS multiplicative_expression {
      $$.addr   = newTemp();
      $$.type   = $1.type;
      $$.tlist  = NULL;
      $$.flist  = NULL;
      genCode($$.addr  ,$1.addr,"-",$3.addr);
  }
  ;

  multiplicative_expression:
    exponentiation_expression {
      $$.addr   = $1.addr;
      $$.type   = $1.type;
      $$.tlist  = $1.tlist;
      $$.flist  = $1.flist;
  }
  | multiplicative_expression TIMES exponentiation_expression {
      $$.addr   = newTemp();
      $$.type   = $1.type;
      $$.tlist  = NULL;
      $$.flist  = NULL;
      genCode($$.addr  ,$1.addr,"*",$3.addr);
  }
  | multiplicative_expression DIVIDE exponentiation_expression {
      $$.addr   = newTemp();
      $$.type   = $1.type;
      $$.tlist  = NULL;
      $$.flist  = NULL;
      genCode($$.addr  ,$1.addr,"/",$3.addr);
  }
;

exponentiation_expression :
  unary_expression {
    $$.addr   = $1.addr;
    $$.type   = $1.type;
    $$.flist  = $1.flist;
    $$.tlist  = $1.tlist;
  }
  | unary_expression EXP exponentiation_expression {
    $$.addr   = newTemp();
    $$.type   = $1.type;
    $$.tlist  = NULL;
    $$.flist  = NULL;
    genCode($$.addr  ,$1.addr,"**",$3.addr);
  }
;

unary_expression:
  postfix_expression {
    $$.addr   = $1.addr;
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
  }
  |PLUSPLUS unary_expression {
     $$.addr   = newTemp();
     $$.tlist  = $2.tlist;
     $$.flist  = $2.flist;
     genCode($$.addr ,$2.addr,"+","1");
     genCode($2.addr,$$.addr );
  }
  |MINUSMINUS unary_expression {
     $$.addr   = newTemp();
     $$.tlist  = $2.tlist;
     $$.flist  = $2.flist;
     genCode($$.addr ,$2.addr,"-","1");
     genCode($2.addr,$$.addr );
  }
  |PLUS unary_expression {
      $$.addr   = $2.addr;
      $$.tlist  = $2.tlist;
      $$.flist  = $2.flist;
    }
  |MINUS unary_expression {
      $$.addr   = newTemp();
      $$.tlist  = $2.tlist;
      $$.flist  = $2.flist;
      genCode($$.addr ,"-1","*",$2.addr);
  }
  |NOT unary_expression {
      if($2.tlist  ==  NULL  && $2.flist   ==  NULL ){
        genCode("if",$2.addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            $2.tlist = makeList(nextInstr-2);
            $2.flist = makeList(nextInstr-1);
    }
      $$.addr   = newTemp();
      $$.tlist  = $2.flist;
      $$.flist  = $2.tlist;
  }
;

postfix_expression:
  primary_expression {
    $$.addr   = $1.addr;
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
  }
  |postfix_expression PLUSPLUS {
    $$.addr   = newTemp();
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
    genCode($$.addr ,$1.addr);
    genCode($1.addr,$$.addr ,"+","1");
  }
  |postfix_expression MINUSMINUS {
    $$.addr   = newTemp();
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
    genCode($$.addr ,$1.addr);
    genCode($1.addr,$$.addr ,"-","1");
  }
;

primary_expression:
 ID {
  $$.addr   = $1.addr;
  $$.tlist  = NULL;
  $$.flist  = NULL;
  if(!IsPresent($1.addr)){
    char *errmsg =  new char[256];
    strcpy(errmsg,"'");
    strcat(errmsg,$$.addr);
    strcat(errmsg,"' was not declared");
    AddError(errmsg,lineno,ERROR);
    delete[] errmsg;
  }
 }
 |Literals {
    $$.addr   = $1.addr;
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
  }
  |LP assignment_expression RP {
    $$.addr  = $2.addr;
    $$.flist  = $2.flist;
    $$.tlist  = $2.tlist;
  }
;

Literals:
  INTNUM {
    $$.type  = INTNUM;
    $$.flist = NULL;
    $$.tlist = NULL;
  }
  | DOUBLENUM {
    $$.type  = DOUBLENUM;
    $$.flist = NULL;
    $$.tlist = NULL;
  }
  | TRUE {
    $$.addr = new char[2];
    $$.addr = (char*)"1";
    $$.type = BOOL;
    if(!assign){
    	 $$.tlist = makeList(nextInstr);
	     $$.flist = NULL;
	     genCode("goto",EMPTY);
    }
    else{
		assign = false;
	  }
  }
  | FALSE {
    $$.addr = new char[2];
    $$.addr = (char*)"0";
    $$.type   = BOOL;
    if(!assign){
	    $$.flist = makeList(nextInstr);
	    $$.tlist = NULL;
	    genCode("goto",EMPTY);
	}
	else {
		assign = false;
	}
  }
;

marker: {$$.instr = nextInstr;}
;

%%
void yyerror(const char *s){
  AddError((char*)" ...is missing",lineno,ERROR);
}
int main(int argc,char *argv[]) {
    FILE* fp=NULL;
    if(argc<2){
      fprintf(stderr,"No input file\n");
      return 0;
    }
    if(argc == 2) {
      fp=fopen(argv[1],"r");
    }
    if(fp==NULL) {
          fprintf(stderr, "Error opening file: %s\n", strerror(errno));
          return 0;
    }
    yyin=fp;
    InitializeSymbolTable();
    Error = NULL;
    while(!feof(yyin)) {
      yyparse();
    }
    printStable();
    fclose(fp);
    DeleteSymbolTable();
    if(Error==NULL) printCode();
    else {
      printError();
    }
    return 0;
}
