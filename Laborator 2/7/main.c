#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} nodeT;

nodeT *newnod(int a)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->val=a;
    return p;

}
void insert_last(nodeT **first,nodeT **last,int a, int *nr)
{
    nodeT *p=newnod(a);
    (*nr)++;
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        (*last)->next=p;
        *last=p;
    }
}

/***void inversare_lista(nodeT **first,int nr)
{
    nodeT *ant,*p,*suc;
    ant=*first;
    p=ant->next;
    suc=p->next;
    p->next=ant;
    for(int i=0; i<nr-2; i++)
    {   ant=p;
        p=suc;
        suc=suc->next;
        p->next=ant;

    }
    (*first)->next=NULL;
    (*first)=p;
}
*/
void afisareL(nodeT *first)
{
    printf("\nLista este: ");
    /**for(nodeT *p=first;p!=NULL;p=p->next)
        printf("%d ",p->val);*/
    while(first!=NULL)
    {
        printf("%d ",first->val);
        first=first->next;
    }
}
int main()
{
    nodeT *first;
    nodeT *last=NULL;
    first=NULL;
    int nr=0;
    insert_last(&first,&last,1,&nr);
    insert_last(&first,&last,2,&nr);
    insert_last(&first,&last,3,&nr);
    insert_last(&first,&last,4,&nr);
    insert_last(&first,&last,4,&nr);
    insert_last(&first,&last,4,&nr);
    insert_last(&first,&last,4,&nr);
    insert_last(&first,&last,4,&nr);
    afisareL(first);
    nodeT *ant,*p,*suc;
    ant=first;
    p=ant->next;
    suc=p->next;
    p->next=ant;
    for(int i=0; i<nr-2; i++)
    {
        ant=p;
        p=suc;
        suc=suc->next;
        p->next=ant;

    }
    (first)->next=NULL;
    (first)=p;
    afisareL(first);
    return 0;
}
