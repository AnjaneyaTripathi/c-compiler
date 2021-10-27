# Frontend Phase of a C Compiler

## Features of the Compiler

- Symbol Table
- Parse Tree and AST
- Semantic Analysis
- Intermediate Code Generation

## What the Compiler accepts?

- Simple C programs - declaration and assignment, printf, scanf and arithmetic operations ( + , - , * , / )
- Simple for loops and if-else statements (no else if)
- Nested for loops and if-else statements

## Using the Compiler

```
yacc -d -v parser.y
lex parser.l
gcc -ll y.tab.c
```

## Example of the Compiler in Action

```
#include<stdio.h>
#include<string.h>

int main() {
    int a;
    int x=1;
    int y=2;
    int z=3;
    x=3;
    y=10;
    z=5;
    if(x>5) {
        for(int k=0; k<10; k++) {
            y = x+3;
            printf("Hello!");
        }
    } else {
        int idx = 1;
    }
    for(int i=0; i<10; i++) {
        printf("Hello World!");
        scanf("%d", &x);
        if (x>5) {
            printf("Hi");
        }
        for(int j=0; j<z; j++) {
            a=1;
        }
    } 
    return 1;
}
```

### Symbol Table

![Symbol Table](/Images/table.png)

### Printing Parse Tree Inorder 

![Symbol Table](/Images/inorder.png)

### Visualising the Parse Tree 

![Symbol Table](/Images/tree.jpg)

### Semantic Phase

![Symbol Table](/Images/semantic.png)

### Intermediate Code Generation

![Symbol Table](/Images/icg.png)

## Development of the Compiler

The final compiler was a culmination of various iterations. To see the development stages, take a look at the archive folder which has each iteration. The details of each stage are given below. 

| Parser      | Description |
| ----------------- | ------------------------------------------------------------------------------------------------------------ |
| parser_v1 | This parser contains the lex file with all regular expressions required and a yacc file that defines the Context Free Grammar for a for loop. It accepts a code chunk with a single for loop and simple binary arithmetic and unary expressions in the body. |
| parser_v2 | This parser improves the CFG defined in the previous parser. It accepts a complete C program, including headers, main function, body, and return. The body can contain nested for loops with if-else blocks, printf and scanf statements, and simple expressions. The expressions accepted are basic binary arithmetic operations and unary operations. |
| parser_v3 | This parser is the first attempt at performing lexical analysis on the program accepted by parser_v2. It was observed that handling both if-else and nested for loops together was difficult, so a depth-first approach was followed for the next parsers by first tackling nested for loops and then moving on to if-else blocks. |
| parser_v4  | This parser performs lexical analysis and generates a symbol table for a C program with nested for loops. |
| parser_v5 | This parser performs syntax analysis of the input program with nested for loops. The output of this parser is the syntax tree of the input program. | 
| parser_v6 | This parser adds if-else blocks to the syntax analysis. The output of this parser is the syntax tree of the input program, which may now have nested for and if-else blocks. |
| parser_v7 | The semantic analysis phase starts with this version. This parser checks if variables have been declared before use or if there are duplicate declarations. In case of an error, an informative error message is printed along with the line number. |
| parser_v8 | This version completes the semantic analysis phase. It implements type conversion during arithmetic operations and variable initializations.|
