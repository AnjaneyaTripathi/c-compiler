# Collection of Lex and Yacc Codes

### How to Run

```
yacc -d parser.y
lex parser.l
gcc -o output lex.yy.c y.tab.c -ll
```

return: RETURN { add('K'); } value ';' { $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "RETURN"); }
| 
;