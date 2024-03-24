#include <stdio.h>
#include <stdlib.h>

/**6. Se considera problema anterioara a camioanelor dintr-un garaj, dar de aceasta data garajul are doua usi legate printrun drum circular.
O usa este folosita doar pentru intrarea camioanelor în garaj, iar alta usa este folosita pentru iesirea
din garaj. Camioanele pot iesi din garaj doar în ordinea în care au intrat (conform modelului coada)*/

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

void insert_garaj(nodeT **garaj,nodeT **garaj_last,nodeT **drum, int val)
{
    if(*garaj==NULL && search(*drum,val)!=NULL)
    {
        *garaj=newnode(val);
        *garaj_last=*garaj;
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
        printf("Camionul %d nu se afla pe drum!\n",val);
}

void iesire_din_garaj(nodeT **garaj,nodeT **garaj_last,nodeT **drum, int val)
{
    if((*garaj_last)->id==val)
    {
        if(*garaj_last==*garaj)
        {
            free(*garaj);
        }
        else
        {
            insert_drum(drum,val);
            nodeT *p=*garaj;
            while(p->next!=*garaj_last)
            {
                p=p->next;

            }

            free(*garaj_last);
            *garaj_last=p;
            (*garaj_last)->next=NULL;
        }
    }
    else
    {
        printf("Camionul nu se afla la iesire.\n");
    }
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

void afisare(nodeT *first)
{
    if(first!=NULL)
    {
        while(first->next!=NULL)
        {
            printf("%d -> ",first->id);
            first=first->next;
        }
        printf("%d",first->id);
        printf("\n");
    }
}

int main()
{
    nodeT *garaj=NULL,*garaj_last=NULL,*drum=NULL;
    insert_drum(&drum,1);
    insert_drum(&drum,2);
    insert_drum(&drum,3);
    insert_drum(&drum,4);
    insert_drum(&drum,10);
    insert_drum(&drum,20);
    afisare(drum);
    insert_garaj(&garaj,&garaj_last,&drum,2);
    insert_garaj(&garaj,&garaj_last,&drum,1);
    insert_garaj(&garaj,&garaj_last,&drum,20);
    insert_garaj(&garaj,&garaj_last,&drum,3);
    afisare(garaj);
    afisare(drum);
    iesire_din_garaj(&garaj,&garaj_last,&drum,2);
    afisare(garaj);
    afisare(drum);
    return 0;
}
