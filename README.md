# Collection of Lex and Yacc Codes

### How to Run

```
yacc -d parser.y
lex parser.l
gcc -o output lex.yy.c y.tab.c -ll
```