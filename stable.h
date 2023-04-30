#ifndef  STABLE_H
#define  STABLE_H

#include "error.cpp"
/**
    Maximum symboltable size
*/
#define MOD 997

struct Attributes{
    int type;
    int lineno;
    int offset;
};
struct SymbolTable{
    char *Identifier;
    SymbolTable *next;
    Attributes  *attr;
};

SymbolTable Table[MOD];

short hashCode(char *s);
SymbolTable *newTable(char *,int);
void InsertId(char *,int,int,int);
void InitializeSymbolTable();
void DeleteSymbolTable();
bool IsPresent(char *);
int getLine(char *);
short getType(char *);
void getType(char *errmsg,int type);
#endif
