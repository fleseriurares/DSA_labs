#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int s,n, monede[MAX], combinatii[MAX + 1],cantitate,Min[100];
void read();
void DP();
void write();

void read()
{
    int i;
    printf("n=");
    scanf("%d",&n);
    printf("s=");
    scanf("%d",&s);
    combinatii[0]=1;
    for(i = 0; i < n; i++)
        scanf("%d",&monede[i]);
}
void DP()
{
   for(int i=1;i<=s;i++)
   {
       Min[i]=10000;
   }
   Min[0]=0;
   ///int i=1;i<=s;i++
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<=s;i++)
        {
            if(monede[j]<i && Min[i-monede[j]]+1<Min[i])
            {
                Min[i]=Min[i-monede[j]]+1;
            }
        }
    }
    printf("Min=%d\n",Min[s]);
    //TO DO
    //Your code goes here
    //TO DO
    //Your code goes here
}
void write()
{
    printf("%d \n", combinatii[s]);
    for(int i = 0; i <= s; i++)
        printf("%d ", combinatii[i]);
}

int main()
{
    read();
    DP();
    write();
    return 0;
}
