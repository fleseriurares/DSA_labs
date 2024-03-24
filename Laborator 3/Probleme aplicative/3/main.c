#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10

int *new_queue()
{
    int *a=(int *)malloc(CAPACITY * sizeof(int));
    return a;
}

void insert_last(int *queue,int *tail,int head,int val)
{

    if(((*tail)!=head || (*tail==0 && head==0)) && (*tail)<CAPACITY)
    {
        queue[(*tail)]=val;
        (*tail)++;
    }
    else if(*tail==CAPACITY && head!=0)
    {
        *tail=0;
        if(*tail<head)
        {
            queue[*tail-1]=val;
            (*tail)++;
        }
        else
        {
            printf("COADA ESTE PLINA!");
        }
    }
    else
    {
        printf("COADA ESTE PLINA!");
    }

}

void insert_first(int *coada,int *head,int *tail,int val)
{
    if( *tail==0 && *head==0)
    {
        coada[(*tail)]=val;
        (*tail)++;
    }
    else if(*head!=0 && *tail!=*head)
    {
        (*head)--;
        coada[*head]=val;
    }
    else if(*head==0)
    {

        (*head)=CAPACITY-1;
        coada[*head]=val;
    }
    else
    {
        printf("COADA ESTE PLINA.");
    }
}




void delete_first(int *coada, int *head, int tail)
{
    if(*head!=CAPACITY-1)
        (*head)=*head+1;
    else
        (*head)=0;
}

void delete_last(int *coada, int head, int *tail)
{
    if(tail!=0)
    {
        (*tail)=*tail-1;
    }
    else
    {
        *tail=CAPACITY;
    }
}
void afisare(int *coada,int head,int tail)
{
    printf("Coada este:");
    if(tail<=head)
    {
        for(int i=head; i<CAPACITY; i++)
        {
            printf("%d ",coada[i]);
        }
        for(int i=0; i<tail; i++)
        {
            printf("%d ",coada[i]);
        }
    }
    else
    {
        for(int i=head; i<tail; i++)
        {
            printf("%d ",coada[i]);
        }
    }
}
int main()
{
    int *coada=new_queue();
    int head=0,tail=0;
    insert_first(coada,&head,&tail,100);
    insert_first(coada,&head,&tail,200);
    insert_first(coada,&head,&tail,300);
    insert_first(coada,&head,&tail,400);
    insert_first(coada,&head,&tail,500);
    insert_first(coada,&head,&tail,600);
    insert_first(coada,&head,&tail,700);
    insert_first(coada,&head,&tail,800);
    insert_first(coada,&head,&tail,900);
    insert_first(coada,&head,&tail,1000);

    afisare(coada,head,tail);

    return 0;
}
