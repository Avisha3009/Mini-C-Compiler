/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 181 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

