/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     WHILE = 258,
     DO = 259,
     IF = 260,
     ELSE = 261,
     SWITCH = 262,
     CASE = 263,
     DEFAULT = 264,
     INT = 265,
     FLOAT = 266,
     BOOL = 267,
     UNSIGNED = 268,
     SIGNED = 269,
     ASSIGN = 270,
     PLUSEQ = 271,
     MINUSEQ = 272,
     TIMESEQ = 273,
     DIVIDEQ = 274,
     PLUS = 275,
     MINUS = 276,
     TIMES = 277,
     DIVIDE = 278,
     EXP = 279,
     OR = 280,
     AND = 281,
     NOT = 282,
     EQ = 283,
     NEQ = 284,
     LT = 285,
     LEQ = 286,
     GT = 287,
     GEQ = 288,
     LP = 289,
     RP = 290,
     LB = 291,
     RB = 292,
     COMMA = 293,
     SEMICOLON = 294,
     COLON = 295,
     DOUBLENUM = 296,
     INTNUM = 297,
     TRUE = 298,
     FALSE = 299,
     ID = 300,
     PLUSPLUS = 301,
     MINUSMINUS = 302,
     BREAK = 303
   };
#endif
/* Tokens.  */
#define WHILE 258
#define DO 259
#define IF 260
#define ELSE 261
#define SWITCH 262
#define CASE 263
#define DEFAULT 264
#define INT 265
#define FLOAT 266
#define BOOL 267
#define UNSIGNED 268
#define SIGNED 269
#define ASSIGN 270
#define PLUSEQ 271
#define MINUSEQ 272
#define TIMESEQ 273
#define DIVIDEQ 274
#define PLUS 275
#define MINUS 276
#define TIMES 277
#define DIVIDE 278
#define EXP 279
#define OR 280
#define AND 281
#define NOT 282
#define EQ 283
#define NEQ 284
#define LT 285
#define LEQ 286
#define GT 287
#define GEQ 288
#define LP 289
#define RP 290
#define LB 291
#define RB 292
#define COMMA 293
#define SEMICOLON 294
#define COLON 295
#define DOUBLENUM 296
#define INTNUM 297
#define TRUE 298
#define FALSE 299
#define ID 300
#define PLUSPLUS 301
#define MINUSMINUS 302
#define BREAK 303




/* Copy the first part of user declarations.  */
#line 1 "yaccrule.y"

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
  


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 40 "yaccrule.y"
{
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
/* Line 193 of yacc.c.  */
#line 251 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 264 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    18,    22,    26,
      28,    29,    31,    33,    35,    37,    39,    41,    43,    46,
      48,    51,    55,    57,    59,    62,    64,    67,    69,    72,
      75,    77,    79,    83,    87,    93,   104,   106,   109,   112,
     116,   121,   127,   134,   137,   138,   139,   149,   151,   155,
     157,   161,   165,   169,   173,   177,   179,   180,   186,   188,
     189,   195,   197,   201,   205,   207,   211,   213,   215,   217,
     219,   221,   225,   229,   231,   235,   239,   241,   245,   247,
     250,   253,   256,   259,   262,   264,   267,   270,   272,   274,
     278,   280,   282,   284,   286
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    50,    51,    -1,    52,    -1,
      57,    -1,    59,    45,    34,    35,    53,    -1,    36,    54,
      37,    -1,    54,    85,    55,    -1,    55,    -1,    -1,    56,
      -1,    57,    -1,    53,    -1,    61,    -1,    68,    -1,    65,
      -1,    39,    -1,    69,    39,    -1,    58,    -1,    57,    58,
      -1,    59,    60,    39,    -1,    10,    -1,    14,    -1,    14,
      10,    -1,    13,    -1,    13,    10,    -1,    11,    -1,    14,
      11,    -1,    13,    11,    -1,    12,    -1,    45,    -1,    45,
      15,    70,    -1,    60,    38,    45,    -1,    60,    38,    45,
      15,    70,    -1,     7,    34,    66,    70,    35,    36,    67,
      62,    37,    66,    -1,    64,    -1,    64,    63,    -1,    63,
      64,    -1,    64,    63,    64,    -1,     9,    40,    85,    54,
      -1,     8,    84,    40,    85,    54,    -1,    64,     8,    84,
      40,    85,    54,    -1,    48,    39,    -1,    -1,    -1,     4,
      85,    67,    55,     3,    34,    70,    35,    39,    -1,    70,
      -1,    69,    38,    70,    -1,    71,    -1,    70,    15,    70,
      -1,    70,    16,    70,    -1,    70,    17,    70,    -1,    70,
      18,    70,    -1,    70,    19,    70,    -1,    73,    -1,    -1,
      71,    72,    25,    85,    73,    -1,    75,    -1,    -1,    73,
      74,    26,    85,    75,    -1,    76,    -1,    75,    28,    76,
      -1,    75,    29,    76,    -1,    78,    -1,    76,    77,    78,
      -1,    32,    -1,    33,    -1,    30,    -1,    31,    -1,    79,
      -1,    78,    20,    79,    -1,    78,    21,    79,    -1,    80,
      -1,    79,    22,    80,    -1,    79,    23,    80,    -1,    81,
      -1,    81,    24,    80,    -1,    82,    -1,    46,    81,    -1,
      47,    81,    -1,    20,    81,    -1,    21,    81,    -1,    27,
      81,    -1,    83,    -1,    82,    46,    -1,    82,    47,    -1,
      45,    -1,    84,    -1,    34,    70,    35,    -1,    42,    -1,
      41,    -1,    43,    -1,    44,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    91,    95,    96,   101,   108,   112,   116,
     117,   121,   124,   127,   130,   133,   136,   142,   143,   147,
     148,   151,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   165,   169,   174,   178,   187,   217,   218,   221,   224,
     229,   234,   237,   249,   262,   268,   276,   292,   293,   298,
     304,   309,   317,   325,   333,   344,   350,   350,   371,   377,
     377,   398,   404,   410,   419,   425,   434,   435,   436,   437,
     441,   447,   454,   464,   470,   477,   487,   493,   503,   508,
     515,   522,   527,   533,   547,   552,   559,   569,   582,   587,
     595,   600,   605,   618,   633
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "DO", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "INT", "FLOAT", "BOOL", "UNSIGNED", "SIGNED",
  "ASSIGN", "PLUSEQ", "MINUSEQ", "TIMESEQ", "DIVIDEQ", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "EXP", "OR", "AND", "NOT", "EQ", "NEQ", "LT", "LEQ",
  "GT", "GEQ", "LP", "RP", "LB", "RB", "COMMA", "SEMICOLON", "COLON",
  "DOUBLENUM", "INTNUM", "TRUE", "FALSE", "ID", "PLUSPLUS", "MINUSMINUS",
  "BREAK", "$accept", "Program", "external_declaration", "function",
  "compound_statement", "statement_list", "statement", "expression_list",
  "declaration_list", "declaration", "var_type", "init_declarator_list",
  "selection_statement", "switch_statement", "default_statement",
  "case_list", "jump_statement", "Next", "break_marker",
  "iteration_statement", "expression", "assignment_expression",
  "logical_OR_expression", "@1", "logical_AND_expression", "@2",
  "equality_expression", "relational_expression", "RELOP",
  "additive_expression", "multiplicative_expression",
  "exponentiation_expression", "unary_expression", "postfix_expression",
  "primary_expression", "Literals", "marker", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    53,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    62,    62,    62,    62,
      63,    64,    64,    65,    66,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    72,    71,    73,    74,
      73,    75,    75,    75,    76,    76,    77,    77,    77,    77,
      78,    78,    78,    79,    79,    79,    80,    80,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     3,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     3,     1,     1,     2,     1,     2,     1,     2,     2,
       1,     1,     3,     3,     5,    10,     1,     2,     2,     3,
       4,     5,     6,     2,     0,     0,     9,     1,     3,     1,
       3,     3,     3,     3,     3,     1,     0,     5,     1,     0,
       5,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    27,    30,    25,    23,     0,     2,     4,     5,
      19,     0,    26,    29,    24,    28,     1,     3,    20,     0,
      31,     0,    31,     0,     0,     0,    21,     0,     0,     0,
       0,    91,    90,    92,    93,    87,     0,     0,    32,    49,
      55,    58,    61,    64,    70,    73,    76,    78,    84,    88,
       0,    33,    81,    82,    83,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,    66,
      67,     0,     0,     0,     0,     0,     0,    85,    86,    10,
       6,     0,    89,    50,    51,    52,    53,    54,    94,    94,
      62,    63,    65,    71,    72,    74,    75,    77,    94,     0,
      17,     0,    13,    94,     9,    11,    12,    14,    16,    15,
       0,    47,    34,     0,     0,    45,    44,    43,     7,     0,
       0,    18,    57,    60,     0,     0,     8,    48,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    36,    46,     0,    94,    44,    38,     0,    37,    94,
      10,    35,     0,    39,    10,    94,    94,    94,    10,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   102,   103,   104,   105,   106,    10,
      19,    21,   107,   139,   140,   141,   108,   125,   124,   109,
     110,   111,    39,    63,    40,    64,    41,    42,    71,    43,
      44,    45,    46,    47,    48,    49,   119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
     117,  -136,  -136,  -136,    85,   131,   101,  -136,  -136,   117,
    -136,   -39,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   -35,
     -10,   105,     8,    45,    -6,   -20,  -136,    45,    45,    45,
      45,  -136,  -136,  -136,  -136,  -136,    45,    45,   118,    15,
      30,   119,    37,   125,   127,  -136,    61,   106,  -136,  -136,
      63,    46,  -136,  -136,  -136,    59,  -136,  -136,    45,    45,
      45,    45,    45,    68,    82,    45,    45,  -136,  -136,  -136,
    -136,    45,    45,    45,    45,    45,    45,  -136,  -136,     7,
    -136,    45,  -136,   118,   118,   118,   118,   118,  -136,  -136,
      37,    37,   125,   127,   127,  -136,  -136,  -136,  -136,    76,
    -136,    93,  -136,    87,  -136,  -136,   117,  -136,  -136,  -136,
     116,   118,   118,    45,    45,  -136,  -136,  -136,  -136,     7,
      45,  -136,    30,   119,     7,    45,  -136,   118,   161,    65,
     132,   115,    45,  -136,    88,   148,   126,    78,   128,   130,
     162,   150,  -136,   129,  -136,  -136,   163,    78,   162,  -136,
       7,  -136,   133,   163,     7,    25,  -136,    23,     7,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   166,  -136,   124,  -128,   -77,  -136,     9,    -8,
      57,  -136,  -136,  -136,    34,  -132,  -136,    31,    44,  -136,
    -136,   -23,  -136,  -136,    66,  -136,    67,    95,  -136,   107,
      90,    64,    89,  -136,  -136,  -135,   -85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      38,    18,   143,   113,   114,    23,    20,    55,   146,     9,
      22,    98,   152,   115,    99,     9,   153,     1,     2,     3,
       4,     5,   155,    23,    24,    51,   157,    27,    28,    50,
     159,   -41,   -41,   -40,    29,    83,    84,    85,    86,    87,
     -56,    30,   126,    79,   -42,   -42,   100,   128,    31,    32,
      33,    34,    35,    36,    37,   101,   -59,    11,   112,   150,
     -41,    81,   -40,    11,   154,    27,    28,    67,    68,    69,
      70,   158,    29,   -42,    58,    59,    60,    61,    62,    30,
      58,    59,    60,    61,    62,    76,    31,    32,    33,    34,
      35,    36,    37,    88,    82,    12,    13,   127,    18,    79,
     131,    16,   129,    58,    59,    60,    61,    62,    89,   134,
     116,     1,     2,     3,     4,     5,    52,    53,    54,    31,
      32,    33,    34,   136,   118,    56,    57,     1,     2,     3,
       4,     5,   117,    58,    59,    60,    61,    62,    95,    96,
      97,    14,    15,    25,    26,    72,    73,    65,    66,    74,
      75,   133,    77,    78,   120,   121,   137,   138,   147,   138,
      90,    91,    93,    94,   130,   142,   132,   145,   144,   149,
     137,   147,    17,   156,    80,   148,   151,   135,    92,   122,
       0,   123
};

static const yytype_int16 yycheck[] =
{
      23,     9,   137,    88,    89,    15,    45,    30,   140,     0,
      45,     4,   147,    98,     7,     6,   148,    10,    11,    12,
      13,    14,   150,    15,    34,    45,   154,    20,    21,    35,
     158,     8,     9,     8,    27,    58,    59,    60,    61,    62,
      25,    34,   119,    36,     8,     9,    39,   124,    41,    42,
      43,    44,    45,    46,    47,    48,    26,     0,    81,   144,
      37,    15,    37,     6,   149,    20,    21,    30,    31,    32,
      33,   156,    27,    37,    15,    16,    17,    18,    19,    34,
      15,    16,    17,    18,    19,    24,    41,    42,    43,    44,
      45,    46,    47,    25,    35,    10,    11,   120,   106,    36,
      35,     0,   125,    15,    16,    17,    18,    19,    26,   132,
      34,    10,    11,    12,    13,    14,    27,    28,    29,    41,
      42,    43,    44,    35,    37,    36,    37,    10,    11,    12,
      13,    14,    39,    15,    16,    17,    18,    19,    74,    75,
      76,    10,    11,    38,    39,    20,    21,    28,    29,    22,
      23,    36,    46,    47,    38,    39,     8,     9,     8,     9,
      65,    66,    72,    73,     3,    39,    34,    37,    40,    40,
       8,     8,     6,    40,    50,   141,   145,   133,    71,   113,
      -1,   114
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    13,    14,    50,    51,    52,    57,
      58,    59,    10,    11,    10,    11,     0,    51,    58,    59,
      45,    60,    45,    15,    34,    38,    39,    20,    21,    27,
      34,    41,    42,    43,    44,    45,    46,    47,    70,    71,
      73,    75,    76,    78,    79,    80,    81,    82,    83,    84,
      35,    45,    81,    81,    81,    70,    81,    81,    15,    16,
      17,    18,    19,    72,    74,    28,    29,    30,    31,    32,
      33,    77,    20,    21,    22,    23,    24,    46,    47,    36,
      53,    15,    35,    70,    70,    70,    70,    70,    25,    26,
      76,    76,    78,    79,    79,    80,    80,    80,     4,     7,
      39,    48,    53,    54,    55,    56,    57,    61,    65,    68,
      69,    70,    70,    85,    85,    85,    34,    39,    37,    85,
      38,    39,    73,    75,    67,    66,    55,    70,    55,    70,
       3,    35,    34,    36,    70,    67,    35,     8,     9,    62,
      63,    64,    39,    84,    40,    37,    64,     8,    63,    40,
      85,    66,    84,    64,    85,    54,    40,    54,    85,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 90 "yaccrule.y"
    {}
    break;

  case 3:
#line 91 "yaccrule.y"
    {}
    break;

  case 6:
#line 101 "yaccrule.y"
    {
	  backpatch((yyvsp[(5) - (5)].List).nextList,nextInstr);
	  genCode("return",0);
  }
    break;

  case 7:
#line 108 "yaccrule.y"
    {(yyval.List).nextList = (yyvsp[(2) - (3)].List).nextList;}
    break;

  case 8:
#line 112 "yaccrule.y"
    {
    backpatch((yyvsp[(1) - (3)].List).nextList,(yyvsp[(2) - (3)].mark).instr);
    (yyval.List).nextList = (yyvsp[(3) - (3)].List).nextList;
  }
    break;

  case 9:
#line 116 "yaccrule.y"
    {(yyval.List).nextList = (yyvsp[(1) - (1)].List).nextList;}
    break;

  case 10:
#line 117 "yaccrule.y"
    {(yyval.List).nextList = NULL;}
    break;

  case 11:
#line 121 "yaccrule.y"
    {
    (yyval.List).nextList=NULL;
  }
    break;

  case 12:
#line 124 "yaccrule.y"
    {
    (yyval.List).nextList=NULL;
  }
    break;

  case 13:
#line 127 "yaccrule.y"
    {
    (yyval.List).nextList = (yyvsp[(1) - (1)].List).nextList;
  }
    break;

  case 14:
#line 130 "yaccrule.y"
    {
    (yyval.List).nextList = (yyvsp[(1) - (1)].List).nextList;
  }
    break;

  case 15:
#line 133 "yaccrule.y"
    {
    (yyval.List).nextList = (yyvsp[(1) - (1)].List).nextList;
  }
    break;

  case 16:
#line 136 "yaccrule.y"
    {
    (yyval.List).nextList = NULL;
  }
    break;

  case 22:
#line 154 "yaccrule.y"
    {type = 1;}
    break;

  case 23:
#line 155 "yaccrule.y"
    {type = 2;}
    break;

  case 24:
#line 156 "yaccrule.y"
    {type= 3;}
    break;

  case 25:
#line 157 "yaccrule.y"
    {type = 4;}
    break;

  case 26:
#line 158 "yaccrule.y"
    { type=5;}
    break;

  case 27:
#line 159 "yaccrule.y"
    {type=6;}
    break;

  case 28:
#line 160 "yaccrule.y"
    {type=7; }
    break;

  case 29:
#line 161 "yaccrule.y"
    {type=8; }
    break;

  case 30:
#line 162 "yaccrule.y"
    { type=9;}
    break;

  case 31:
#line 165 "yaccrule.y"
    {
  	InsertId((yyvsp[(1) - (1)].exp).addr,lineno,type,offset);
  	offset+=widtharray[type];
  }
    break;

  case 32:
#line 169 "yaccrule.y"
    {
  	InsertId((yyvsp[(1) - (3)].exp).addr,lineno,type,offset);
  	offset+=widtharray[type];
  	genCode((yyvsp[(1) - (3)].exp).addr,(yyvsp[(3) - (3)].exp).addr);
  }
    break;

  case 33:
#line 174 "yaccrule.y"
    {
  	InsertId((yyvsp[(3) - (3)].exp).addr,lineno,type,offset);
  	offset+=widtharray[type];
  }
    break;

  case 34:
#line 178 "yaccrule.y"
    {
  	InsertId((yyvsp[(3) - (5)].exp).addr,lineno,type,offset);
  	offset+=widtharray[type];
  	genCode((yyvsp[(3) - (5)].exp).addr,(yyvsp[(5) - (5)].exp).addr);
  }
    break;

  case 35:
#line 187 "yaccrule.y"
    {
	  YYSTYPE::switchL *l=NULL;
	  int in=nextInstr;
	  while((yyvsp[(8) - (10)].switchList)!=NULL){
	    if((yyvsp[(8) - (10)].switchList)->stype == true) {
        //if case stmt
        //cout<<$4.addr<<endl;
	      genCode("if",(yyvsp[(4) - (10)].exp).addr," == ",(yyvsp[(8) - (10)].switchList)->val,"goto",(yyvsp[(8) - (10)].switchList)->instr);
        //cout<<$4.addr<<endl;

	    }
	    else {
	       l = (yyvsp[(8) - (10)].switchList);
	    }
	    (yyvsp[(8) - (10)].switchList)=(yyvsp[(8) - (10)].switchList)->next;
	  }
	  if(l!=NULL) {
	    genCode("goto",l->instr);
	    delete l;
	  }
	  backpatch((yyvsp[(3) - (10)].List).nextList,in); //Backpatch start of switch_statement
	  backpatch((yyvsp[(10) - (10)].List).nextList,nextInstr);//Backpatch end of switch_statement
	  backpatch(breaklist[break_current],nextInstr); //Backpatch break statement(s)
	  break_current--;
	}
    break;

  case 36:
#line 217 "yaccrule.y"
    {(yyval.switchList)=(yyvsp[(1) - (1)].switchList);}
    break;

  case 37:
#line 218 "yaccrule.y"
    {
  	(yyval.switchList) = mergeSwitchList((yyvsp[(1) - (2)].switchList),(yyvsp[(2) - (2)].switchList));
  }
    break;

  case 38:
#line 221 "yaccrule.y"
    {
  	(yyval.switchList) = mergeSwitchList((yyvsp[(1) - (2)].switchList),(yyvsp[(2) - (2)].switchList));
  }
    break;

  case 39:
#line 224 "yaccrule.y"
    {
  	(yyval.switchList) = mergeSwitchList(mergeSwitchList((yyvsp[(1) - (3)].switchList),(yyvsp[(2) - (3)].switchList)),(yyvsp[(3) - (3)].switchList));
  }
    break;

  case 40:
#line 229 "yaccrule.y"
    {
    (yyval.switchList)=makeList((yyvsp[(3) - (4)].mark).instr,false,NULL,EMPTY);
  }
    break;

  case 41:
#line 234 "yaccrule.y"
    {
    (yyval.switchList)=makeList((yyvsp[(4) - (5)].mark).instr,true,(yyvsp[(2) - (5)].exp).addr,lineno);
  }
    break;

  case 42:
#line 237 "yaccrule.y"
    {
    (yyval.switchList) = makeList((yyvsp[(5) - (6)].mark).instr,true,(yyvsp[(3) - (6)].exp).addr,lineno);
    int line;
    if( (line=IsDuplicateCaseLabel((yyvsp[(1) - (6)].switchList),(yyvsp[(3) - (6)].exp).addr)) != -1 ){
      AddError("duplicate case label",lineno,ERROR);
      AddError("previously used here",line,ERROR);
    }
    (yyval.switchList) = mergeSwitchList((yyvsp[(1) - (6)].switchList),(yyval.switchList));
  }
    break;

  case 43:
#line 249 "yaccrule.y"
    {
    if(break_current!=EMPTY){
      genCode("goto",EMPTY);
      
      breaklist[break_current]=mergeList(makeList(nextInstr-1),breaklist[break_current]);
      //cout<<"here";
      
    }
    else {
      AddError("break is not in switch statement",lineno,ERROR);
    }
  }
    break;

  case 44:
#line 262 "yaccrule.y"
    {
  (yyval.List).nextList = makeList(nextInstr);
  genCode("goto",EMPTY);
  (yyval.List).instr = nextInstr;
}
    break;

  case 45:
#line 268 "yaccrule.y"
    {
  break_current++;
  breaklist.push_back(NULL);
}
    break;

  case 46:
#line 276 "yaccrule.y"
    {
      if((yyvsp[(7) - (9)].exp).tlist  ==  NULL  && (yyvsp[(7) - (9)].exp).flist  ==  NULL ){
        (yyvsp[(7) - (9)].exp).tlist = makeList(nextInstr);
        genCode("if",(yyvsp[(7) - (9)].exp).addr,"!=","0","goto",EMPTY);
        (yyvsp[(7) - (9)].exp).flist = makeList(nextInstr);
        genCode("goto",EMPTY);
      }
      (yyval.List).nextList = (yyvsp[(7) - (9)].exp).flist;
	    backpatch(breaklist[break_current],nextInstr); 
      backpatch((yyvsp[(7) - (9)].exp).tlist,(yyvsp[(2) - (9)].mark).instr);
      break_current--;
    }
    break;

  case 49:
#line 298 "yaccrule.y"
    {
      (yyval.exp).addr  = (yyvsp[(1) - (1)].exp).addr;
      (yyval.exp).type  = (yyvsp[(1) - (1)].exp).type;
      (yyval.exp).tlist = (yyvsp[(1) - (1)].exp).tlist;
      (yyval.exp).flist = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 50:
#line 304 "yaccrule.y"
    {
      genCode((yyvsp[(1) - (3)].exp).addr,(yyvsp[(3) - (3)].exp).addr);
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
  }
    break;

  case 51:
#line 309 "yaccrule.y"
    {
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      (yyval.exp).addr  = newTemp();
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"+",(yyvsp[(3) - (3)].exp).addr);
      genCode((yyvsp[(1) - (3)].exp).addr,(yyval.exp).addr );
      (yyval.exp).addr  = (yyvsp[(1) - (3)].exp).addr;
  }
    break;

  case 52:
#line 317 "yaccrule.y"
    {
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      (yyval.exp).addr  = newTemp();
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"-",(yyvsp[(3) - (3)].exp).addr);
      genCode((yyvsp[(1) - (3)].exp).addr,(yyval.exp).addr );
      (yyval.exp).addr  = (yyvsp[(1) - (3)].exp).addr;
  }
    break;

  case 53:
#line 325 "yaccrule.y"
    {
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      (yyval.exp).addr  = newTemp();
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"*",(yyvsp[(3) - (3)].exp).addr);
      genCode((yyvsp[(1) - (3)].exp).addr,(yyval.exp).addr );
      (yyval.exp).addr  = (yyvsp[(1) - (3)].exp).addr;
  }
    break;

  case 54:
#line 333 "yaccrule.y"
    {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"/",(yyvsp[(3) - (3)].exp).addr);
        genCode((yyvsp[(1) - (3)].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[(1) - (3)].exp).addr;
  }
    break;

  case 55:
#line 344 "yaccrule.y"
    {
      (yyval.exp).addr  = (yyvsp[(1) - (1)].exp).addr;
      (yyval.exp).type  = (yyvsp[(1) - (1)].exp).type;
      (yyval.exp).flist = (yyvsp[(1) - (1)].exp).flist;
      (yyval.exp).tlist = (yyvsp[(1) - (1)].exp).tlist;
  }
    break;

  case 56:
#line 350 "yaccrule.y"
    {
	    if((yyvsp[(1) - (1)].exp).tlist  ==  NULL  && (yyvsp[(1) - (1)].exp).flist   ==  NULL ){
	        genCode("if",(yyvsp[(1) - (1)].exp).addr,"!=","0","goto",EMPTY);
	            genCode("goto",EMPTY);
	            (yyvsp[(1) - (1)].exp).tlist = makeList(nextInstr-2);
	            (yyvsp[(1) - (1)].exp).flist = makeList(nextInstr-1);
	    }
    }
    break;

  case 57:
#line 357 "yaccrule.y"
    {
      if((yyvsp[(5) - (5)].exp).tlist  ==  NULL  && (yyvsp[(5) - (5)].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[(5) - (5)].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[(5) - (5)].exp).tlist = makeList(nextInstr-2);
            (yyvsp[(5) - (5)].exp).flist = makeList(nextInstr-1);
      }
      backpatch((yyvsp[(1) - (5)].exp).flist,(yyvsp[(4) - (5)].mark).instr);
      (yyval.exp).flist = (yyvsp[(5) - (5)].exp).flist;
      (yyval.exp).tlist = mergeList((yyvsp[(1) - (5)].exp).tlist,(yyvsp[(5) - (5)].exp).tlist);
  }
    break;

  case 58:
#line 371 "yaccrule.y"
    {
    (yyval.exp).addr  = (yyvsp[(1) - (1)].exp).addr;
    (yyval.exp).type  = (yyvsp[(1) - (1)].exp).type;
    (yyval.exp).flist = (yyvsp[(1) - (1)].exp).flist;
    (yyval.exp).tlist = (yyvsp[(1) - (1)].exp).tlist;
  }
    break;

  case 59:
#line 377 "yaccrule.y"
    {
        if((yyvsp[(1) - (1)].exp).tlist  ==  NULL  && (yyvsp[(1) - (1)].exp).flist   ==  NULL ){
          genCode("if",(yyvsp[(1) - (1)].exp).addr,"!=","0","goto",EMPTY);
          genCode("goto",EMPTY);
          (yyvsp[(1) - (1)].exp).tlist = makeList(nextInstr-2);
          (yyvsp[(1) - (1)].exp).flist = makeList(nextInstr-1);
    	  }
    }
    break;

  case 60:
#line 384 "yaccrule.y"
    {
      if((yyvsp[(5) - (5)].exp).tlist  ==  NULL  && (yyvsp[(5) - (5)].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[(5) - (5)].exp).addr,"!=","0","goto",EMPTY);
        genCode("goto",EMPTY);
        (yyvsp[(5) - (5)].exp).tlist = makeList(nextInstr-2);
        (yyvsp[(5) - (5)].exp).flist = makeList(nextInstr-1);
      }
      backpatch((yyvsp[(1) - (5)].exp).tlist,(yyvsp[(4) - (5)].mark).instr);
      (yyval.exp).tlist = (yyvsp[(5) - (5)].exp).tlist;
      (yyval.exp).flist = mergeList((yyvsp[(1) - (5)].exp).flist,(yyvsp[(5) - (5)].exp).flist);
      }
    break;

  case 61:
#line 398 "yaccrule.y"
    {
      (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
      (yyval.exp).type   = (yyvsp[(1) - (1)].exp).type;
      (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
      (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 62:
#line 404 "yaccrule.y"
    {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[(1) - (3)].exp).addr," == ",(yyvsp[(3) - (3)].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
    break;

  case 63:
#line 410 "yaccrule.y"
    {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[(1) - (3)].exp).addr,"!=",(yyvsp[(3) - (3)].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
    break;

  case 64:
#line 419 "yaccrule.y"
    {
    (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
    (yyval.exp).type   = (yyvsp[(1) - (1)].exp).type;
    (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
    (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 65:
#line 425 "yaccrule.y"
    {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[(1) - (3)].exp).addr,(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
    break;

  case 66:
#line 434 "yaccrule.y"
    {(yyval.str)=(char*)">";}
    break;

  case 67:
#line 435 "yaccrule.y"
    {(yyval.str) =(char*)">=";}
    break;

  case 68:
#line 436 "yaccrule.y"
    {(yyval.str) =(char*)"<";}
    break;

  case 69:
#line 437 "yaccrule.y"
    {(yyval.str) =(char*)"<=";}
    break;

  case 70:
#line 441 "yaccrule.y"
    {
      (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
      (yyval.exp).type   = (yyvsp[(1) - (1)].exp).type;
      (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
      (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 71:
#line 447 "yaccrule.y"
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[(1) - (3)].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"+",(yyvsp[(3) - (3)].exp).addr);
  }
    break;

  case 72:
#line 454 "yaccrule.y"
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[(1) - (3)].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"-",(yyvsp[(3) - (3)].exp).addr);
  }
    break;

  case 73:
#line 464 "yaccrule.y"
    {
      (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
      (yyval.exp).type   = (yyvsp[(1) - (1)].exp).type;
      (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
      (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 74:
#line 470 "yaccrule.y"
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[(1) - (3)].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"*",(yyvsp[(3) - (3)].exp).addr);
  }
    break;

  case 75:
#line 477 "yaccrule.y"
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[(1) - (3)].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"/",(yyvsp[(3) - (3)].exp).addr);
  }
    break;

  case 76:
#line 487 "yaccrule.y"
    {
    (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
    (yyval.exp).type   = (yyvsp[(1) - (1)].exp).type;
    (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
    (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
  }
    break;

  case 77:
#line 493 "yaccrule.y"
    {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).type   = (yyvsp[(1) - (3)].exp).type;
    (yyval.exp).tlist  = NULL;
    (yyval.exp).flist  = NULL;
    genCode((yyval.exp).addr  ,(yyvsp[(1) - (3)].exp).addr,"**",(yyvsp[(3) - (3)].exp).addr);
  }
    break;

  case 78:
#line 503 "yaccrule.y"
    {
    (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
    (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
    (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 79:
#line 508 "yaccrule.y"
    {
     (yyval.exp).addr   = newTemp();
     (yyval.exp).tlist  = (yyvsp[(2) - (2)].exp).tlist;
     (yyval.exp).flist  = (yyvsp[(2) - (2)].exp).flist;
     genCode((yyval.exp).addr ,(yyvsp[(2) - (2)].exp).addr,"+","1");
     genCode((yyvsp[(2) - (2)].exp).addr,(yyval.exp).addr );
  }
    break;

  case 80:
#line 515 "yaccrule.y"
    {
     (yyval.exp).addr   = newTemp();
     (yyval.exp).tlist  = (yyvsp[(2) - (2)].exp).tlist;
     (yyval.exp).flist  = (yyvsp[(2) - (2)].exp).flist;
     genCode((yyval.exp).addr ,(yyvsp[(2) - (2)].exp).addr,"-","1");
     genCode((yyvsp[(2) - (2)].exp).addr,(yyval.exp).addr );
  }
    break;

  case 81:
#line 522 "yaccrule.y"
    {
      (yyval.exp).addr   = (yyvsp[(2) - (2)].exp).addr;
      (yyval.exp).tlist  = (yyvsp[(2) - (2)].exp).tlist;
      (yyval.exp).flist  = (yyvsp[(2) - (2)].exp).flist;
    }
    break;

  case 82:
#line 527 "yaccrule.y"
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[(2) - (2)].exp).tlist;
      (yyval.exp).flist  = (yyvsp[(2) - (2)].exp).flist;
      genCode((yyval.exp).addr ,"-1","*",(yyvsp[(2) - (2)].exp).addr);
  }
    break;

  case 83:
#line 533 "yaccrule.y"
    {
      if((yyvsp[(2) - (2)].exp).tlist  ==  NULL  && (yyvsp[(2) - (2)].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[(2) - (2)].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[(2) - (2)].exp).tlist = makeList(nextInstr-2);
            (yyvsp[(2) - (2)].exp).flist = makeList(nextInstr-1);
    }
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[(2) - (2)].exp).flist;
      (yyval.exp).flist  = (yyvsp[(2) - (2)].exp).tlist;
  }
    break;

  case 84:
#line 547 "yaccrule.y"
    {
    (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
    (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
    (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 85:
#line 552 "yaccrule.y"
    {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).tlist  = (yyvsp[(1) - (2)].exp).tlist;
    (yyval.exp).flist  = (yyvsp[(1) - (2)].exp).flist;
    genCode((yyval.exp).addr ,(yyvsp[(1) - (2)].exp).addr);
    genCode((yyvsp[(1) - (2)].exp).addr,(yyval.exp).addr ,"+","1");
  }
    break;

  case 86:
#line 559 "yaccrule.y"
    {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).tlist  = (yyvsp[(1) - (2)].exp).tlist;
    (yyval.exp).flist  = (yyvsp[(1) - (2)].exp).flist;
    genCode((yyval.exp).addr ,(yyvsp[(1) - (2)].exp).addr);
    genCode((yyvsp[(1) - (2)].exp).addr,(yyval.exp).addr ,"-","1");
  }
    break;

  case 87:
#line 569 "yaccrule.y"
    {
  (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
  (yyval.exp).tlist  = NULL;
  (yyval.exp).flist  = NULL;
  if(!IsPresent((yyvsp[(1) - (1)].exp).addr)){
    char *errmsg =  new char[256];
    strcpy(errmsg,"'");
    strcat(errmsg,(yyval.exp).addr);
    strcat(errmsg,"' was not declared");
    AddError(errmsg,lineno,ERROR);
    delete[] errmsg;
  }
 }
    break;

  case 88:
#line 582 "yaccrule.y"
    {
    (yyval.exp).addr   = (yyvsp[(1) - (1)].exp).addr;
    (yyval.exp).tlist  = (yyvsp[(1) - (1)].exp).tlist;
    (yyval.exp).flist  = (yyvsp[(1) - (1)].exp).flist;
  }
    break;

  case 89:
#line 587 "yaccrule.y"
    {
    (yyval.exp).addr  = (yyvsp[(2) - (3)].exp).addr;
    (yyval.exp).flist  = (yyvsp[(2) - (3)].exp).flist;
    (yyval.exp).tlist  = (yyvsp[(2) - (3)].exp).tlist;
  }
    break;

  case 90:
#line 595 "yaccrule.y"
    {
    (yyval.exp).type  = INTNUM;
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
  }
    break;

  case 91:
#line 600 "yaccrule.y"
    {
    (yyval.exp).type  = DOUBLENUM;
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
  }
    break;

  case 92:
#line 605 "yaccrule.y"
    {
    (yyval.exp).addr = new char[2];
    (yyval.exp).addr = (char*)"1";
    (yyval.exp).type = BOOL;
    if(!assign){
    	 (yyval.exp).tlist = makeList(nextInstr);
	     (yyval.exp).flist = NULL;
	     genCode("goto",EMPTY);
    }
    else{
		assign = false;
	  }
  }
    break;

  case 93:
#line 618 "yaccrule.y"
    {
    (yyval.exp).addr = new char[2];
    (yyval.exp).addr = (char*)"0";
    (yyval.exp).type   = BOOL;
    if(!assign){
	    (yyval.exp).flist = makeList(nextInstr);
	    (yyval.exp).tlist = NULL;
	    genCode("goto",EMPTY);
	}
	else {
		assign = false;
	}
  }
    break;

  case 94:
#line 633 "yaccrule.y"
    {(yyval.mark).instr = nextInstr;}
    break;


/* Line 1267 of yacc.c.  */
#line 2395 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 636 "yaccrule.y"

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

