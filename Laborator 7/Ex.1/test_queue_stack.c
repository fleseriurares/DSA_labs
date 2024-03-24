#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"  /// Se include head-urul

int main()
{
    printf("Operatii cu Coada\n");
    Queue* q=create_queue();
    enqueue(q, 12);
    enqueue(q, 10);
    enqueue(q, 14);

    print_queue(q);
    dequeue(q);
    dequeue(q);

    print_queue(q);
    dequeue(q);
    print_queue(q);
    enqueue(q,12);
    enqueue(q,100);
    print_queue(q);

    printf("\nOperatii cu Stiva\n");
    Stack* s=create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);

    print_stack(s);
    printf("%d\n", pop(s));
    print_stack(s);
    clear_stack(s);

    print_stack(s);
    push(s, 90);
    push(s, 1000);
    print_stack(s);
    return 0;
}
