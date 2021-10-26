%{
    #include "y.tab.h"
%}

num	    [0-9]+
id	    [a-zA-Z]+
binary	=|<|>|!=|<=|>=|==|&&|"||"|[+-/*]
unary	"++"|"--"

%%

"for"	    { return FOR; }
{binary}	{ return BINARY; }
{unary}	    { return UNARY; }
{num}	    { return NUMBER; }
{id}	    { return ID; }
[ \n\t]	    { ; } 
.	        {return *yytext; }

%%

int yywrap() {
    return 1;
}