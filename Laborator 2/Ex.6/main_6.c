#include <stdio.h>
#include <stdlib.h>

void insert_last(int *a,int *size,int val)
{
    a[*size]=val;
    (*size)++;
}

void insert_first(int *a,int *size,int val)
{
    for(int i=*size; i>0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=val;
    (*size)++;
}

int *search(int *a,int size,int val)
{
    for(int i=0; i<size; i++)
    {
        if(a[i]==val)
            return a+i;
    }
    printf("Nu s-a gasit elementul %d\n",val);
}

void delete_last(int *a,int *size)
{
    if(*size!=0)
        (*size)--;
}

void delete_first(int *a,int *size)
{
    for(int i=0; i<*size-1; i++)
    {
        a[i]=a[i+1];
    }
    (*size)--;
}

void delete_key(int *a,int *size, int val)
{
    int *p=search(a,*size,val);
    if(p!=NULL)
    {
        for(int i=p-a; i<*size-1; i++)
        {
            a[i]=a[i+1];
        }
        (*size)--;
    }
    else
        printf("\nNu s-a gasit valoarea &d in sir.\n",val);
}
void verif_realloc(int **a,int *capacity,int size)
{
    if(size==*capacity)
    {
        int *ra=(int *)realloc(a,2*(*capacity)*sizeof(int));
        *a=ra;
    }
    if(*a==NULL)
    {
        printf("NU S-A PUTUT REALOCA MEMORIE");
        exit(3);
    }
}
void print(int *a,int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}


int main()
{
    int capacity=10,size=0;
    int *a=(int *)malloc(capacity*sizeof(int));
    if(a==NULL)
    {
        printf("NU S-A PUTUT ALOCA MEMORIA");
        exit(2);
    }
    insert_first(a,&size,5);
    print(a,size);
    verif_realloc(&a,&capacity,size);
    insert_first(a,&size,2);
    print(a,size);
    verif_realloc(&a,&capacity,size);
    insert_first(a,&size,7);
    print(a,size);
    verif_realloc(&a,&capacity,size);
    insert_last(a,&size,12);
    print(a,size);
    verif_realloc(&a,&capacity,size);
    insert_last(a,&size,13);
    print(a,size);
    verif_realloc(&a,&capacity,size);
    if(search(a,size,2)!=NULL)
        printf("\nCheia 2 are indexul: %d\n",search(a,size,2)-a);
    if(search(a,size,20)-a>=0)
        printf("Cheia 20 are indexul: %d\n",search(a,size,20)-a);
    delete_first(a,&size);
    print(a,size);
    delete_key(a,&size,12);
    print(a,size);
    return 0;
}
