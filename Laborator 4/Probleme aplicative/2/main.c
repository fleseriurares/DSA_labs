#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node *left;
    struct _node *right;
    int key;
}nodeT;

nodeT *newnode()
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *creeare_arbore(FILE *f)
{   int a;
    nodeT *p=newnode();
    fscanf(f,"%d",&a);
    if(a==0)
    {
        return NULL;
    }
    else
    {
        p->key=a;
        p->left=creeare_arbore(f);
        p->right=creeare_arbore(f);
        return p;
    }

}

///2
void interschimbare(nodeT *p)
{
    nodeT *aux=p->left;
    p->left=p->right;
    p->right=aux;
}

///3

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int adancime_max(nodeT *arbore)
{
    if(arbore==NULL)
    {
       return -1;
    }
    else
    {
        return 1+max(adancime_max(arbore->left),adancime_max(arbore->right));
    }

}

///4
int max_3(int a, int b,int c)
{
    if(a>b && a>c)
    {
        return a;
    }
    else if(b>c)
    return b;
    return c;
}
int diametru(nodeT *arbore)
{
    if(arbore==NULL)
        return -1;
    return max_3(2+adancime_max(arbore->right)+adancime_max(arbore->left),diametru(arbore->right),diametru(arbore->left));
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

int main()
{
    FILE *f=fopen("arbori2.txt","r");
    nodeT *arbore=creeare_arbore(f);
  ///3  printf("Adancimea maxima este: %d",adancime_max(arbore));
    printf("Diametrul arborelui este: %d",diametru(arbore));
    return 0;
}
