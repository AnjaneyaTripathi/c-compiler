%{
    #include "y.tab.h"
%}


num	     [0-9]+
datatype "int"|"float"|"char"|"void"
id	     [a-zA-Z]+
binary	 =|<|>|!=|<=|>=|==|&&|"||"|[+-/*]
unary	 "++"|"--"

%%

"for"	                { return FOR; }
"if"	                { return IF; }
"else"	                { return ELSE; }
"true"                  { return TRUE; }
"false"                 { return FALSE; }
"printf"                { return PRINTFF; }
"scanf"                 { return SCANFF; }
^"#include"[ ]*<.+\.h>  { return INCLUDE; }
"return"                { return RETURN; }
{binary}	            { return BINARY; }
{unary}	                { return UNARY; }
{num}	                { return NUMBER; }
{datatype}              { return DATATYPE; }
{id}	                { return ID; }
[ \t]*                  { ; }
[\n]                    { ; }
.	                    {return *yytext; }
["].*["]                { return STRLT; }

%%

int yywrap() {
    return 1;
}