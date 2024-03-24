#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    int key;
} nodeT;

typedef struct _lista
{
    struct _lista *prev;
    struct _lista *next;
    int key;
} listT;

nodeT *newnode()
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *creare_arbore(FILE *f)
{
    int a;
    nodeT *p=newnode();
    fscanf(f,"%d",&a);
    if(a==0)
    {
        return NULL;
    }
    else
    {
        p->key=a;
        p->left=creare_arbore(f);
        p->right=creare_arbore(f);
        return p;
    }

}

listT *treetolist(nodeT *arbore)
{

}

void preordine(nodeT *first)
{

    if(first!=NULL)
    {
        printf("%d ",first->key);
        preordine(first->left);
        preordine(first->right);
    }
}

void afisare(listT *first)
{
    printf("Lista este:");
    while(first->next!=NULL)
    {
        printf("%d -> ",first->key);
        first=first->next;
    }
    printf("%d",first->key);
}
int main()
{
    FILE *f=fopen("fisier.txt","r");
    nodeT *arbore=creare_arbore(f);
    listT *p=treetolist(arbore);
    preordine(arbore);
    return 0;
}
