#include <stdio.h>
#include <stdlib.h>


/**
2. Se dau doua fisiere text F1.txt si F2.txt care contin elemente numere intregi ordonate crescator. Fiecare numar apare
o singura data in fisier. Cititi datele din cele doua fisiere si stocati informatia in cate o lista simplu inlantuita. Scrieti
o functie care returneaza o lista ce reprezinta intersectia celor doua liste si afisati lista returnata. Scrieti o functie
care returnreaza o lista ce reprezinta reuniunea celor doua liste si afisati-o.

*/

typedef struct _node
{
    int key;
    struct _node *next;
} nodeT;

nodeT *newnode(int val)
{
    nodeT *p=((nodeT *)malloc(sizeof(nodeT)));
    p->next=NULL;
    p->key=val;
    return p;
}

nodeT insert_file(FILE *file,nodeT **first)
{
    int a;
    fscanf(file,"%d",&a);
    nodeT *p;
    *first=newnode(a);
    p=*first;

    while(fscanf(file,"%d",&a)==1)
    {
        p->next=newnode(a);
        p=p->next;

    }
}

nodeT *intersectie(nodeT *p1,nodeT *p2)
{
    nodeT *p=NULL,*rez;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->key<p2->key)
            p1=p1->next;
        else if(p1->key>p2->key)
        {
            p2=p2->next;
        }
        else
        {
            if(p==NULL)
            {
                p=newnode(p1->key);
                rez=p;
            }
            else
            {
                p->next=newnode(p1->key);
                p=p->next;

            }
            p1=p1->next;
            p2=p2->next;
        }
    }
    return rez;
}

nodeT *reuniune(nodeT *p1,nodeT *p2)
{
    nodeT *p=NULL,*rez;
    if(p1->key<p2->key)
    {
        p=newnode(p1->key);
        p1=p1->next;
    }
    else if(p1->key>p2->key)
    {
        p=newnode(p2->key);
        p2=p2->next;
    }
    else
    {
        p=newnode(p1->key);
        p1=p1->next;
        p2=p2->next;
    }
    rez=p;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->key<p2->key)
        {
            p->next=newnode(p1->key);
            p=p->next;
            p1=p1->next;
        }
        else if(p1->key>p2->key)
        {
            p->next=newnode(p2->key);
            p=p->next;
            p2=p2->next;
        }
        else
        {
            p->next=newnode(p1->key);
            p=p->next;
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p2!=NULL)
    {
        p->next=newnode(p2->key);
        p=p->next;
        p2=p2->next;
    }
    while(p1!=NULL)
    {
        p->next=newnode(p1->key);
        p=p->next;
        p1=p1->next;
    }
    return rez;
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
    FILE *f1=fopen("F1.txt","r");
    if(f1==NULL)
    {
        printf("Nu se poate deschide fisierul");
        exit(2);
    }
    FILE *f2=fopen("F2.txt","r");
    if(f1==NULL)
    {
        printf("Nu se poate deschide fisierul");
        exit(3);
    }
    nodeT *first1, *first2;
    insert_file(f1,&first1);
    afisare(first1);
    printf("\n");
    insert_file(f2,&first2);
    afisare(first2);
    printf("\n");
    nodeT *rez1=intersectie(first1,first2);
    nodeT *rez2=reuniune(first1,first2);
    printf("INTERSECTIA:");
    afisare(rez1);
    printf("\nREUNIUNEA:");
    afisare(rez2);
    return 0;
}
