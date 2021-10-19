%{
    #include<stdio.h>
    void yyerror(const char *s);
    int yylex();
%}

%token INCLUDE FOR IF ELSE ID NUMBER UNARY BINARY DATATYPE TRUE FALSE RETURN

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
| conditionals
| body expressions
| body loops
| body conditionals
;

loops: FOR '(' statement ';' statement ';' statement ')' '{' body '}'
;

expressions: expressions statement ';'
| statement ';'
;

conditionals: IF '(' condition ')' '{' expressions '}'
| IF '(' condition ')' '{' expressions '}' ELSE '{' expressions '}'
;

statement: ID BINARY statement
| ID UNARY
| UNARY ID
| ID
| NUMBER
;

condition: condition BINARY condition
| boolean
;

boolean: ID BINARY ID
| ID BINARY NUMBER
| NUMBER BINARY ID
| TRUE
| FALSE
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
