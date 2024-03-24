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
    printf("\nLista este:\n");
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
    int n,x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        ///insert_first(&first,&last,x);
        insert_last(&first,&last,x);

    }
    int afterkey,key;
    printf("Nodul dupa care doriti sa inserati este:");
    scanf("%d",&afterkey);
    printf("Valoarea noului nod este:");
    scanf("%d",&key);
    insert_after_key(&first,&last,afterkey,key);
    afisareL(first);
    return 0;
}
