#include <stdio.h>
#include <stdlib.h>

typedef struct _nodeT
{
    int val;
    struct _nodeT *next;
}nodeT;

nodeT *new_el(int key)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->val=key;
    return p;
}

struct nodeT *xor(nodeT *a, nodeT *b)
{
    return (nodeT *) ((uintptr_t)(a) ^ (uintptr_t)(b));
};


void adaugare(nodeT **tail, int key)
{
    nodeT *p=new_el(key);
    p->next=xor(*tail,NULL);
    if(*tail != NULL)
    {
        nodeT *urm=xor(((*tail)->next),NULL);
        (*tail)->next=xor(p,urm);
    }
    *tail=p;
}
/// NULL - 1 - 2 - 3 - NULL
void print(nodeT *head)
{
    nodeT *a=head;
    nodeT *ant=NULL;
    nodeT *succ;

    printf("Lista este: ");

    while(a!=NULL)
    {
        printf("%d ",a->val);

        succ=xor(ant, a->next);
        ant=a;
        a=succ;
    }

///succ=a->next^ant;
///ant=a->next^succ;

}
void delete_last(nodeT **head)
{
    nodeT *p=xor((*head)->next,NULL);
    nodeT *r=xor(p->next,*head);
    p->next=xor(r,NULL);
    free(*head);
    *head=p;


}

void delete_key(nodeT **first,int key)
{
    nodeT *a=*first;
    nodeT *ant=NULL;
    nodeT *ant2=NULL;
    nodeT *succ;
    nodeT *succ2;
    if((*first)->val==key)
    {
        a=xor(NULL,(*first)->next);
        nodeT *b=xor(a->next,(*first));
        a->next=xor(NULL,b);
        free(*first);
        (*first)=a;

    }
    else
    {
        while(a!=NULL && a->val!=key)
        {
            succ=xor(ant,a->next);
            ant2=ant;
            ant=a;
            a=succ;
        }
        if(xor(a->next,ant)!=NULL)
        {
        succ=xor(ant,a->next);
        succ2=xor(a,succ->next);
        ant->next=xor(ant2,succ);
        succ->next=xor(ant,succ2);
        free(a);
    }
        else
        {
        ant->next=xor(ant2,NULL);
        free(a);
        }
    }


}

///succ=a->next^ant;
///ant=a->next^succ;


int main()
{
    nodeT *tail=NULL;
    nodeT *head=NULL;
    adaugare(&tail,2);
    head=tail;
    adaugare(&tail,3);
    adaugare(&tail,4);
    adaugare(&tail,5);
    ///delete_last(&head);
    ///delete_key(&first,2);
    print(tail);

    return 0;
}
