#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _arbore{
    char nume[10];
    struct _arbore *tata;
    struct _arbore *mama;
}nodeT;

nodeT *creare_arbore(FILE *f)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    char num[10];
    fscanf(f,"%s",num);
    if(strcmp(num,"stop")==0)
    {
        return NULL;
    }
    strcpy(p->nume,num);
    p->tata=creare_arbore(f);
    p->mama=creare_arbore(f);
    return p;
}

int nivel(nodeT *arbore,char num[10])
{   if(arbore==NULL)
    {
        return -1;
    }
    if(strcmp(arbore->nume,num)==0)
    {
        return 0;
    }

     int st=nivel(arbore->tata,num);
    int dr=nivel(arbore->mama,num);
    if(st==-1 && dr==-1)
    {
        return -1;
    }
    else if(st==-1)
    {
        return dr+1;
    }
    else
        return st+1;
}


void preordine(nodeT *first)
{

    if(first!=NULL)
    {
        printf("%s ",first->nume);
        preordine(first->tata);
        preordine(first->mama);
    }
}

int main()
{
    FILE *f=fopen("arbore_genealogic.txt","r");
    nodeT *p=creare_arbore(f);
    preordine(p);
    printf("\nNivel: %d",nivel(p,"Mihai"));
    return 0;
}
