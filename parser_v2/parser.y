%{
    #include<stdio.h>
    void yyerror(const char *s);
    int yylex();
%}

%token INCLUDE FOR ID NUMBER UNARY BINARY DATATYPE RETURN

%%

program: headers main '(' ')' '{' body return '}'
;

headers: headers headers 
| INCLUDE
;

main: DATATYPE ID
;

body: expressions
| loops
| program expressions
| program loops
;

loops: FOR '(' statement ';' statement ';' statement ')' '{' body '}'
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

return: RETURN NUMBER ';'
| RETURN ID ';'
|
;

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
