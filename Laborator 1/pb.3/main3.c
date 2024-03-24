#include <stdio.h>
#include <stdlib.h>
/**
3. Se citesc de la tastatura 2 numere, CAPACITY si SIZE. Sa se aloce dinamic un sir de CAPACITY elemente
reale. Sa se scrie o functie care adauga un element in sir, pe prima pozitie a sirului (cea cu indicele 0).
Folosind functia creata sa se insereze in sir SIZE numere. Ce se intampla daca CAP ACIT Y ≥ SIZE si
daca CAP ACIT Y < SIZE. Afisati sirul de numere dupa fiecare inserare.
*/

void adaugare(float *a,int n)
{int i;
    for(i=n;i>0;i--)
    {
        a[i]=a[i-1];
    }
    scanf("%f",&a[i]);
}

int main()
{
    int CAPACITY, SIZE;
    printf("CAPACITY=");
    scanf("%d",&CAPACITY);
    printf("SIZE=");
    scanf("%d",&SIZE);
    float *a=(float *)calloc(CAPACITY,sizeof(float));
    if(a==NULL)
    {
        printf("NU S-A PUTUT ALOCA MEMORIA.");
        exit(2);
    }
    int k=1;
    float *a2;
    while(SIZE>k*CAPACITY)
    {
        a2=(float*)realloc(a,k*CAPACITY*sizeof(float));
        k++;
    }
a=a2;
    for(int i=0;i<SIZE;i++)
    {
        adaugare(a,i);
        for(int j=0;j<=i;j++)
            printf("%.2f ",a[j]);
        printf("\n");
    }
free(a2);
return 0;
}
