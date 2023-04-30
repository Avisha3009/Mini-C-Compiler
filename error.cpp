#include <cstring>
#include <string.h>
#include <vector>
#include "error.h"

er *newerNode(const char *errmsg,int lineno){
    er *temp  = new er;
    temp->lineno = lineno;
    temp->errmsg =  new char[strlen(errmsg)];
    strcpy(temp->errmsg,errmsg);
    temp->next = NULL;
    return temp;
}

int IsDuplicateCaseLabel(YYSTYPE::switchL *l,char *p){
   /**
    Scan switch list if there is duplicate then return line_number where it was declared first
    else return -1
   */
    YYSTYPE::switchL *l2=l;
    while(l2!=NULL){
        if( ! strcmp(l2->val,p) )
        return l2->lineno;
        l2=l2->next;
    }
    return -1;
}

void AddError(const char *errmsg,int lineno,int8_t ertype){
  
    if(Error==NULL){
        Error = newerNode(errmsg,lineno);
        Error->ertype = ertype;
    }
    else{
            er *temp = Error;
            while(temp->next!=NULL)temp = temp->next;
            temp->next = newerNode(errmsg,lineno);
            temp->next->ertype = ertype;
    }
}

void printError(){
    er *temp;
    fprintf(stderr,"%s","--line--------------------message-------------------\n");
    while(Error){
        switch(Error->ertype){
            case ERROR:
                fprintf(stderr,"%4d  error: %s\n",Error->lineno,Error->errmsg);
                break;
            case NOTE:
                fprintf(stderr,"%4d  note: %s\n",Error->lineno,Error->errmsg);
                break;
            case WARNING:
                fprintf(stderr,"%4d  warning: %s\n",Error->lineno,Error->errmsg);
                break;
           default:
                fprintf(stderr,"%4d  error: %s\n",Error->lineno,Error->errmsg);
        }
        temp = Error;
        Error=Error->next;
        delete temp;
    }
    fprintf(stderr,"%s","----------------------------------------------------------\n");
}
