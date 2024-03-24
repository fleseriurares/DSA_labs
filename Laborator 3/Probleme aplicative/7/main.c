#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    char cuv[10];
    int frecv;
    struct _node *next;
    struct _node *prev;
} nodeT;

nodeT *newnode(int frecv,char cuv[10])
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->prev=NULL;
    p->frecv=frecv;
    strcpy(p->cuv,cuv);
    return p;
}

void insert_last(nodeT **first,nodeT **last,char cuv[10],int frecv)
{
    if(*first==NULL)
    {
        *first=newnode(frecv,cuv);
        *last=*first;
    }
    else
    {
        nodeT *p=newnode(frecv,cuv);
        (*last)->next=p;
        p->prev=*last;
        *last=p;
    }
}
void interschimbare_char(char cuv1[10],char cuv2[10])
{
    char aux[10];
    strcpy(aux,cuv1);
    strcpy(cuv1,cuv2);
    strcpy(cuv2,aux);
}

void swap(int *a,int *b)
{
    int aux=*a;
    *a=*b;
    *b=aux;
}

void ordonare(nodeT *first)
{
    int ind=0;
    while(ind==0)
    {
        ind=1;
        nodeT *p=first;
        while(p->next!=NULL && strcmp(p->cuv,p->next->cuv)<0)
        {
            p=p->next;
        }
        if(p->next!=NULL)
        {
            ind=0;
            interschimbare_char(p->cuv,p->next->cuv);
            swap(&(p->frecv),&(p->next->frecv));
        }
}
}
void afisare(nodeT *first)
{
    if(first!=NULL)
    {
        while(first->next!=NULL)
        {
            printf("(%s,%d) -> ",first->cuv,first->frecv);
            first=first->next;
        }
        printf("(%s,%d)",first->cuv,first->frecv);
        printf("\n");
    }
}

int main()
{
    nodeT *first=NULL,*last=NULL;
    insert_last(&first,&last,"caine",2);
    insert_last(&first,&last,"pisica",1);
    insert_last(&first,&last,"pesti",3);
    insert_last(&first,&last,"mal",5);
    ordonare(first);
    afisare(first);

    return 0;
}
