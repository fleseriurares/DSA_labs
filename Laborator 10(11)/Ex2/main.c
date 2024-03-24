#include<stdio.h>
#define LIMIT 100001


int n,a[LIMIT],Min[LIMIT]={LIMIT},s;
//b reprezinta spatiul solutiilor partiale
int b[LIMIT]={0},maxi;
FILE * out;
void read();
void write();
void scmax();
int recurs(int maxi,int q);


void read()
{
    FILE * pFile;
    int i;

    pFile = fopen ("fisier.txt","r+");
    fscanf (pFile, "%d", &n);
    fscanf (pFile, "%d", &s);
    for( i = 1; i <= n; i++)
        fscanf (pFile, "%d", &a[i]);

    fclose (pFile);
}

void write()
{
    out = fopen ("CALEA CATRE FISIERUL VOSTRU OUT","w+");
    //maxi reprezinta lungimea maxima
    fprintf(out,"%d",maxi);
            printf("%d ",maxi);
    //TO Do
    //decomentati linia de mai jos pentru a afisa recursiv sirul
    recurs(maxi,n);
    fclose(out);
}
int searchbsol(int k)
{
    //TO DO
    //CODUL VOSTRU TREBUIE INTRODUS AICI
    /*SETEAZA Min[i] LA INFINIT pentru toti i
    Min[0] = 0
    For i = 1 la S
    For j = 0 la N -1
    Daca (Vj <= i AND Min[i-Vj] + 1 < Min[i]) Atunci
    Min[i] = Min[i - Vj] + 1
    Output Min[S]*/
    Min[0]=0;
    for(int i=1; i<=s; i++)
    {
        for(int j=0; j<n; j++)
        {
            b[i] += b[i - b[j]];
            if(b[j]<=i && Min[i-b[j]]+1<Min[i])
                Min[i]=Min[i-b[j]]+1;
        }
    }
    return 0;
}
void scmax()
{
    for(int i = 2; i <= n; i++)
    {
        b[i] = searchbsol(i);
        if(b[i] > maxi)
            maxi = b[i];
    }
}
int recurs(int maxi,int q)
{
    if(q == 0)return 0;
    else if(b[q] == maxi)
    {
        recurs(maxi-1,q-1);
        printf("%d ",a[q]);
        fprintf (out, "%d",a[q]);
    }
    else recurs(maxi,q-1);
}
int main()
{

    read();
    maxi = 1;
    b[1] = 1;
    scmax();
    write();

    return 0;
}
