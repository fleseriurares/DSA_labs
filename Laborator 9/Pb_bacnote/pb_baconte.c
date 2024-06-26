#include <stdio.h>
#include <stdlib.h>

int solNb=0; /* solution number */
int numar_bacnote=0;
enum { FALSE, TRUE };

int optim[100]= {1};
int nr_coins_optim=100;

void construct_candidates(int c[], int *ncandidates, int change)
{
    if(change >0)
    {
        c[0] = 1; /* consider the current coin */
        c[1] = 0; /* do not consider the current coin */
        *ncandidates = 2; /* total number of possibilities is 2 (consider/not consider) */
    }
    else
        *ncandidates = 0; /* no candidates */
}

int is_a_solution(int change)
{
    return (change == 0); /* is a solution when change is 0 */
}

void backtrack(int a[], int k, int n, int change, int values[])
{
    int c[2]; /* candidates for next position */
    int ncandidates; /* next position candidate count */
    int i;

    if(k == n) /* all the coins were explored! */
        return;

    if (is_a_solution(change))
    {

        //must process solution
        int nr_bacnote=0;

        for(int i=0; i<n; i++)
        {
            if(a[i]==1)
                {nr_bacnote++;}
        }
       /// printf("%d - > %d\n",nr_coins_optim,nr_bacnote);
        if(nr_coins_optim>nr_bacnote)
        {
            printf("Found solution %d:\n", ++solNb);
            nr_coins_optim=nr_bacnote;

            for(int i=0; i<n; i++)
            {
                printf("%d ", a[i]*values[i]);
                optim[i]=a[i]*values[i];
            }

    printf("\n");
    }
    }
    else
    {
        k = k + 1;
        construct_candidates(c,&ncandidates,change);
        for (i=0; i<ncandidates; i++)
        {
            a[k] = c[i];
            backtrack(a,k,n,change-a[k]*values[k], values);
        }
    }

}


int main()
{
    int n, change;
    int* values = NULL;
    int* a = NULL;
    printf("Number of coins=");
    scanf( "%d", &n );
    printf("Change to be returned=");
    scanf( "%d", &change );
    printf("Input coin values:\n");
    values = (int*)malloc(n*sizeof(int));
    a=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        a[i] = values[i] = 0;
    }
    for(int i=0; i<n; i++)
        scanf("%d", values+i);

    backtrack(a, -1, n, change, values);
    printf("Solutie optima:\n");
    for(int i=0;i<n;i++)
        printf("%d ",optim[i]);
    printf( "\nEnd.\n" );
    return 0;
}

