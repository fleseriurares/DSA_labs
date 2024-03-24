#include <stdio.h>
#include <stdlib.h>

/**
2. Se citesc de la tastatura 2 numere, CAPACITY si SIZE. Sa se aloce dinamic un sir care poate sa contina
CAPACITY elemente reale. Sa se scrie o functie care adauga un element in sir, pe ultima pozitie a sirului.
Folosind functia creata sa se insereze in sir SIZE numere. Ce se intampla daca CAPACITY ≥ SIZE si
daca CAPACITY < SIZE. Afisati sirul de numere dupa fiecare operatie de inserare.
*/
void adaugare(float *a,int i)
{
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
//free(a);
    return 0;
}
