%{
    #include<stdio.h>
    void yyerror(const char *s);
    int yylex();
%}

%token FOR ID NUMBER UNARY BINARY

%%

program: expressions
| loops
| program expressions
| program loops
;

loops: FOR '(' statement ';' statement ';' statement ')' '{' program '}'
;

expressions: expressions statement ';'
| statement ';'
;

statement: ID BINARY statement
| ID UNARY
| UNARY ID
| ID
| NUMBER
;

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
