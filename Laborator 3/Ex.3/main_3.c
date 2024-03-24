#include <stdio.h>
#include <stdlib.h>

/**
Ex. 3 — Implementati urmatoarele functii pentru lista dublu inlantuita:
•Inserare: void insert_first(struct list_header *L, int givenKey), void insert_last(struct list_header *L,
int givenKey) si void insert_after_key(struct list_header *L, int afterKey, int givenKey).
•Parcurgere: void print_forward(struct list_header *L) si void print_backward(struct list_header *L)
care afiseaza continutul listei dublu inlantuite de la primul la ultimul element, respectiv in ordine inversa.
•Cautare: NodeDL* search(struct list_header *L, int givenKey) care cauta in lista ∗L nodul care are cheia
givenKey. Functia returneaza adresa nodului, respectiv NULL daca acesta nu exista.
•Stergere: void delete_first(struct list_header *L), void delete_last(struct list_header *L) si
delete_key(struct list_header *L, int givenKey) pentru lista dublu inlantuita.
*/

typedef struct _node
{
    int val;
    struct _node *prev;
    struct _node *next;
} nodeT;

nodeT *creearenod(int key)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->prev=NULL;
    p->val=key;
    return p;
}

void insert_first(nodeT **first, nodeT **last,int key)
{
    nodeT *p=creearenod(key);
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        p->next=*first;
        (*first)->prev=p;
        (*first)=p;
    }
}

void insert_last(nodeT **first, nodeT **last, int key)
{
    nodeT *p=creearenod(key);
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        p->prev=*last;
        (*last)->next=p;
        *last=p;
    }
}

void insert_after_key(nodeT **first,nodeT **last,int givenkey,int key)
{
    nodeT *p=*first;
    while(p!=NULL && p->val!=givenkey)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        nodeT *q=creearenod(key);
        if(p->next==NULL)
        {
            p->next=q;
            q->prev=p;
            *last=q;
        }
        else
        {
            q->next=p->next;
            p->next->prev=q;
            p->next=q;
            q->prev=p;
        }
    }
    else
    {
        printf("Nu exista nodul cu valoareaa %d in lista.\n",givenkey);
    }
}

nodeT *search(nodeT *first,int givenkey)
{
    while(first!=NULL)
    {
        if(first->val==givenkey)
        {
            return first;
        }
        first=first->next;
    }
    return first;
}

void delete_first(nodeT **first)
{
    if(*first!=NULL)
    {
        nodeT *p=*first;
        *first=(*first)->next;
        (*first)->prev=NULL;
        free(p);
    }
    else
    {
        printf("Lista este goala");
    }
}

void delete_last(nodeT **first)
{
    nodeT *p=*first;
    nodeT *aux=*first;
    if(aux!=NULL)
    {
        if((*first)->next==NULL)
            free(*first);
        else
        {
            while((aux->next)!=NULL)
                aux=aux->next;
            p=aux->prev;
            p->next=NULL;
            aux->prev=NULL;
            free(aux);
        }
    }
    else
    {
        printf("Lista este goala");
    }
}

void delete_key(nodeT **first, int givenkey)
{
    nodeT *p=search(*first,givenkey);
    if(p==NULL)
    {
        printf("Nu exista nodul pe care doriti sa il stergeti.");
    }
    else
    {
        if(p==*first)
        {
            *first=(*first)->next;
            (*first)->prev=NULL;
            free(p);
        }
        else if(p->next==NULL)
        {
            p->prev->next=NULL;
            free(p);
        }
        else
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
        }
    }
}

void printf_forward(nodeT *first)
{
    printf("Lista este:");
    while(first->next!=NULL)
    {
        printf("%d ",first->val);
        first=first->next;
    }
    printf("%d",first->val);
}

void printf_backward(nodeT *last)
{
    printf("Lista este:");
    while(last->prev!=NULL)
    {
        printf("%d ",last->val);
        last=last->prev;
    }
    printf("%d",last->val);
}

void printf_backward1(nodeT *first)
{
    printf("Lista este:");

    while(first->next!=NULL)
    {
        first=first->next;
    }
    while(first->prev!=NULL)
    {
        printf("%d ",first->val);
        first=first->prev;
    }
    printf("%d",first->val);
}

int main()
{
    nodeT *first=NULL,*last=NULL;
    ///insert_first(&first,&last,1);
    ///insert_first(&first,&last,2);
    insert_last(&first,&last,1);
    insert_last(&first,&last,2);
    insert_last(&first,&last,3);
    insert_last(&first,&last,4);
    insert_last(&first,&last,5);
    ///insert_after_key(&first,&last,3,10);
    ///insert_after_key(&first,&last,10,20);
    /// delete_first(&first);
    /// delete_last(&first);
    delete_key(&first,3);
    printf_forward(first);
    printf("\n");
    printf_backward1(first);
    ///nodeT *p=search(first,3);
    ///printf("\n val=%d",p->val);
    return 0;
}
