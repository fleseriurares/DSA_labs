#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int val;
struct node *next;
}nodeT;

nodeT *newnod(int a)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->val=a;
    return p;

}nodeT *inserarefin(nodeT **first,int a)
{
    nodeT *p=newnod(a);
    if(*first==NULL)
    {
        *first=p;
    }
    else
    {
        nodeT *it=*first;
        while(it->next!=NULL)
            it=it->next;
        it->next=p;
    }
}
///Functia search:
nodeT *search(nodeT *first,int x)
{
    nodeT *p=first;
    while(p->val!=x && p!=NULL)
        p=p->next;
    return p;
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
        inserarefin(&first,x);
    }
    printf("valoarea cautata este:");
    scanf("%d",&x);
    printf("%p",search(first,x));
    return 0;
}
