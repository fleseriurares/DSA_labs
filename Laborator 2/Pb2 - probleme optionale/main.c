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
node *inserare(node **first,int val,int poz)
{
    node *p=newnod(val);
    if(poz==1)
    {
        p->next=(*first);
        *first=p;
    }
    else
    {
        node *q=*first;
        for(int i=1; i<poz; i++)
        {
            q=q->next;
        }
        {
            p->next=q->next;
            q->next=p;
        }
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
    afisareL(first);
    printf("pe ce pozitie si ce valoare inserati?");
    int k,val;
    scanf("%d %d",&k,&val);
    inserare(&first,val,k);
    afisareL(first);
    return 0;
}
