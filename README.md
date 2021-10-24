# Collection of Lex and Yacc Codes

### How to Run

```
yacc -d parser.y
lex parser.l
gcc -o output lex.yy.c y.tab.c -ll
```
### Parser_v1

Accepts a code chunk with a single for loop and simple expressions in the body.

### Parser_v2

Accepts a complete C program including headers, main function, body and return. The body can contain nested for loops with if-else blocks. printf and scanf statements and simple expressions. The expressions accepted are basic binary arithmetic operations and unary operations. 

### Parser_v3

The first attempt at performing lexical analysis on the program accepted by parser_v2. It was observed that handling both if-else and nested for loops together was difficult so a depth first approach was folowed for the next parsers by first tackling nested for loops and hten moving on to if-else blocks.

### Parser_v4

Performs lexical analysis and generates symbol table for a C program with nested for loops.

### Parser_v5

Performs syntax analysis and generates syntax tree for a C program with nested for loops.

##### Handle return

```
return: RETURN { add('K'); } value ';' { $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "RETURN"); }
| 
;
```