#include <stdio.h>
#include <stdlib.h>

/**
5. Se da un garaj pentru camioane. Drumul de access al garajului poate sa contina oricâte camioane. Garajul are o
singura usa astfel încât doar ultimul camion care a intrat pote sa iasa primul (conform modelului stiva). Fiecare
camion este identificat de un numar întreg pozitiv (truck_id). Scrieti un program care sa trateze diferite tipuri de
mutari ale camioanelor, si sa permita urmatoarele comenzi:
a) Pe_drum (truck_id); b) Intra_in_garaj (truck_ id);
c) Iese_din_garaj (truck_id); d) Afiseaza_camioane (garaj sau drum);
*/

typedef struct _node
{
    int id;
    struct _node *next;
} nodeT;

nodeT *newnode(int val)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->id=val;
    return p;
}

void *insert_drum(nodeT **drum,int val)
{
    nodeT *p=newnode(val);
    nodeT *aux=*drum;
    if(*drum==NULL)
    {
        *drum=p;
    }
    else
    {
        while(aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=p;
    }
}

nodeT *search(nodeT *p,int val)
{
    while(p!=NULL && p->id!=val)
    {
        p=p->next;
    }
    return p;
}

void del_key(nodeT **first,int val)
{
    nodeT *p=*first;
    nodeT *aux;
    if(val==(*first)->id)
    {
        *first=(*first)->next;
        free(p);
    }
    else
    {
        while(p->next!=NULL && p->next->id!=val)
        {
            p=p->next;
        }
        if(p->next==NULL)
            printf("Nu exista nodul de sters!");
        else
        {
            aux=p->next;
            p->next=aux->next;
            free(aux);
        }
    }
}

void insert_garaj(nodeT **garaj,nodeT **drum,int val)
{
    if(*garaj==NULL && search(*drum,val)!=NULL)
    {
        *garaj=newnode(val);
        del_key(drum,val);
    }
    else if(search(*drum,val)!=NULL)
    {
        nodeT *p=newnode(val);
        p->next=*garaj;
        *garaj=p;
        del_key(drum,val);
    }
    else
        printf("Camionul %d nu se afla pe drum!",val);
}

void iese_din_garaj(nodeT **garaj, nodeT **drum,int val)
{
    if((*garaj)->id!=val)
    {
        printf("Camionul %d nu se afla la iesire.\n",val);
    }
    else
    {
        nodeT *aux=*garaj;
        insert_drum(drum,(*garaj)->id);
        *garaj=(*garaj)->next;
        free(aux);
    }
}

void afisare(nodeT *first)
{
    while(first->next!=NULL)
    {
        printf("%d -> ",first->id);
        first=first->next;
    }
    printf("%d",first->id);
    printf("\n");
}
int main()
{
    nodeT *drum=NULL,*garaj=NULL;
    insert_drum(&drum,1);
    insert_drum(&drum,2);
    insert_drum(&drum,3);
    insert_drum(&drum,4);
   afisare(drum);
    insert_garaj(&garaj,&drum,2);
    insert_garaj(&garaj,&drum,3);
    afisare(drum);
    afisare(garaj);

    return 0;
}
