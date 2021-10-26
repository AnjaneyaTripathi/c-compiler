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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void insert_type();
    int search(char *);
	void insert_type();
	void printtree(struct node*);
	void printTreeUtil(struct node*, int);
	void printInorder(struct node *);
    void check_declaration(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	struct node* mknode(struct node *left, struct node *right, char *token);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
	} symbolTable[40];

    int count=0;
    int q;
	char type[10];
    extern int countn;
	struct node *head;
	int sem_errors=0;
	int temp_var=0;
	int label=0;
	int is_for=0;

	struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};



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
#line 47 "parser.y"
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
			char if_body[5];
			char else_body[5];
		} nam3;
	}
/* Line 193 of yacc.c.  */
#line 225 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      33,    34,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    15,    16,    19,    22,    24,    26,
      28,    30,    31,    44,    45,    46,    47,    59,    62,    65,
      66,    73,    74,    84,    85,    91,    92,    96,    98,   100,
     101,   102,   107,   108,   113,   114,   119,   120,   124,   127,
     130,   131,   135,   137,   139,   141,   143,   145,   147,   149,
     151,   153,   155,   157,   159,   161,   163,   164,   169
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    45,    33,    34,    35,    47,    67,
      36,    -1,    43,    43,    -1,    -1,    31,    44,    -1,    46,
      16,    -1,     6,    -1,     7,    -1,     8,    -1,     3,    -1,
      -1,     9,    48,    33,    57,    37,    56,    37,    57,    34,
      35,    47,    36,    -1,    -1,    -1,    -1,    10,    49,    33,
      56,    34,    50,    35,    47,    36,    51,    54,    -1,    57,
      37,    -1,    47,    47,    -1,    -1,     4,    52,    33,    25,
      34,    37,    -1,    -1,     5,    53,    33,    25,    38,    39,
      16,    34,    37,    -1,    -1,    11,    55,    35,    47,    36,
      -1,    -1,    66,    65,    66,    -1,    12,    -1,    13,    -1,
      -1,    -1,    46,    16,    58,    62,    -1,    -1,    16,    59,
      40,    63,    -1,    -1,    16,    60,    65,    63,    -1,    -1,
      16,    61,    30,    -1,    30,    16,    -1,    40,    66,    -1,
      -1,    63,    64,    63,    -1,    66,    -1,    26,    -1,    29,
      -1,    27,    -1,    28,    -1,    22,    -1,    21,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    14,    -1,    15,
      -1,    16,    -1,    -1,    32,    68,    66,    37,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    78,    79,    79,    82,    85,    86,    87,
      88,    91,    91,    98,    98,    98,    98,   103,   104,   105,
     105,   106,   106,   109,   109,   110,   113,   126,   127,   128,
     131,   131,   147,   147,   165,   165,   166,   166,   179,   194,
     195,   198,   218,   221,   222,   223,   224,   227,   228,   229,
     230,   231,   232,   235,   236,   237,   240,   240,   241
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "PRINTFF", "SCANFF", "INT",
  "FLOAT", "CHAR", "FOR", "IF", "ELSE", "TRUE", "FALSE", "NUMBER",
  "FLOAT_NUM", "ID", "LE", "GE", "EQ", "NE", "GT", "LT", "AND", "OR",
  "STR", "ADD", "MULTIPLY", "DIVIDE", "SUBTRACT", "UNARY", "INCLUDE",
  "RETURN", "'('", "')'", "'{'", "'}'", "';'", "','", "'&'", "'='",
  "$accept", "program", "headers", "@1", "main", "datatype", "body", "@2",
  "@3", "@4", "@5", "@6", "@7", "else", "@8", "condition", "statement",
  "@9", "@10", "@11", "@12", "init", "expression", "arithmetic", "relop",
  "value", "return", "@13", 0
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
     285,   286,   287,    40,    41,   123,   125,    59,    44,    38,
      61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    43,    45,    46,    46,    46,
      46,    48,    47,    49,    50,    51,    47,    47,    47,    52,
      47,    53,    47,    55,    54,    54,    56,    56,    56,    56,
      58,    57,    59,    57,    60,    57,    61,    57,    57,    62,
      62,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    68,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     2,     0,     2,     2,     1,     1,     1,
       1,     0,    12,     0,     0,     0,    11,     2,     2,     0,
       6,     0,     9,     0,     5,     0,     3,     1,     1,     0,
       0,     4,     0,     4,     0,     4,     0,     3,     2,     2,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     5,     1,    10,     7,     8,     9,
       3,     0,     0,     0,     6,     0,     0,    19,    21,    11,
      13,    34,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    30,    56,    18,     0,    17,     0,
       0,     0,    29,     0,    49,    50,    51,    52,    48,    47,
       0,    37,    40,     0,     2,     0,     0,     0,    27,    28,
      53,    54,    55,     0,     0,    33,    42,    35,     0,    31,
       0,     0,     0,    29,    14,     0,    43,    45,    46,    44,
       0,    39,    57,    20,     0,     0,     0,    26,    41,     0,
       0,     0,     0,     0,     0,    22,     0,    15,     0,    25,
       0,    23,    16,    12,     0,     0,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,     4,    11,    23,    36,    28,    29,    86,
      99,    26,    27,   102,   104,    63,    25,    52,    30,    31,
      32,    69,    65,    80,    50,    66,    37,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int8 yypact[] =
{
      -5,   -41,    28,    49,   -41,   -41,   -41,   -41,   -41,   -41,
      -5,    -3,    16,     0,   -41,    12,   102,   -41,   -41,   -41,
     -41,   -13,    32,    37,    87,    17,    25,    34,    35,    38,
      30,   103,    42,   -41,   -41,   -41,   102,    29,   -41,    54,
      56,    70,    -2,    46,   -41,   -41,   -41,   -41,   -41,   -41,
      46,   -41,    43,    46,   -41,    40,    47,    50,   -41,   -41,
     -41,   -41,   -41,    64,   103,   100,   -41,   100,    46,   -41,
      51,    62,    45,    -2,   -41,    46,   -41,   -41,   -41,   -41,
      46,   -41,   -41,   -41,    85,    65,    69,   -41,   100,    79,
      70,   102,    77,    81,    -1,   -41,    95,   -41,   102,   105,
      15,   -41,   -41,   -41,    96,   102,    33,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   133,   -41,   -41,   131,   -16,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,    63,   -40,   -41,   -41,   -41,
     -41,   -41,   -34,   -41,    71,    -9,   -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int8 yytable[] =
{
      24,    57,     6,    17,    18,     7,     8,     9,    19,    20,
      58,    59,    60,    61,    62,    21,    67,   -36,     6,    17,
      18,     7,     8,     9,    19,    20,     1,   -32,     5,    22,
      13,    21,    14,    64,    15,    97,     6,    17,    18,     7,
       8,     9,    19,    20,    70,    22,    88,    16,    33,    21,
      93,   103,     6,    34,    38,     7,     8,     9,    39,    81,
      60,    61,    62,    22,    64,    54,    87,    40,    41,   107,
      43,    42,    51,     6,    71,    94,     7,     8,     9,    55,
       1,    56,   100,    68,    84,    72,    21,    73,    82,   106,
       6,    17,    18,     7,     8,     9,    19,    20,    74,    83,
      22,    89,    90,    21,    91,     6,    17,    18,     7,     8,
       9,    19,    20,    92,    95,    96,   101,    22,    21,    35,
      44,    45,    46,    47,    48,    49,    76,    77,    78,    79,
      98,   105,    22,     3,    12,    75,    85
};

static const yytype_uint8 yycheck[] =
{
      16,    41,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    15,    16,    16,    50,    30,     3,     4,
       5,     6,     7,     8,     9,    10,    31,    40,     0,    30,
      33,    16,    16,    42,    34,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    53,    30,    80,    35,    16,    16,
      90,    36,     3,    16,    37,     6,     7,     8,    33,    68,
      14,    15,    16,    30,    73,    36,    75,    33,    33,    36,
      40,    33,    30,     3,    34,    91,     6,     7,     8,    25,
      31,    25,    98,    40,    39,    38,    16,    37,    37,   105,
       3,     4,     5,     6,     7,     8,     9,    10,    34,    37,
      30,    16,    37,    16,    35,     3,     4,     5,     6,     7,
       8,     9,    10,    34,    37,    34,    11,    30,    16,    32,
      17,    18,    19,    20,    21,    22,    26,    27,    28,    29,
      35,    35,    30,     0,     3,    64,    73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    42,    43,    44,     0,     3,     6,     7,     8,
      43,    45,    46,    33,    16,    34,    35,     4,     5,     9,
      10,    16,    30,    46,    47,    57,    52,    53,    48,    49,
      59,    60,    61,    16,    16,    32,    47,    67,    37,    33,
      33,    33,    33,    40,    17,    18,    19,    20,    21,    22,
      65,    30,    58,    68,    36,    25,    25,    57,    12,    13,
      14,    15,    16,    56,    66,    63,    66,    63,    40,    62,
      66,    34,    38,    37,    34,    65,    26,    27,    28,    29,
      64,    66,    37,    37,    39,    56,    50,    66,    63,    16,
      37,    35,    34,    57,    47,    37,    34,    36,    35,    51,
      47,    11,    54,    36,    55,    35,    47,    36
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
#line 73 "parser.y"
    { (yyvsp[(2) - (8)].nam).nd = mknode((yyvsp[(6) - (8)].nam).nd, (yyvsp[(7) - (8)].nam).nd, "main"); (yyval.nam).nd = mknode((yyvsp[(1) - (8)].nam).nd, (yyvsp[(2) - (8)].nam).nd, "program"); 
	head = (yyval.nam).nd;
}
    break;

  case 3:
#line 78 "parser.y"
    { (yyval.nam).nd = mknode((yyvsp[(1) - (2)].nam).nd, (yyvsp[(2) - (2)].nam).nd, "headers"); }
    break;

  case 4:
#line 79 "parser.y"
    { add('H'); }
    break;

  case 5:
#line 79 "parser.y"
    { (yyval.nam).nd = mknode(NULL, NULL, (yyvsp[(1) - (2)].nam).name); }
    break;

  case 6:
#line 82 "parser.y"
    { add('K'); }
    break;

  case 7:
#line 85 "parser.y"
    { insert_type(); }
    break;

  case 8:
#line 86 "parser.y"
    { insert_type(); }
    break;

  case 9:
#line 87 "parser.y"
    { insert_type(); }
    break;

  case 10:
#line 88 "parser.y"
    { insert_type(); }
    break;

  case 11:
#line 91 "parser.y"
    { add('K'); is_for = 1; }
    break;

  case 12:
#line 91 "parser.y"
    { 
	struct node *temp = mknode((yyvsp[(6) - (12)].nam3).nd, (yyvsp[(8) - (12)].nam).nd, "CONDITION"); 
	struct node *temp2 = mknode((yyvsp[(4) - (12)].nam).nd, temp, "CONDITION"); 
	(yyval.nam).nd = mknode(temp2, (yyvsp[(11) - (12)].nam).nd, (yyvsp[(1) - (12)].nam).name); 
	printf("JUMP to %s\n", (yyvsp[(6) - (12)].nam3).if_body);
	printf("\nLABEL %s\n", (yyvsp[(6) - (12)].nam3).else_body);
}
    break;

  case 13:
#line 98 "parser.y"
    { add('K'); is_for = 0; }
    break;

  case 14:
#line 98 "parser.y"
    { printf("\nLABEL %s:\n", (yyvsp[(4) - (5)].nam3).if_body); }
    break;

  case 15:
#line 98 "parser.y"
    { printf("\nLABEL %s:\n", (yyvsp[(4) - (9)].nam3).else_body); }
    break;

  case 16:
#line 98 "parser.y"
    { 
	struct node *iff = mknode((yyvsp[(4) - (11)].nam3).nd, (yyvsp[(8) - (11)].nam).nd, (yyvsp[(1) - (11)].nam).name); 
	(yyval.nam).nd = mknode(iff, (yyvsp[(11) - (11)].nam).nd, "if-else"); 
	printf("GOTO next\n");
}
    break;

  case 17:
#line 103 "parser.y"
    { (yyval.nam).nd = (yyvsp[(1) - (2)].nam).nd; }
    break;

  case 18:
#line 104 "parser.y"
    { (yyval.nam).nd = mknode((yyvsp[(1) - (2)].nam).nd, (yyvsp[(2) - (2)].nam).nd, "statements"); }
    break;

  case 19:
#line 105 "parser.y"
    { add('K'); }
    break;

  case 20:
#line 105 "parser.y"
    { (yyval.nam).nd = mknode(NULL, NULL, "printf"); }
    break;

  case 21:
#line 106 "parser.y"
    { add('K'); }
    break;

  case 22:
#line 106 "parser.y"
    { (yyval.nam).nd = mknode(NULL, NULL, "scanf"); }
    break;

  case 23:
#line 109 "parser.y"
    { add('K'); }
    break;

  case 24:
#line 109 "parser.y"
    { (yyval.nam).nd = mknode(NULL, (yyvsp[(4) - (5)].nam).nd, (yyvsp[(1) - (5)].nam).name); }
    break;

  case 25:
#line 110 "parser.y"
    { (yyval.nam).nd = NULL; }
    break;

  case 26:
#line 113 "parser.y"
    { 
	(yyval.nam3).nd = mknode((yyvsp[(1) - (3)].nam2).nd, (yyvsp[(3) - (3)].nam2).nd, (yyvsp[(2) - (3)].nam).name); 
	if(is_for) {
		sprintf((yyval.nam3).if_body, "L%d", label++);
		printf("\nLABEL %s:\n", (yyval.nam3).if_body);
		printf("\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[(1) - (3)].nam2).name, (yyvsp[(2) - (3)].nam).name, (yyvsp[(3) - (3)].nam2).name, label);
		sprintf((yyval.nam3).else_body, "L%d", label++);
	} else {
		printf("\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[(1) - (3)].nam2).name, (yyvsp[(2) - (3)].nam).name, (yyvsp[(3) - (3)].nam2).name, label, label+1);
		sprintf((yyval.nam3).if_body, "L%d", label++);
		sprintf((yyval.nam3).else_body, "L%d", label++);
	}
}
    break;

  case 27:
#line 126 "parser.y"
    { add('K'); (yyval.nam3).nd = NULL; }
    break;

  case 28:
#line 127 "parser.y"
    { add('K'); (yyval.nam3).nd = NULL; }
    break;

  case 29:
#line 128 "parser.y"
    { (yyval.nam3).nd = NULL; }
    break;

  case 30:
#line 131 "parser.y"
    { add('V'); }
    break;

  case 31:
#line 131 "parser.y"
    { 
	(yyvsp[(2) - (4)].nam).nd = mknode(NULL, NULL, (yyvsp[(2) - (4)].nam).name); 
	int t = check_types((yyvsp[(1) - (4)].nam).name, (yyvsp[(4) - (4)].nam2).type); 
	if(t>0){ 
		if(t == 1) {
			struct node *temp = mknode(NULL, (yyvsp[(4) - (4)].nam2).nd, "inttofloat"); 
			(yyval.nam).nd = mknode((yyvsp[(2) - (4)].nam).nd, temp, "declaration"); 
		} else { 
			struct node *temp = mknode(NULL, (yyvsp[(4) - (4)].nam2).nd, "floattoint"); 
			(yyval.nam).nd = mknode((yyvsp[(2) - (4)].nam).nd, temp, "declaration"); 
		} 
	} else { 
		(yyval.nam).nd = mknode((yyvsp[(2) - (4)].nam).nd, (yyvsp[(4) - (4)].nam2).nd, "declaration"); 
	} 
	printf("=\t %s\t %s\t\n", (yyvsp[(2) - (4)].nam).name, (yyvsp[(4) - (4)].nam2).name);
}
    break;

  case 32:
#line 147 "parser.y"
    { check_declaration((yyvsp[(1) - (1)].nam).name); }
    break;

  case 33:
#line 147 "parser.y"
    {
	(yyvsp[(1) - (4)].nam).nd = mknode(NULL, NULL, (yyvsp[(1) - (4)].nam).name); 
	char *id_type = get_type((yyvsp[(1) - (4)].nam).name); 
	if(id_type[0] != (yyvsp[(4) - (4)].nam2).type[0]) {
		if(id_type[0] == 'i') {
			struct node *temp = mknode(NULL, (yyvsp[(4) - (4)].nam2).nd, "floattoint");
			(yyval.nam).nd = mknode((yyvsp[(1) - (4)].nam).nd, temp, "="); 
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[(4) - (4)].nam2).nd, "inttofloat");
			(yyval.nam).nd = mknode((yyvsp[(1) - (4)].nam).nd, temp, "="); 
		}
	}
	else {
		(yyval.nam).nd = mknode((yyvsp[(1) - (4)].nam).nd, (yyvsp[(4) - (4)].nam2).nd, "="); 
	}
	printf("=\t %s\t %s\t\n", (yyvsp[(1) - (4)].nam).name, (yyvsp[(4) - (4)].nam2).name);
}
    break;

  case 34:
#line 165 "parser.y"
    { check_declaration((yyvsp[(1) - (1)].nam).name); }
    break;

  case 35:
#line 165 "parser.y"
    { (yyvsp[(1) - (4)].nam).nd = mknode(NULL, NULL, (yyvsp[(1) - (4)].nam).name); (yyval.nam).nd = mknode((yyvsp[(1) - (4)].nam).nd, (yyvsp[(4) - (4)].nam2).nd, (yyvsp[(3) - (4)].nam).name); }
    break;

  case 36:
#line 166 "parser.y"
    { check_declaration((yyvsp[(1) - (1)].nam).name); }
    break;

  case 37:
#line 166 "parser.y"
    { 
	(yyvsp[(1) - (3)].nam).nd = mknode(NULL, NULL, (yyvsp[(1) - (3)].nam).name); 
	(yyvsp[(3) - (3)].nam).nd = mknode(NULL, NULL, (yyvsp[(3) - (3)].nam).name); 
	(yyval.nam).nd = mknode((yyvsp[(1) - (3)].nam).nd, (yyvsp[(3) - (3)].nam).nd, "ITERATOR"); 
	printf("%s\n", (yyvsp[(3) - (3)].nam).name); 
	if(!strcmp((yyvsp[(3) - (3)].nam).name, "++")) {
		printf("+\t %s\t 1\t t%d\n", (yyvsp[(1) - (3)].nam).name, temp_var);
	}
	else {
		printf("-\t %s\t 1\t t%d\n", (yyvsp[(1) - (3)].nam).name, temp_var);
	}
	printf("=\t %s\t t%d\n", (yyvsp[(1) - (3)].nam).name, temp_var++);
}
    break;

  case 38:
#line 179 "parser.y"
    { 
	check_declaration((yyvsp[(2) - (2)].nam).name); 
	(yyvsp[(1) - (2)].nam).nd = mknode(NULL, NULL, (yyvsp[(1) - (2)].nam).name); 
	(yyvsp[(2) - (2)].nam).nd = mknode(NULL, NULL, (yyvsp[(2) - (2)].nam).name); 
	(yyval.nam).nd = mknode((yyvsp[(1) - (2)].nam).nd, (yyvsp[(2) - (2)].nam).nd, "ITERATOR"); 
	if(!strcmp((yyvsp[(1) - (2)].nam).name, "++")) {
		printf("+\t %s\t 1\t t%d\n", (yyvsp[(2) - (2)].nam).name, temp_var);
	}
	else {
		printf("-\t %s\t 1\t t%d\n", (yyvsp[(2) - (2)].nam).name, temp_var);
	}
	printf("=\t %s\t t%d\n", (yyvsp[(2) - (2)].nam).name, temp_var++);
}
    break;

  case 39:
#line 194 "parser.y"
    { (yyval.nam2).nd = (yyvsp[(2) - (2)].nam2).nd; sprintf((yyval.nam2).type, (yyvsp[(2) - (2)].nam2).type); strcpy((yyval.nam2).name, (yyvsp[(2) - (2)].nam2).name); }
    break;

  case 40:
#line 195 "parser.y"
    { sprintf((yyval.nam2).type, "null"); (yyval.nam2).nd = mknode(NULL, NULL, "NULL"); strcpy((yyval.nam2).name, "NULL"); }
    break;

  case 41:
#line 198 "parser.y"
    { 
	if((yyvsp[(1) - (3)].nam2).type[0] == (yyvsp[(3) - (3)].nam2).type[0]) {
		sprintf((yyval.nam2).type, (yyvsp[(1) - (3)].nam2).type);
		(yyval.nam2).nd = mknode((yyvsp[(1) - (3)].nam2).nd, (yyvsp[(3) - (3)].nam2).nd, (yyvsp[(2) - (3)].nam).name); 
	}
	else {
		sprintf((yyval.nam2).type, "float");
		if((yyvsp[(1) - (3)].nam2).type[0] == 'i') {
			struct node *temp = mknode(NULL, (yyvsp[(1) - (3)].nam2).nd, "inttofloat");
			(yyval.nam2).nd = mknode(temp, (yyvsp[(3) - (3)].nam2).nd, (yyvsp[(2) - (3)].nam).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[(3) - (3)].nam2).nd, "inttofloat");
			(yyval.nam2).nd = mknode((yyvsp[(1) - (3)].nam2).nd, temp, (yyvsp[(2) - (3)].nam).name);
		}
	}
	sprintf((yyval.nam2).name, "t%d", temp_var);
	temp_var++;
	printf("%s\t %s\t %s\t %s\t\n", (yyvsp[(2) - (3)].nam).name, (yyvsp[(1) - (3)].nam2).name, (yyvsp[(3) - (3)].nam2).name, (yyval.nam2).name);
}
    break;

  case 42:
#line 218 "parser.y"
    { strcpy((yyval.nam2).name, (yyvsp[(1) - (1)].nam2).name); sprintf((yyval.nam2).type, (yyvsp[(1) - (1)].nam2).type); (yyval.nam2).nd = (yyvsp[(1) - (1)].nam2).nd; }
    break;

  case 53:
#line 235 "parser.y"
    { strcpy((yyval.nam2).name, (yyvsp[(1) - (1)].nam).name); sprintf((yyval.nam2).type, "int"); add('C'); (yyval.nam2).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nam).name); }
    break;

  case 54:
#line 236 "parser.y"
    { strcpy((yyval.nam2).name, (yyvsp[(1) - (1)].nam).name); sprintf((yyval.nam2).type, "float"); add('C'); (yyval.nam2).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nam).name); }
    break;

  case 55:
#line 237 "parser.y"
    { strcpy((yyval.nam2).name, (yyvsp[(1) - (1)].nam).name); char *id_type = get_type((yyvsp[(1) - (1)].nam).name); sprintf((yyval.nam2).type, id_type); check_declaration((yyvsp[(1) - (1)].nam).name); (yyval.nam2).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nam).name); }
    break;

  case 56:
#line 240 "parser.y"
    { add('K'); }
    break;

  case 57:
#line 240 "parser.y"
    { (yyvsp[(1) - (4)].nam).nd = mknode(NULL, NULL, "return"); (yyval.nam).nd = mknode((yyvsp[(1) - (4)].nam).nd, (yyvsp[(3) - (4)].nam2).nd, "RETURN"); }
    break;

  case 58:
#line 241 "parser.y"
    { (yyval.nam).nd = NULL; }
    break;


/* Line 1267 of yacc.c.  */
#line 1861 "y.tab.c"
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


#line 244 "parser.y"


int main() {
    yyparse();
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbolTable[i].id_name, symbolTable[i].data_type, symbolTable[i].type, symbolTable[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	printtree(head); 
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
	if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors!", sem_errors);
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbolTable[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

void check_declaration(char *c) {
    q = search(c);
    if(!q) {
        printf("ERROR: Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
        //exit(0);
    }
}

int check_types(char *type1, char *type2){
	if(type1[0] == type2[0])
		return 0;
	if(type1[0]=='f')
		return 1;
	return 2;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Insert proper equality check function
		// Handle case of use before declaration
		if(symbolTable[i].id_name[0] == var[0]) {
			return symbolTable[i].data_type;
		}
	}
}

void add(char c) {
    q=search(yytext);
	if(!q) {
		if(c == 'H') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("CONST");
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Constant");
			count++;
		}
    }
    else if(c == 'V' && q) {
        printf("ERROR: Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
		sem_errors++;
    }
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void printtree(struct node* tree) {
	//printTreeUtil(tree, 0);
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	printInorder(tree);
}

void printInorder(struct node *tree) {
	int i;
	if (tree->left) {
		printInorder(tree->left);
	}
	printf("%s, ", tree->token);
	if (tree->right) {
		printInorder(tree->right);
	}
}

void printTreeUtil(struct node *root, int space) {
    if(root == NULL)
        return;
    space += 7;
    printTreeUtil(root->right, space);
    for (int i = 7; i < space; i++)
        printf(" ");
	printf("%s\n", root->token);
    printTreeUtil(root->left, space);
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
