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
void delete_first(nodeT** first, nodeT** last)
{
    nodeT *p=*first;
    (*first)=(*first)->next;
    free(p);
}
void delete_last(nodeT** first, nodeT** last)
{
    nodeT *p=*first;
    while(p->next!=*last)
    {
        p=p->next;
    }
    p->next=NULL;
    free(*last);
    *last=p;
}
nodeT *search(nodeT *first,int x)
{
    nodeT *p=first;
    while(p!=NULL &&p->val!=x)
        p=p->next;
    return p;
}
///PRIMUL ELEMENT
void delete_key(nodeT** first, nodeT** last, int givenKey)
{
    nodeT *p=search(*first,givenKey);
    if(p==*first)
    {
        *first=(*first)->next;
        free(p);
    }
    else if(p!=NULL)
    {
        nodeT *aux=*first;
        while(aux->next!=p)
        {
            aux=aux->next;
        }
        aux->next=p->next;

        free(p);
    }
    else
        printf("\nNu exista nodul pe care doriti sa il stergeti!");
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
        printf("\nNu exista nodul dupa care doriti sa inserati!");
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
    insert_first(&first,&last,1);
    insert_last(&first,&last,3);
    insert_after_key(&first,&last,4,22);

    insert_after_key(&first,&last,3,25);
    afisareL(first);
    printf("\nSTERGERE:");
    delete_first(&first,&last);
    afisareL(first);
    delete_last(&first,&last);
    afisareL(first);
    delete_key(&first,&last,22);
    afisareL(first);
    delete_key(&first,&last,8);
    afisareL(first);
    return 0;
}
