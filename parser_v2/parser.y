%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include "lex.yy.c"
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void insert_type();
    int search(char *);

    struct dataType{
        char * id_name;
        // char * data_type;
        char * type;
        int line_no;
	} symbolTable[20];
    char count=0;
    int q;
    extern int countn;

%}

%token INCLUDE FOR IF ELSE ID NUMBER UNARY BINARY DATATYPE TRUE FALSE RETURN PRINTFF SCANFF STRLT

%%

program: headers main '(' ')' '{' body return '}'
;

headers: headers INCLUDE { add('H'); } 
| INCLUDE { add('H'); }
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
| DATATYPE variable
| PRINTFF '(' STRLT ')'
| SCANFF '(' STRLT ',' '&' ID ')'
;

variable: ID array
| '*' variable
;

array: '[' NUMBER ']' array 
|  '[' ID ']' array 
| '[' ']' array 
|  
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
    printf("\t\t\tSymbol table\n");
	printf("#######################################################################################\n");	
	printf("\nsymbol \t identify \t line number\n");
	printf("_______________________________________________________________________________________\n");
	int i=0;
	for(i=0;i<count;i++){
		printf("%s\t%s\t%d\t\n",symbolTable[i].id_name,symbolTable[i].type,symbolTable[i].line_no);
		
	}
	for(i=0;i<count;i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
}

int  search(char *type)
{
	int i;
	for(i=count -1 ;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	
	}
	return 0;
}

void add(char c){
    q=search(yytext);
	if(q==0){
		if(c=='H')
		{
			symbolTable[count].id_name=strdup(yytext);
			// symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
    }
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
