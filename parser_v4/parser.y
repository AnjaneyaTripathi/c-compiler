%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
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

%token PRINTFF SCANFF INT FLOAT CHAR VOID RETURN FOR INCLUDE TRUE FALSE NUMBER ID LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY

%%

program: headers main '(' ')' '{' body return '}' 
;

headers: headers headers
| INCLUDE { add('H'); }
;

main: datatype ID { add('K'); }
;

datatype: INT { insert_type(); }
| FLOAT { insert_type(); }
| CHAR { insert_type(); }
| VOID { insert_type(); }
;

body: FOR { add('K'); } '(' statement ';' statement ';' statement ')' '{' body '}'
| statement ';'
| body body
| PRINTFF { add('K'); } '(' STR ')' ';'
| SCANFF { add('K'); } '(' STR ',' '&' ID ')' ';'
;

statement: datatype ID { add('V'); } init
| ID '=' expression 
| ID relop value
| ID UNARY
| UNARY ID
;

init: '=' value
| 
;

value: ID
| NUMBER { add('C'); }
;

expression: expression arithmetic expression
| value
;

arithmetic: ADD
| SUBTRACT
| MULTIPLY
| DIVIDE
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

return: RETURN { add('K'); } value ';'
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
		if(strcmp(symbolTable[i].id_name, type)==0) {
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
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c =='K') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Keyword");
			count++;
		}
		else if(c=='V') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Variable");
			count++;
		}
		else if(c=='C') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("CONST");
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Constant");
			count++;
		}
    }
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}