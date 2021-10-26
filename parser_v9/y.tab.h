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
     FLOAT_NUM = 270,
     ID = 271,
     LE = 272,
     GE = 273,
     EQ = 274,
     NE = 275,
     GT = 276,
     LT = 277,
     AND = 278,
     OR = 279,
     STR = 280,
     ADD = 281,
     MULTIPLY = 282,
     DIVIDE = 283,
     SUBTRACT = 284,
     UNARY = 285,
     INCLUDE = 286,
     RETURN = 287
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
#define FLOAT_NUM 270
#define ID 271
#define LE 272
#define GE 273
#define EQ 274
#define NE 275
#define GT 276
#define LT 277
#define AND 278
#define OR 279
#define STR 280
#define ADD 281
#define MULTIPLY 282
#define DIVIDE 283
#define SUBTRACT 284
#define UNARY 285
#define INCLUDE 286
#define RETURN 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "parser.y"
{ struct var_name { 
			char name[100]; 
			struct node* nd;
		} nam;

		struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
		} nam2; 

		struct var_name3 {
			char name[100];
			struct node* nd;
			char *if_body;
			char *else_body;
		} nam3;
	}
/* Line 1529 of yacc.c.  */
#line 132 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

