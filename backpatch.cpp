#include "y.tab.h"
#include<iostream>
using namespace std;
typedef YYSTYPE::BackpatchList patchList;
typedef YYSTYPE::switchL switchLR;
/**
    Create a new backpatchList
    @param jump_instruction_number int
    @return backpatchList patchList*
*/
patchList *makeList(int i){
 patchList *temp =  new patchList();
 temp->ins  = i;
 temp->next = NULL;
 return temp;
}

//Merge two backpatchList
patchList *mergeList(patchList *l1,patchList *l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    patchList *t = l1;
    while(t->next!=NULL)t=t->next;
    t->next=l2;
    return l1;
}
/*
    Backpatch  goto instruction
*/
void backpatch(patchList *p,int i){
    patchList *t = p;
    patchList *t2;
    while(t!=NULL){
        quadruple[t->ins].label = i;
        t2=t;
        t=t->next;
        delete t2;
    }
}
/*
    Create backpatchList of switch statement
*/
switchLR*  makeList(int label,bool type,char* val,int lineno){
    switchLR *temp = new switchLR;
    temp->instr  = label;
    temp->stype   = type;
    temp->val    = val;
    temp->lineno = lineno;
    temp->next   = NULL;
    return temp;
}
/*
    Merge two switchList
*/
switchLR* mergeSwitchList(switchLR *l1,switchLR *l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    switchLR *t = l1;
    while(t->next!=NULL)t = t->next;
    t->next = l2;
    return l1;
}
