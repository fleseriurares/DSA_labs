#include <stdio.h>
#include <stdlib.h>
#define M 7
typedef struct _node{
    int key;
    int status;
}nodeT;


enum {FREE,OCCUPIED};

int h0(int x)
{
    return x%M;
}

int linear_probing(int k,int m,int i)
{
    return (h0(k)+i)%m;
}

int h_prime1(int k)
{
    return k%M;
}

int h_prime2(int k)
{
    return 5-k%5;
}

int quadric_probing(int k,int m,int i)
{
    return (h_prime1(k)+i+i*i)%m;
}

int double_hashing(int k,int m,int i)
{
    return (h_prime1(k)+h_prime2(k) * i)%m;
}

void insert_key(nodeT *htable,int k,int m, int (*hfunc)(int k,int m,int i))
{       int i=0;

        int ct=0;
        while(ct<M)
        {int a=hfunc(k,m,i);
            if(htable[a].status==FREE)
            {
                htable[a].key=k;
                htable[a].status=OCCUPIED;
                ct=M+1;
            }
            else
            {
                i++;
            }
            ct++;
        }
}

void set_free(nodeT *htable[M])
{
    for(int i=0;i<M;i++)
    {
        htable[M]=FREE;
    }
}

void print(nodeT *htable)
{
    for(int i=0;i<M;i++)
    {
        printf(" %d: ",i);
        if(htable[i].status==OCCUPIED)
        {
            printf("%d",htable[i].key);
        }
        else
            printf("--");
        printf("\n");
    }
}

int main()
{
    nodeT htable[M];
    set_free(htable);
    insert_key(htable,2,M,double_hashing);
    insert_key(htable,7,M,double_hashing);
    insert_key(htable,14,M,double_hashing);
    insert_key(htable,10,M,double_hashing);
    insert_key(htable,23,M,double_hashing);
    insert_key(htable,25,M,double_hashing);

    print(htable);
    return 0;
}
