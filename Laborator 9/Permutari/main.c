#include <stdio.h>
#include <stdlib.h>

/*      Problema cu permutari   */


void afisare(int n, int *sol, int *vec)
{
    for (int i=1; i<=n; i++)
    {
        printf("%d ", vec[sol[i]]);
    }
    printf("\n");
}

void back(int k, int *vec, int *viz, int *sol, int n)
{
    if (k == n+1)
        afisare(n, sol, vec);
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (!viz[i])
            {
                viz[i] = 1;
                sol[k] = i;
                back(k + 1, vec, viz, sol, n);
                viz[i] = 0;
            }
        }
    }
}

int main ()
{
    int *vec, *viz, *sol, n;
    scanf("%d", &n);
    vec = (int *)malloc((n+1)* sizeof(int));
    viz = (int *)calloc(n+1, sizeof(int));
    sol = (int *)malloc((n+1)* sizeof(int));

    for (int i=1; i<=n; i++)
        scanf("%d", &vec[i]);

    back(1, vec, viz, sol, n);

    return 0;
}
