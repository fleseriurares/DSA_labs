#include <stdio.h>
#include <stdlib.h>

#define M 7
typedef struct _node
{
    int key;
    struct _node *next;
} nodeT;

nodeT *newnode(int val)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->key=val;
    p->next=NULL;
    return p;
}

int hfunction(int x)
{
    return x%M;
}

void insert(nodeT *htable[M],int val)
{
    int a=hfunction(val);
    if(htable[a]==NULL)
    {
        htable[a]=newnode(val);
    }
    else
    {
        nodeT *p=htable[a];
        htable[a]=newnode(val);
        htable[a]->next=p;

    }
}

void afisare(nodeT *htable[M])
{
    for(int i=0; i<M; i++)
    {
        printf(" %d: ",i);
        if(htable[i]!=NULL)
        {
            nodeT *p=htable[i];
            while(p->next!=NULL)
            {
                printf("%d -> ",p->key);
                p=p->next;
            }
            printf("%d",p->key);
        }
        printf("\n");
    }
}

nodeT *findElem(nodeT *htable[M],int val)
{
    int a=hfunction(val);
    nodeT *p=htable[a];
    while(p!=NULL && p->key!=val)
    {
        p=p->next;
    }
    return p;
}

void del(nodeT *htable[M],int val)
{
    nodeT *p=findElem(htable,val);
    if(p==NULL)
    {
        printf("Nu exista elem. de sters");
    }
    int a=hfunction(val);
    p=htable[a];
    if(p->key==val)
    {
        nodeT *aux=p->next;
        htable[a]=aux;
        free(p);
    }
    else
    {
        while(p->next!=NULL && p->next->key!=val)
        {
            p=p->next;
        }
        if(p->next!=NULL)
        {
            nodeT *aux=p->next;
            p->next=aux->next;
            free(aux);
        }
    }
}

int main()
{
    nodeT *htable[M];
    for(int i=0; i<M; i++)
    {
        htable[i]=NULL;
    }
    insert(htable,2);
    insert(htable,5);
    insert(htable,8);
    insert(htable,1);
    insert(htable,22);
    insert(htable,29);
    afisare(htable);
    del(htable,5);
    afisare(htable);
    nodeT *p=findElem(htable,2);
    printf("SEARCH: %d",p->key);
    return 0;
}
