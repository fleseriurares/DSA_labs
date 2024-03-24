/// Autor: Totoian Marius-Horatiu
/// Data: 28.04.2023

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_stack.h"

typedef struct NodeT
{
    int key;
    struct NodeT* next;
} NodeT;

struct Queue
{
    NodeT *head, *tail;
};

struct Stack
{
    NodeT* head;
};

Queue* create_queue()
{
    Queue* q= (Queue*)malloc(sizeof(Queue));
    q->head=NULL;
    q->tail=NULL;
    return q;
}

NodeT* create_element(int value)
{
    NodeT* element=(NodeT*)malloc(sizeof(NodeT));
    element->key=value;
    element->next=NULL;
    return element;
}

bool is_empty_queue(Queue* q)
{
    return q->head==NULL;
}

void enqueue(Queue* q, int value)
{///printf("+");
    NodeT* element=create_element(value);
    if(is_empty_queue(q))
    {
        q->head=element;
    }
    else
    {
        q->tail->next=element;
    }
    q->tail=element;
}

int dequeue(Queue* q)
{
    if(is_empty_queue(q))
    {
        return -1;
    }

    int value=q->head->key;
    NodeT* element=q->head;
    q->head=q->head->next;
    free(element);
    return value;
}

void clear_queue(Queue* q)
{
    while(q->head!=NULL)
    {
        NodeT* element=q->head;
        q->head=q->head->next;
        free(element);
    }
}

void print_queue(Queue* q)
{
    if(is_empty_queue(q))
    {
        printf("Coada este goala\n");
    }
    else
    {
        printf("Coada este: ");
        NodeT* element=q->head;
        while(element!=NULL)
        {
            printf("%d ", element->key);
            element=element->next;
        }
        printf("\n");
    }
}

Stack* create_stack()
{
    Stack* s= (Stack*)malloc(sizeof(Stack));
    s->head=NULL;
    return s;
}

bool is_empty_stack(Stack* s)
{
    return s->head==NULL;
}

void push(Stack* s, int value)
{
    NodeT* element=create_element(value);
    if(!is_empty_stack(s))
    {
        element->next=s->head;
    }
    s->head=element;
};

int pop(Stack* s)
{
    if(is_empty_stack(s))
    {
        return -1;
    }

    int value=s->head->key;
    NodeT* element=s->head;
    s->head=s->head->next;
    free(element);
    return value;
}

void clear_stack(Stack* s)
{
    while(s->head!=NULL)
    {
        NodeT* element=s->head;
        s->head=s->head->next;
        free(element);
    }
}

void print_stack(Stack* s){
    if(is_empty_stack(s))
    {
        printf("Stiva este goala\n");
    }
    else
    {
        printf("Stiva este: ");
        NodeT* element=s->head;
        while(element!=NULL)
        {
            printf("%d ", element->key);
            element=element->next;
        }
        printf("\n");
    }
}
