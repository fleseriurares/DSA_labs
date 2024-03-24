#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int s,n, monede[MAX], combinatii[MAX + 1],cantitate;
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
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<=s; i++)
        {
            if(i >= monede[j])
            {///printf("ok");
                combinatii[i] += combinatii[i - monede[j]];
            }
        }
    }
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
