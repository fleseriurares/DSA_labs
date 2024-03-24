#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NDEBUG
int sir[100];
void merge_sort(int *a, int p, int q)
{

    if(p<q)
    {
        int    m=(p+q)/2;
        merge_sort(a,p,m);
        merge_sort(a,m+1,q);

        int i=p,j=m+1,k=0;
        while(i<=m && j<=q)
        {
            if(a[i]<a[j])
            {
                sir[++k]=a[i++];
                //   i++;
                //   k++;
            }
            else
            {
                sir[++k]=a[j++];
                //  j++;
                //    k++;
            }
        }
        while(i<=m)
        {
            sir[++k]=a[i++];
            // k++;
            // i++;
        }
        while(j<=q)
        {
            sir[++k]=a[j++];
            // k++;
            // j++;
        }
        for(int i=p,j=1; i<=q; i++,j++)
        {
            a[i]=sir[j];
        }

    }
}

int main()
{
    int numbers[] = {4, 9, 3, 1, 5, 7, 8, 6, 2};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = (int) (sizeof(numbers) / sizeof(int));
    merge_sort(numbers, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        assert(numbers[i] == expected[i]);
    }
    return 0;
}
