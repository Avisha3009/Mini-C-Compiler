flex lexrule.l
bison -dy yaccrule.y
g++ lex.yy.c y.tab.c -ll