%{
	#include <stdlib.h>
	#include "y.tab.h"
	int lineno = 1;
	bool assign = false;
	#define STRDUP(var) var = new char[strlen(yytext)];strcpy(var,yytext);
%}

digit [0-9]
alpha [a-zA-z]

%%
\/\/.*\n {/*single  Line comment*/}
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/  {/* Multi line comment*/}

unsigned       {return UNSIGNED;}
signed         {return SIGNED;}
int            {return INT;}
float 		   {return FLOAT;}
bool           {return BOOL;}

while          {return WHILE;}
switch         {return SWITCH;}
case           {return CASE;}
default        {return DEFAULT;}
break          {return BREAK;}
do			   {return DO;}

= 			   {assign = true; return ASSIGN;}
"+="           {assign = true; return PLUSEQ;}
-=             {assign = true; return MINUSEQ;}
"*="           {assign = true; return TIMESEQ;}
"/="           {assign = true; return DIVIDEQ;}

"++"		   {return PLUSPLUS;}
"--"           {return MINUSMINUS;}

"+" 		   {return PLUS;}
-              {return MINUS;}
"*"  		   {return TIMES;}
"/"            {return DIVIDE;}
"**"              {return EXP;}

"||"           {return OR;}
&&             {return AND;}
!			   {return NOT;}

== 	 		   {return EQ;}
!= 			   {return NEQ;}
"<"  		   {return LT;}
"<=" 		   {return LEQ;}
>              {return GT;}
>= 			   {return GEQ;}

"("            {return  LP;}
")"            {return  RP;}	
"{"            {return  LB;}
"}"            {return  RB;}
,              {return  COMMA;}
;              {return  SEMICOLON;}
:              {return COLON;}

({digit}*\.{digit}+([eE][+\-]?{digit}+)?)  { STRDUP(yylval.exp.addr);return DOUBLENUM;}
({digit}+|({digit}+[eE][+]?{digit}+))      { STRDUP(yylval.exp.addr);return INTNUM;}
true          							   { return TRUE;}
false 									   { return FALSE;}
{alpha}({digit}|{alpha})*                  { STRDUP(yylval.exp.addr);return ID;}

[\r\t\f\v ]+  {/* remove whilte space*/}

\n { lineno++; }
#.* {/*Remove all #include  and #define */}

%%
