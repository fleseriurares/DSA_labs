#include <stdio.h>
#include <stdlib.h>
/**
1. Sa se scrie programul care creeaza doua liste ordonate crescator dupa o cheie numerica si apoi le interclaseaza. .
I/O description. Intrare:
i1 23 47 52 30 2 5 -2
i2 -5 -11 33 7 90
p1
p2
m
p1
p2
Iesire:
1: -2 2 5 23 30 47 52
2: -11 -5 7 33 90
1: -11 5 2 2 5 7 23 ...
2: vida
*/

///Structura:
typedef struct _node
{
    int key;
    struct _node *next;
} nodeT;

nodeT *newnode(int val)
{
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    p->next=NULL;
    p->key=val;
    return p;
}

void insert(nodeT **first,nodeT **last, int val)
{
    nodeT *p=newnode(val);
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

void ordonare(nodeT *first)
{
    nodeT *prev,*act;
    int ind=0,aux;
    while(ind==0)
    {
        ind=1;
        prev=first;
        act=prev->next;
        while(act!=NULL)
        {
            if(prev->key>act->key)
            {
                aux=prev->key;
                prev->key=act->key;
                act->key=aux;
                ind=0;
            }
            prev=prev->next;
            act=act->next;
        }
    }
}

void interclasare(nodeT **first1,nodeT *first2)
{
    nodeT *p=*first1,*aux1=*first1,*aux2=first2,*suc;
    ///facem sa convina in ca ca trebuie schimbata radacina
    if((*first1)->key>(first2)->key)
    {
        p=first2;
        while((*first1)->key>(first2->next)->key)
        {
            first2=first2->next;
        }
        suc=first2->next;
        first2->next=(*first1);
        first2=suc;
        (*first1)=(*first1)->next;
        aux2=suc;
    }

    while((*first1)!=NULL && first2!=NULL)
    {   ///evitam duplicatele
        if(first2->key==(*first1)->key)
        {
            first2=first2->next;
        }
        if((first2->next)!=NULL && first2->key<(*first1)->key)
        {
            while((first2->next)!=NULL && (first2->next)->key<(*first1)->key)
            {
                first2=first2->next;
            }

            suc=first2->next;
            first2->next=(*first1);
            aux1->next=aux2;
            first2=suc;
            aux2=suc;
        }
        aux1=(*first1);
        (*first1)=(*first1)->next;
    }
    if(first2!=NULL)
    {
        aux1->next=first2;
    }
    *first1=p;
}

void afisare(nodeT *first)
{
    printf("Lista este: ");
    while(first->next!=NULL)
    {
        printf("%d -> ",first->key);
        first=first->next;
    }
    printf("%d",first->key);
}

int main()
{
    nodeT *first1=NULL,*last1=NULL,*first2=NULL,*last2=NULL;


    insert(&first1,&last1,23);
    insert(&first1,&last1,47);
    insert(&first1,&last1,52);
    insert(&first1,&last1,30);
    insert(&first1,&last1,33);
    insert(&first1,&last1,2);
    insert(&first1,&last1,5);
    insert(&first1,&last1,-2);
    ordonare(first1);

    insert(&first2,&last2,-5);
    insert(&first2,&last2,-11);
    insert(&first2,&last2,33);
    insert(&first2,&last2,7);
    insert(&first2,&last2,90);
    ordonare(first2);

    /**  insert(&first1,&last1,1);
      insert(&first1,&last1,3);
      insert(&first1,&last1,5);
      ordonare(first1);


      insert(&first2,&last2,4);
      insert(&first2,&last2,2);
      insert(&first2,&last2,6);
      ordonare(first2);
    */
    interclasare(&first1,first2);
    afisare(first1);
    return 0;
}
