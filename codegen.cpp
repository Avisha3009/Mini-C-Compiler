#include <cstring>
#include <string.h>
#include <vector>
#include "codegen.h"
#include "backpatch.cpp"
#include "stable.cpp"
extern Quadruple quadruple[5000];

char* newTemp(){
	char *temp= new char[10];
	snprintf(temp,10,"t%d",tempGenerated);
	tempGenerated++;
	return temp;
}
void printCode(){
    FILE * file = fopen("output.txt","w");
    FILE* fp = fopen("icg.txt","w");
	for(int i=0;i<nextInstr-1;i++){
	     printf("\n");
	     fprintf(file,"\n");
	     fprintf(fp,"\n");
        if(!strcmp(quadruple[i].result,"if")){
            // cout<<quadruple[i].addr1<<endl;
            printf("%.4d : %s %s %s %s %s %.4d",i,quadruple[i].result,quadruple[i].addr1,quadruple[i].op,quadruple[i].addr2,quadruple[i].addr3,quadruple[i].label);
            fprintf(file,"%.4d : %s %s %s %s %s %.4d",i,quadruple[i].result,quadruple[i].addr1,quadruple[i].op,quadruple[i].addr2,quadruple[i].addr3,quadruple[i].label);
            fprintf(fp,"%s %s %s %s %s %d",quadruple[i].result,quadruple[i].addr1,quadruple[i].op,quadruple[i].addr2,quadruple[i].addr3,quadruple[i].label);
            continue;
        }
        if(!strcmp("goto",quadruple[i].result)){
             printf("%.4d : %s %.4d",i,quadruple[i].result,quadruple[i].label);
             fprintf(file,"%.4d : %s %.4d",i,quadruple[i].result,quadruple[i].label);
             fprintf(fp,"%s %d",quadruple[i].result,quadruple[i].label);
             
        }
	    else{
            printf("%.4d : %s = %s",i,quadruple[i].result,quadruple[i].addr1);
            fprintf(file,"%.4d : %s = %s",i,quadruple[i].result,quadruple[i].addr1);
            fprintf(fp,"%s = %s",quadruple[i].result,quadruple[i].addr1);
            if(quadruple[i].op!=NULL){
                printf(" %s",quadruple[i].op);
                fprintf(file," %s",quadruple[i].op);
                fprintf(fp," %s",quadruple[i].op);
            }
            else continue;
            if(quadruple[i].addr2!=NULL){
                printf(" %s",quadruple[i].addr2);
                fprintf(file," %s",quadruple[i].addr2);
                fprintf(fp," %s",quadruple[i].addr2);
            }
            else continue;
            if(quadruple[i].addr3!=NULL){
                printf(" %s",quadruple[i].addr3);
                fprintf(file," %s",quadruple[i].addr3);
                fprintf(fp," %s",quadruple[i].addr3);
            }
            else continue;
            if(quadruple[i].label!=0){
                printf(" %d",quadruple[i].label);
                fprintf(file," %d",quadruple[i].label);
                fprintf(fp," %d",quadruple[i].label);
            }
	    }
	}
	 printf("\n%.4d : %s\n",nextInstr-1,quadruple[nextInstr-1].result);
	 fprintf(file,"\n%.4d : %s\n",nextInstr-1,quadruple[nextInstr-1].result);
	 fprintf(fp,"\n %s\n",quadruple[nextInstr-1].result);
	 fclose(file);
}
/*
    Generate 3 address code and store in Quadrule table for binary expression 
*/
void genCode(const char *result,const char*addr1,const char *op,const char *addr2){
        quadruple[nextInstr].result=(char*)result;
		quadruple[nextInstr].addr1=(char*)addr1;
        quadruple[nextInstr].op=(char*)op;
		quadruple[nextInstr].addr2=(char*)addr2;
		quadruple[nextInstr].addr3=NULL;
		quadruple[nextInstr].label=0;
		nextInstr++;
}
/*
    Generate 3 address code and store in Quadrule table for unary expression
*/
void genCode(const char *result,const char *unop,const char*addr1){
        quadruple[nextInstr].result=(char*)result;
		quadruple[nextInstr].addr1=NULL;
        quadruple[nextInstr].op=(char*)unop;
		quadruple[nextInstr].addr2=(char*)addr1;
		quadruple[nextInstr].addr3=NULL;
		quadruple[nextInstr].label=0;
		nextInstr++;
}
/*
    Generate 3 address code and store in Quadrule table for conditional jump

*/
void genCode(const char*result,const char *addr1,const char *op,const char *addr2,const char *addr3,int label){

		quadruple[nextInstr].result=(char*)result;
        //cout<<addr1<<endl;
		quadruple[nextInstr].addr1=(char*)addr1;
        //cout<<quadruple[nextInstr].addr1<<endl;
		quadruple[nextInstr].op=(char*)op;
		quadruple[nextInstr].addr2=(char*)addr2;
		quadruple[nextInstr].addr3=(char*)addr3;
		quadruple[nextInstr].label=label;
		nextInstr++;
}
/*
    Generate 3 address code and store in Quadrule table for assignement
*/
void genCode(const char *result,const char *addr1){
		quadruple[nextInstr].result = (char*)result;
		quadruple[nextInstr].addr1 = (char*)addr1;
		quadruple[nextInstr].addr2 = NULL;
		quadruple[nextInstr].addr3 = NULL;
		quadruple[nextInstr].label =0;
		nextInstr++;
}
/*
    Generate 3 address code and store in Quadrule table for goto target
*/
void genCode(const char *result,int label){
		quadruple[nextInstr].result = (char*)result;
		quadruple[nextInstr].addr1 = NULL;
		quadruple[nextInstr].addr2 = NULL;
		quadruple[nextInstr].addr3 = NULL;
		quadruple[nextInstr].label = label;
		nextInstr++;
}
