#include <stdio.h>
#include <stdlib.h>
/**
Ex. 1 — Implementati operatiile fundamentale pe stiva – void push(NodeT** stack, int key) si NodeT*
pop(NodeT** stack), utilizand lista simplu inlantuita ca si structura de baza. Totodata, implementati o
functie de initializare a stivei, si una de afisare a elementelor acesteia. Testati operatiile implementate.
*/

typedef struct node
{
    int val;
    struct node *next;
} nodeT;

nodeT *newnod(int a)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->val=a;
    return p;

}

void push(nodeT** stack, int key)
{
    if(stack==NULL)
    {
        (*stack)=newnod(key);
    }
    else
    {
        nodeT *p=newnod(key);
        p->next=*stack;
        (*stack)=p;
    }
}

nodeT *pop(nodeT** stack)
{   if((*stack)==NULL)
        return -1;
    nodeT *p=*stack;
    *stack=(*stack)->next;
    p->next=NULL;
    return p;
}

void afisareS(nodeT *stack)
{
    while(stack->next!=NULL)
    {
        printf("%d\n",stack->val);
        stack=stack->next;
    }
    printf("%d",stack->val);
    stack=stack->next;
}
void afisareL(nodeT *stack)
{
    while(stack->next!=NULL)
    {
        printf("%d ",stack->val);
        stack=stack->next;
    }
    printf("%d",stack->val);
    stack=stack->next;
}
int main()
{
    nodeT *stack=NULL;
    nodeT *last=NULL;
    push(&stack,1);
    push(&stack,3);
    push(&stack,10);
    push(&stack,15);
    afisareS(stack);
    nodeT* p=pop(&stack);
    printf("\nValoarea dupa pop a lui p este : %d,iar noua lista:\n",p->val);
    afisareS(stack);
    return 0;
}
