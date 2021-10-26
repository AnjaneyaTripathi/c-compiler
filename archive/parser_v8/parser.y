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
	void printtree(struct node*);
	void printTreeUtil(struct node*, int);
	void printInorder(struct node *);
    void check_declaration(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	struct node* mknode(struct node *left, struct node *right, char *token);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
	} symbolTable[40];

    int count=0;
    int q;
	char type[10];
    extern int countn;
	struct node *head;
	int sem_errors=0;

	struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};

%}

%union { struct var_name { 
		char name[100]; 
		struct node* nd;
		} nam;

		struct var_name2 { 
		char name[100]; 
		struct node* nd;
		char type[5];
		} nam2; 
	} 
%token VOID 
%token <nam> PRINTFF SCANFF INT FLOAT CHAR FOR IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY INCLUDE RETURN 
%type <nam> headers main body return datatype statement arithmetic relop program else condition
%type <nam2> init value expression

%%

program: headers main '(' ')' '{' body return '}' { $2.nd = mknode($6.nd, $7.nd, "main"); $$.nd = mknode($1.nd, $2.nd, "program"); 
	head = $$.nd;
} 
;

headers: headers headers { $$.nd = mknode($1.nd, $2.nd, "headers"); }
| INCLUDE { add('H'); } { $$.nd = mknode(NULL, NULL, $1.name); }
;

main: datatype ID { add('K'); }
;

datatype: INT { insert_type(); }
| FLOAT { insert_type(); }
| CHAR { insert_type(); }
| VOID { insert_type(); }
;

body: FOR { add('K'); } '(' statement ';' statement ';' statement ')' '{' body '}' { struct node *temp = mknode($6.nd, $8.nd, "CONDITION"); struct node *temp2 = mknode($4.nd, temp, "CONDITION"); $$.nd = mknode(temp2, $11.nd, $1.name); }
| IF { add('K'); } '(' condition ')' '{' body '}' else { struct node *iff = mknode($4.nd, $7.nd, $1.name); $$.nd = mknode(iff, $9.nd, "if-else"); }
| statement ';' { $$.nd = $1.nd; }
| body body { $$.nd = mknode($1.nd, $2.nd, "statements"); }
| PRINTFF { add('K'); } '(' STR ')' ';' { $$.nd = mknode(NULL, NULL, "printf"); }
| SCANFF { add('K'); } '(' STR ',' '&' ID ')' ';' { $$.nd = mknode(NULL, NULL, "scanf"); }
;

else: ELSE { add('K'); } '{' body '}' { $$.nd = mknode(NULL, $4.nd, $1.name); }
| { $$.nd = NULL; }
;

condition: value relop value { $$.nd = mknode($1.nd, $3.nd, $2.name); }
| TRUE { add('K'); $$.nd = NULL; }
| FALSE { add('K'); $$.nd = NULL; }
| { $$.nd = NULL; }
;

statement: datatype ID { add('V'); } init { 
	$2.nd = mknode(NULL, NULL, $2.name); 
	int t = check_types($1.name, $4.type); 
	if(t>0){ 
		if(t == 1) {
			struct node *temp = mknode(NULL, $4.nd, "inttofloat"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} else { 
			struct node *temp = mknode(NULL, $4.nd, "floattoint"); 
			$$.nd = mknode($2.nd, temp, "declaration"); 
		} 
	} else { 
		$$.nd = mknode($2.nd, $4.nd, "declaration"); 
	} 
}
| ID { check_declaration($1.name); } '=' expression {
	$1.nd = mknode(NULL, NULL, $1.name); 
	char *id_type = get_type($1.name); 
	if(id_type[0] != $4.type[0]) {
		if(id_type[0] == 'i') {
			struct node *temp = mknode(NULL, $4.nd, "floattoint");
			$$.nd = mknode($1.nd, temp, "="); 
		}
		else {
			struct node *temp = mknode(NULL, $4.nd, "inttofloat");
			$$.nd = mknode($1.nd, temp, "="); 
		}
	}
	else{
		$$.nd = mknode($1.nd, $4.nd, "="); 
	}
}
| ID { check_declaration($1.name); } relop expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $4.nd, $3.name); }
| ID { check_declaration($1.name); } UNARY { $1.nd = mknode(NULL, NULL, $1.name); $3.nd = mknode(NULL, NULL, $3.name); $$.nd = mknode($1.nd, $3.nd, "ITERATOR"); }
| UNARY ID { check_declaration($2.name); $1.nd = mknode(NULL, NULL, $1.name); $2.nd = mknode(NULL, NULL, $2.name); $$.nd = mknode($1.nd, $2.nd, "ITERATOR"); }
;

init: '=' value { $$.nd = $2.nd; sprintf($$.type, $2.type); }
| { sprintf($$.type, "null"); $$.nd = mknode(NULL, NULL, "NULL"); }
;

expression: expression arithmetic expression { 
	if($1.type[0] == $3.type[0]){
		sprintf($$.type, $1.type);
		$$.nd = mknode($1.nd, $3.nd, $2.name); 
	}
	else{
		sprintf($$.type, "float");
		if($1.type[0] == 'i'){
			struct node *temp = mknode(NULL, $1.nd, "inttofloat");
			$$.nd = mknode(temp, $3.nd, $2.name);
		}
		else{
			struct node *temp = mknode(NULL, $3.nd, "inttofloat");
			$$.nd = mknode($1.nd, temp, $2.name);
		}
	}
}
| value { sprintf($$.type, $1.type); $$.nd = $1.nd; }
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

value: NUMBER { sprintf($$.type, "int"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| FLOAT_NUM { sprintf($$.type, "float"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); }
| ID { char *id_type = get_type($1.name); sprintf($$.type, id_type); check_declaration($1.name); $$.nd = mknode(NULL, NULL, $1.name); }
;

return: RETURN { add('K'); } value ';' { $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "RETURN"); }
| { $$.nd = NULL; }
;

%%

int main() {
    yyparse();
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbolTable[i].id_name, symbolTable[i].data_type, symbolTable[i].type, symbolTable[i].line_no);
	}
	for(i=0;i<count;i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	printtree(head); 
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
	if(sem_errors>0){
		printf("Semantic analysis completed with %d errors!", sem_errors);
	}else{
		printf("Semnatic analysis completed with no errors");
	}
	printf("\n\n");
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

void check_declaration(char *c) {
    q = search(c);
    if(!q) {
        printf("ERROR: Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
        //exit(0);
    }
}

int check_types(char *type1, char *type2){
	if(type1[0] == type2[0])
		return 0;
	if(type1[0]=='f')
		return 1;
	return 2;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Insert proper equality check function
		// Handle case of use before declaration
		if(symbolTable[i].id_name[0] == var[0]) {
			return symbolTable[i].data_type;
		}
	}
}

void add(char c) {
    q=search(yytext);
	if(!q) {
		if(c == 'H') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("CONST");
			symbolTable[count].line_no=countn;
			symbolTable[count].type=strdup("Constant");
			count++;
		}
    }
    else if(c == 'V' && q) {
        printf("ERROR: Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
		sem_errors++;
    }
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void printtree(struct node* tree) {
	//printTreeUtil(tree, 0);
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	printInorder(tree);
}

void printInorder(struct node *tree) {
	int i;
	if (tree->left) {
		printInorder(tree->left);
	}
	printf("%s, ", tree->token);
	if (tree->right) {
		printInorder(tree->right);
	}
}

void printTreeUtil(struct node *root, int space) {
    if(root == NULL)
        return;
    space += 7;
    printTreeUtil(root->right, space);
    for (int i = 7; i < space; i++)
        printf(" ");
	printf("%s\n", root->token);
    printTreeUtil(root->left, space);
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}