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
^"#include"[ ]*<.+\.h>  { return INCLUDE; }
"return"                { return RETURN; }
{binary}	            { return BINARY; }
{unary}	                { return UNARY; }
{num}	                { return NUMBER; }
{datatype}              { return DATATYPE; }
{id}	                { return ID; }
[ \n\t]	                { ; } 
.	                    {return *yytext; }

%%

int yywrap() {
    return 1;
}