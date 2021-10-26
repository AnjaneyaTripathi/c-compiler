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
     PRINTFF = 258,
     SCANFF = 259,
     INT = 260,
     FLOAT = 261,
     CHAR = 262,
     VOID = 263,
     RETURN = 264,
     FOR = 265,
     INCLUDE = 266,
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
     UNARY = 284
   };
#endif
/* Tokens.  */
#define PRINTFF 258
#define SCANFF 259
#define INT 260
#define FLOAT 261
#define CHAR 262
#define VOID 263
#define RETURN 264
#define FOR 265
#define INCLUDE 266
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

