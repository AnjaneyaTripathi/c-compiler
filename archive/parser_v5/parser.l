%{
    #include "y.tab.h"
    int countn=0;
%}
%option yylineno

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"printf"                    { strcpy(yylval.nam.name,(yytext)); return PRINTFF; }
"scanf"                     { strcpy(yylval.nam.name,(yytext)); return SCANFF; }
"int"                       { strcpy(yylval.nam.name,(yytext)); return INT; }
"float"                     { strcpy(yylval.nam.name,(yytext)); return FLOAT; }
"char"                      { strcpy(yylval.nam.name,(yytext)); return CHAR; }
"void"                      { strcpy(yylval.nam.name,(yytext)); return VOID; }
"return"                    { strcpy(yylval.nam.name,(yytext)); return RETURN; }
"for"	                    { strcpy(yylval.nam.name,(yytext)); return FOR; }
^"#include"[ ]*<.+\.h>      { strcpy(yylval.nam.name,(yytext)); return INCLUDE; }
"true"                      { strcpy(yylval.nam.name,(yytext)); return TRUE; }
"false"                     { strcpy(yylval.nam.name,(yytext)); return FALSE; }
{digit}+                    { strcpy(yylval.nam.name,(yytext)); return NUMBER; }
{alpha}({alpha}|{digit})*   { strcpy(yylval.nam.name,(yytext)); return ID; }
{unary}                     { strcpy(yylval.nam.name,(yytext)); return UNARY; }
"<="                        { strcpy(yylval.nam.name,(yytext)); return LE; }
">="                        { strcpy(yylval.nam.name,(yytext)); return GE; }
"=="                        { strcpy(yylval.nam.name,(yytext)); return EQ; }
"!="                        { strcpy(yylval.nam.name,(yytext)); return NE; }
">"	                        { strcpy(yylval.nam.name,(yytext)); return GT; }
"<"	                        { strcpy(yylval.nam.name,(yytext)); return LT; }
"&&"	                    { strcpy(yylval.nam.name,(yytext)); return AND; }
"||"	                    { strcpy(yylval.nam.name,(yytext)); return OR; }
"+"                         { strcpy(yylval.nam.name,(yytext)); return ADD; }
"-"                         { strcpy(yylval.nam.name,(yytext)); return SUBTRACT; }
"/"                         { strcpy(yylval.nam.name,(yytext)); return DIVIDE; }
"*"                         { strcpy(yylval.nam.name,(yytext)); return MULTIPLY; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { return *yytext; }
["].*["]                    { strcpy(yylval.nam.name,(yytext)); return STR; }

%%

int yywrap() {
    return 1;
}