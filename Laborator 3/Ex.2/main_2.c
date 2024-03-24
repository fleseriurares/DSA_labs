#include <stdio.h>
#include <stdlib.h>
/**
Ex. 2 — Implementati operatiile fundamentale pe coada – void enqueue(struct queue *my_queue, int key)
si int dequeue(struct queue *my_queue) (impreuna cu o functie de initializare a cozii si una de afisare a
elementelor acesteia), utilizand un vector ca si structura de baza.
Utilizati exemplele furnizate in Figura 3.4 si pseudocodul disponibil in Th. Cormen et. al, "Introduction to
Algorithms" (pag 235, sect 10.1).
Implementarea voastra ar trebui sa considere cazurile de overflow la inserare (coada este plina, nu se mai poate
insera), respectiv underflow la stergere (coada este goala, nu se poate sterge element). Cate elemente poate contine
maxim o coada implementata asa, daca vectorul de baza are dimensiune CAPACITY ? Sugestie: Structura
queue ar trebui sa contina un vector de dimens CAP ACIT Y (data, constanta), si cei doi indici - head, respectiv
tail.
#define CAPACITY 10
typedef struct _queue
{
int vec[CAPACITY];
int size;
int head, tail;
}queue
*/
#define CAPACITY 10
typedef struct _queue
{
    int vec[CAPACITY];
    int size;
    int head, tail;
} queue;

///ALOCARE COADA
queue *newqueue()
{
    queue *p=(queue *)malloc(sizeof(queue));
    return p;

}
void enqueue(queue *q, int key)
{
    if(q->tail==q->head && q->size!=0)
    {
        printf("COADA ESTE PLINA!");
    }
    else
    {   (q->size)++;
        q->vec[q->tail]=key;
        if(q->tail==CAPACITY-1)
            q->tail=0;
        else
            (q->tail)++;
    }
}

int dequeue(queue *q)
{
    if(q->size==0)
    {
        printf("Coada este goala, nu se mai poate sterge niciun element.");
    }
    else
    {
        if(q->head!=CAPACITY-1)
        {
            q->head++;
        }
        else
        {
            q->head=0;
        }
    }
}

void afisareQ(queue *q)
{
    printf("Coada este: ");
   /// printf("--%d--\n",q->head);
    if(q->head<=q->tail)
    {
        for(int i=q->head; i<q->tail; i++)
        {
            printf("%d ",q->vec[i]);
        }
    }
    else
    {
        for(int i=q->head; i<CAPACITY; i++)
        {
            printf("%d ",q->vec[i]);
        }
        for(int i=0; i<q->tail; i++)
        {
            printf("%d ",q->vec[i]);
        }
    }
}
int main()
{
    queue *coada=newqueue();
    coada->size=0;
    coada->head=0;
    coada->tail=0;
    enqueue(coada,1);
    enqueue(coada,2);
    enqueue(coada,3);
    enqueue(coada,4);
    enqueue(coada,5);
    dequeue(coada);
    dequeue(coada);
    afisareQ(coada);
    printf("\Lungimea cozii: %d",coada->size);
    return 0;
}
