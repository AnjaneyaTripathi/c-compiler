%{
    #include<stdio.h>
    void yyerror(const char *s);
    int yylex();
%}

%token FOR ID NUMBER UNARY BINARY

%%

program: program loop body                    { printf("Loops and more?"); }
| loop body                                   { printf("Loops!"); }
;

loop: FOR '(' for_statements ')'              { printf("For loop!"); }
;

body: statement                               { printf("Nothin' much..."); }
| '{' statements '}'                          { printf("Code Block!"); }
| '{' loop '}' body                           { printf("Nested For?"); }
;

for_statements: statement ';' statement ';' statement
;

statements: statements statement ';'          { printf("Lecture begins!"); }
| statement ';'                               { printf("One liner!"); }
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
