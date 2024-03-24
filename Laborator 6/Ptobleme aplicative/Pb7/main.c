#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 7

typedef struct _node{
    char word[10];
    struct _node *next;
}nodeT;

nodeT *newnode(char cuv[10])
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    strcpy(p->word,cuv);
    return p;
}

void set_NULL(nodeT *T[M])
{
    for(int i=0;i<M;i++)
    {
        T[i]=NULL;
    }
}

void insert(nodeT *T[M],char cuv[10])
{
    int a=f2(f1(cuv));
    if(T[a]==NULL)
    {
        T[a]=newnode(cuv);
    }
    else
    {
        nodeT *p=T[a];
        T[a]=newnode(cuv);
        T[a]->next=p;
    }
}

int f1(char cuv[10])
{
    int n=strlen(cuv);
    int suma=0;
    for(int i=0;i<n;i++)
    {
        suma=suma+cuv[i];
    }
    suma=suma/n;
    return suma;
}
int f2(int a)
{
    return a%M;
}

int index(char cuv[10])
{
    return f2(f1(cuv));
}

void print(nodeT *T[M])
{
    for(int i=0;i<M;i++)
    {
        printf(" %d: ",i);
        nodeT *p=T[i];
        if(p!=NULL)
        {
        if(p->next!=NULL)
        {
            printf("%s -> ",p->word);
            p=p->next;
        }
        printf("%s ",p->word);
        }
        printf("\n");
    }
}
int main()
{
    nodeT *T[M];
    set_NULL(T);
    char cuv[10];
    scanf("%s",cuv);
    while(strcmp(cuv,"stop"))
    {
        insert(T,cuv);
        scanf("%s",cuv);
    }
    print(T);
    return 0;
}
