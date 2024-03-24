#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int s,n, monede[MAX], Min[MAX + 1]={MAX},cantitate;
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
    ///combinatii[0]=1;
    for(i = 0; i < n; i++)
        scanf("%d",&monede[i]);
}
void DP()
{

for(int i=0;i<=s;i++)
{
    Min[i]=MAX;
}
Min[0]=0;
   for(int i=1;i<=s;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(monede[j]<=i && Min[i-monede[j]]+1<Min[i])
           {
               Min[i]=Min[i-monede[j]]+1;
           }
       }
   }
    //TO DO
    //Your code goes here
}
void write()
{
    printf("%d \n", Min[s]);
    for(int i = 0; i <= s; i++)
        printf("%d ", Min[i]);
}

int main()
{
    printf("%d",Min[2]);
    read();
    DP();
    write();
    return 0;
}
