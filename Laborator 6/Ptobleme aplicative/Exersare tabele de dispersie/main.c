#include <stdio.h>
#include <stdlib.h>
#define M 7

typedef struct _cell
{
    int key;
    int status;
} Cell;

enum {FREE,OCCUPIED};

void set_free(Cell *T)
{
    for(int i=0; i<M; i++)
    {
        T[i].status=FREE;
    }
}

int h_prime(int k)
{
    return k%M;
}

int linear_probing(int k,int m,int i)
{
    return (h_prime(k)+i)%m;
}
void insert_tabel(Cell *T,int k,int m,int (*h_func)(int k,int m,int i))
{
    int i=0;
    int a=h_func(k,m,i);
    while(T[a].status==OCCUPIED && i<M)
    {
        i++;
        a=h_func(k,m,i);
    }
    if(i>=M)
        printf("Tabelul de dispersie este plin :(.");
    else
    {
        T[a].key=k;
        T[a].status=OCCUPIED;
    }
}

void print(Cell *T)
{
    for(int i=0; i<M; i++)
    {
        printf(" %d: ",i);
        if(T[i].status==FREE)
            printf("--");
        else
        {
            printf("%d",T[i].key);
        }
        printf("\n");
    }
}

int main()
{
    Cell *T=(Cell *)malloc(M*sizeof(Cell));
    set_free(T);
    insert_tabel(T,2,7,linear_probing);
    insert_tabel(T,3,7,linear_probing);
    insert_tabel(T,8,7,linear_probing);
    insert_tabel(T,24,7,linear_probing);
    insert_tabel(T,36,7,linear_probing);
    insert_tabel(T,21,7,linear_probing);
    print(T);
    return 0;
}
