%{
    #include "y.tab.h"
    int countn=0;
%}
%option yylineno

/* Add negative numbers */
/* scanf does not work */
/* num	     [0-9]+  */
/* datatype "int"|"float"|"char"|"void" */
/* id	     [a-zA-Z]+ */
/* binary	 =|<|>|!=|<=|>=|==|&&|"||"|[+-/*] */
/* unary	 "++"|"--" */

alpha [a-zA-Z]
digit [0-9]

%%

"printf"                    { return PRINTFF; }
"scanf"                     { return SCANFF; }
"int"                       { return INT; }
"float"                     { return FLOAT; }
"char"                      { return CHAR; }
"void"                      { return VOID; }
"return"                    { return RETURN; }
"for"	                    { return FOR; }
"if"	                    { return IF; }
"else"	                    { return ELSE; }
^"#include"[ ]*<.+\.h>      { return INCLUDE; }
"true"                      { return TRUE; }
"false"                     { return FALSE; }
{digit}+                    { return NUMBER; }
{alpha}({alpha}|{digit})*   { return ID; }
"<="                        { return LE; }
">="                        { return GE;}
"=="                        { return EQ;}
"!="                        { return NE;}
">"	                        { return GT;}
"<"	                        { return LT;}
"&&"	                    { return AND;}
"||"	                    { return OR;}
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        {return *yytext; }
["].*["]                    { return STRLT; }

%%

int yywrap() {
    return 1;
}