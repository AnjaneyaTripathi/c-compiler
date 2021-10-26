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
	void insert_type();

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
	} symbolTable[20];
    int count=0;
    int q;
	char type[10];
    extern int countn;

%}

%token INCLUDE FOR IF ELSE ID NUMBER UNARY BINARY DATATYPE TRUE FALSE RETURN PRINTFF SCANFF STRLT

%%

program: headers main '(' ')' '{' body return '}'
;

headers: headers headers
| INCLUDE { add('H'); }
;

main: DATATYPE { insert_type(); } ID { add('V'); }
;

body: expressions
| loops
| conditionals
| expressions body
| loops body
| conditionals body
;

loops: FOR { add('K'); } '(' statement statement statement ')' '{' body '}'
;

expressions: statement expressions
| statement
;

conditionals: IF { add('K'); } '(' condition ')' '{' expressions '}' else
;

else: ELSE { add('K'); } '{' expressions '}'
|
;

statement: DATATYPE { insert_type(); } ID { add('V'); } ';'
| DATATYPE { insert_type(); } variable
| ID BINARY statement
| ID UNARY ';'
| UNARY ID ';'
| ID ';'
| NUMBER { add('C'); } ';'
| PRINTFF '(' STRLT ')' ';'
| SCANFF '(' STRLT ',' '&' ID ')' ';'
;

variable: ID array
| '*' variable
| ID { add('V'); } '=' NUMBER { add('C'); } ';'
| ',' variable
;

array: '[' NUMBER { add('C'); } ']' array 
| '[' ID ']' array 
| '[' ']' array 
| ';'
;

condition: condition BINARY boolean
| boolean
;

boolean: ID BINARY ID
| ID BINARY NUMBER { add('C'); }
| NUMBER { add('C'); } BINARY ID
| TRUE { add('K'); }
| FALSE { add('K'); }
;

return: RETURN { add('K'); } NUMBER { add('C'); } ';'
| RETURN { add('K'); } ID ';'
|
;

%%

int main() {
    yyparse();
    printf("\t\t\tSymbol table\n");
	printf("#######################################################################################\n");	
	printf("\nsymbol \t identify \t line number\n");
	printf("_____________________________\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbolTable[i].id_name, symbolTable[i].data_type, symbolTable[i].type, symbolTable[i].line_no);
	}
	for(i=0; i<count; i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbolTable[i].id_name,type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

void add(char c) {
    q=search(yytext);
	if(q==0) {
		if(c=='H') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c =='K') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Keyword");
			count++;
		}
		else if(c=='V') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Variable");
			count++;
		}
		else if(c=='C') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Constant");
			count++;
		}
    }
}

void insert_type() {
	strcpy(type,yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}