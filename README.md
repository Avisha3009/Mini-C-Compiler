# Mini C Compiler 

To parse and generate Intermediate Code, optimise it and generate the final machine code for switch and do-while construct using lex and yacc.

## Steps to be followed to generate Intermediate Code:

```bash
flex lexrule.l
bison -dy yaccrule.y
g++ lex.yy.c y.tab.c -ll
./a.out test.c
```

OR

```bash
./Compile.sh
./a.out test.c
```
## Steps to generate the optimised icg and target code

```bash
python optimise.py
python labels.py
python tcg.py
```