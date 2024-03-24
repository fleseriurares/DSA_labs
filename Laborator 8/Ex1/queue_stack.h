/// Autor: Totoian Marius-Horatiu
/// Data: 28.04.2023

#ifndef QUEUE_STACK_MODULE_H_
#define QUEUE_STACK_MODULE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue Queue;
typedef struct Stack Stack;

///****************************************
/// Operatii pe coada
///****************************************
Queue* create_queue();

void enqueue(Queue* q, int value);

/// In cazul in care coada este goala se returneaza -1
int dequeue(Queue* q);

bool is_empty_queue(Queue* q);

void clear_queue(Queue* q);

/// In cazul in care coada este goala se va afisa acest mesaj
void print_queue(Queue* q);

///****************************************
/// Operatii pe stiva
///****************************************
Stack* create_stack();

void push(Stack* s, int value);

/// In cazul in care stiva este goala se returneaza -1
int pop(Stack* s);

bool is_empty_stack(Stack* s);

void clear_stack(Stack* s);

/// In cazul in care stiva este goala se va afisa acest mesaj
void print_stack(Stack* s);

#endif // _QUEUE_STACK_MODULE_H_
