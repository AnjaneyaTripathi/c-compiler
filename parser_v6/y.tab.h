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
     VOID = 258,
     PRINTFF = 259,
     SCANFF = 260,
     INT = 261,
     FLOAT = 262,
     CHAR = 263,
     FOR = 264,
     IF = 265,
     ELSE = 266,
     TRUE = 267,
     FALSE = 268,
     NUMBER = 269,
     ID = 270,
     LE = 271,
     GE = 272,
     EQ = 273,
     NE = 274,
     GT = 275,
     LT = 276,
     AND = 277,
     OR = 278,
     STR = 279,
     ADD = 280,
     MULTIPLY = 281,
     DIVIDE = 282,
     SUBTRACT = 283,
     UNARY = 284,
     INCLUDE = 285,
     RETURN = 286
   };
#endif
/* Tokens.  */
#define VOID 258
#define PRINTFF 259
#define SCANFF 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define FOR 264
#define IF 265
#define ELSE 266
#define TRUE 267
#define FALSE 268
#define NUMBER 269
#define ID 270
#define LE 271
#define GE 272
#define EQ 273
#define NE 274
#define GT 275
#define LT 276
#define AND 277
#define OR 278
#define STR 279
#define ADD 280
#define MULTIPLY 281
#define DIVIDE 282
#define SUBTRACT 283
#define UNARY 284
#define INCLUDE 285
#define RETURN 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "parser.y"
{ struct var_name { 
		char name[100]; 
		struct node* nd;
		} nam; 
	}
/* Line 1529 of yacc.c.  */
#line 117 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

