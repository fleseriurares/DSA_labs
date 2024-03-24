#include <stdio.h>
#include <stdlib.h>
/**
2.Implementati operatiile fundamentale pe stiva (void push(int *stack, int *top, int key) si (int pop(int *stack, int
*top) ), utilizand un vector ca si structura de baza.

*/

int *new_stack(int n)
{
   int *stack=(int*)malloc(n*sizeof(int));
    if(stack==NULL)
    {
        printf("Nu s-a putut aloca memorie");
        exit(2);
    }
    return stack;
}
void push(int *stack, int *top, int key)
{
    stack[*top]=key;
    (*top)++;
}
void pop(int *stack, int *top)
{   if(top!=0)
    (*top)--;
}

void afisare(int *stack, int top)
{   printf("Stiva este:\n");
    for(int i=top-1;i>=0;i--)
        printf("%d\n",stack[i]);
}
int main()
{
    int *stiva=new_stack(10),top=0;
    push(stiva,&top,10);
    push(stiva,&top,2);
    push(stiva,&top,3);
    pop(stiva,&top);
    push(stiva,&top,22);
    push(stiva,&top,19);
    afisare(stiva,top);
    return 0;
}
