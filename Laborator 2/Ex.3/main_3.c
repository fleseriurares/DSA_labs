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
void insert_last(nodeT **first,nodeT **last,int a)
{
    nodeT *p=newnod(a);
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
void insert_first(nodeT **first,nodeT **last, int a)
{
    nodeT *p=newnod(a);
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        p->next=*first;
        p->val=a;
        *first=p;
    }
}
nodeT *search(nodeT *first,int x)
{
    nodeT *p=first;
    while(p!=NULL &&p->val!=x)
        p=p->next;
    return p;
}
void insert_after_key(nodeT **first,nodeT **last,int afterkey,int key)
{
    nodeT *p=search(*first,afterkey);
    nodeT *aux=newnod(key);
    if(p!=NULL)
    {
        aux->next=p->next;
        p->next=aux;

        if(aux->next==NULL)
            *last=aux;
    }
    else
        printf("Nu exista nodul dupa care doriti sa inserati!");
}
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
    nodeT *first,*last;
    first=NULL;
    last=NULL;
    insert_first(&first,&last,4);
    afisareL(first);
    insert_first(&first,&last,1);
    afisareL(first);
    insert_last(&first,&last,3);
    afisareL(first);
    printf("\nAdresa primei cautari (2):%p",search(first,2));
    search(first,3);
    printf("\nAdresa primei cautari (3):%p",search(first,3));
    insert_after_key(&first,&last,4,22);
    afisareL(first);
    insert_after_key(&first,&last,3,25);
    afisareL(first);
    return 0;
}
