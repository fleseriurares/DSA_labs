#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int val;
    struct _node *next;
} node;

///CREEARE NOD
node *newnod(a)
{
    node *p=(node *)malloc(sizeof(node));
    p->next=NULL;
    p->val=a;
    return p;
}
node *inserarefin(node **first,int a)
{
    node *p=newnod(a);
    if(*first==NULL)
    {
        *first=p;
    }
    else
    {
        node *it=*first;
        while(it->next!=NULL)
            it=it->next;
        it->next=p;
    }
}
void afisareL(node *first)
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
void inversare(node **first)
{

    node *p=*first;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    last=p;
    int a[100],i;
    for(p=*first,i=0;p!=NULL;p=p->next, i++)
    {
        a[i]=p->val;
    }
    int k=i;
     for(p=*first,i=k-1;p!=NULL;p=p->next,i--)
    {
        p->val=a[i];
    }

}
int main()
{
    node *first,*last;
    first=NULL;
    last=NULL;
    int n,x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        inserarefin(&first,x);
    }
    inversare(&first);
    afisareL(first);
    return 0;
}
