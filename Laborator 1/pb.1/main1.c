#include <stdio.h>
#include <stdlib.h>
/**
1. Sa se citeasca dintr-un fisier text date despre studenti: in fisier se da pe prima linie numarul de studenti
(n), apoi pe urmatoarele n linii numele studentului, prenumele, varsta urmate de notele la primele 3
laboratoare la SDA. Exemplu de fisier:
5
Pop Ana 21 10 9 8
Costea Andrei 20 7 8 5
Butnaru Dan 21 9 5 7
Chis Maria 20 8 10 9
Vlaicu Robert 21 10 9 5
- Sa se creeze o structura care sa permita stocarea studentilor.
- Sa se aloce dinamic un sir de studenti.
- Sa se afiseze sirul de studenti citit.
- Sa se parcurga sirul de studenti si sa se calculeze media celor 3 note ale fiecarui student. Sa se afiseze
apoi sirul de studenti si media fiecaruia. Sugestie: creati un camp medie in structura Student de la
punctul 2.
- Pentru fiecare student sa se incrementeze toate notele cu 1. Sa se afiseze studentii si notele lor
modificate
*/

typedef struct _studenti{
char nume[10];
char prenume[10];
int varsta;
int note[3];
float medie;
} STUDENT;

int main()
{
    FILE *f=fopen("student.txt","r");
    int n;
    fscanf(f,"%d",&n);
    STUDENT *s=(struct _studenti*)calloc(n,sizeof(struct _studenti));
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%s",&(s[i].nume));
        fscanf(f,"%s",&(s[i].prenume));
        fscanf(f,"%d",&(s[i].varsta));
        fscanf(f,"%d",&(s[i].note[0]));
        fscanf(f,"%d",&(s[i].note[1]));
        fscanf(f,"%d",&(s[i].note[2]));
        s[i].medie=(s[i].note[0]+s[i].note[1]+s[i].note[2])/3.0;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d. %s %s %d %d %d %d; media:%.2f\n",i+1,s[i].nume,s[i].prenume,s[i].varsta,s[i].note[0],s[i].note[1],s[i].note[2],s[i].medie);
    }
    for(int i=0;i<n;i++)
    {
       s[i].note[0]++;
       s[i].note[1]++;
       s[i].note[2]++;
    }
    printf("DUPA MODIFICAREA NOTELOR:\n");
     for(int i=0;i<n;i++)
    {
        printf("%d. %s %s %d %d %d\n",i+1,s[i].nume,s[i].prenume,s[i].note[0],s[i].note[1],s[i].note[2]);
    }
    fclose(f);
    return 0;
}
