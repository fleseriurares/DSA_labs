#include <stdio.h>
#include <stdlib.h>
#define M 7
typedef struct cell
{
    int key;
    int status;
} Cell;

enum { FREE, OCCUPIED };



void afisare(Cell *T, int m)
{
    printf("\n\nTabela de dispersie este \n");
    for (int i = 0; i < m; i++)
    {
        if(T[i].status == OCCUPIED)
            printf("T[%d]=%d\n",i,T[i]);
        else
            printf("T[%d]= --\n",i);
    }
}

int h_prime(int k, int m)
{
     return k%m;
    return 0; //schimbati in formula
}


int h_prime2(int k, int m){
    return 5 - (k%5);
}
int h0(int k)
{   if(k<0)
    return M-abs(k%M);
    return k%M;

}
int search_key(int k, Cell* T, int m,int i, int (*hash_func)(int k, int m, int i)){
   int a=hash_func(k,m,i);
    if(T[a].status==FREE || i>=m)
    {
        return -1;
    }
    else
    {
        if(T[a].key==k)
            return a;
        else
            return search_key(k,T,m,i+1,hash_func);
    }
   return 0; //-1 in cazul in care nu se gaseste, altfel pozitia
}
void insert_key(int k, Cell *T, int m, int i,int (*hash_func)(int k, int m, int i))
{
    int a=hash_func(k,m,i);
    if(T[a].status==FREE)
    {
        T[a].key=k;
        T[a].status=OCCUPIED;
    }
    else if(i<m)
    {
      insert_key(k,T,m,i+1,hash_func);
    }
    else
        printf("Tabelul e plin!");
    //insereaza pe prima pozitie libera potrivit hash_func-ului sau afiseaza ca tabela e plina
}
int linear_probing(int k, int m, int i)
{
    return (h0(k)+i)%m;
}

int quadratic_probing(int k, int m, int i)
{
    return (h_prime(k,m)+i+i*i)%m;
}

int double_hashing(int k, int m, int i)
{   return (h_prime(k,m)+i*h_prime2(k,m))%m;
}

void set_table_free(Cell *T, int m)
{
    //initializam tabela
    int i;
    for (i = 0; i<m; i++)
    {
        T[i].status = FREE;
    }
}

int main()
{
    int m = 7;
    Cell *T = (Cell*) malloc(m*sizeof(Cell)); //tabela de dispersie - se aloca

    //test linear probing
    set_table_free(T, m);
    int vals[] = {19, 36, 5, 21, 4, 26, 14};
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        insert_key(vals[i], T, m,0, linear_probing);
    afisare(T, m);
    //21, 36, 26, 14, 4, 19, 5

   //test quadratic probing
   set_table_free(T, m);
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        insert_key(vals[i], T, m,0, quadratic_probing);
    afisare(T, m);
    //k + i + i*i mod m: 5, 36, 21, 26, 4, 19, 14

    //test double hashing
    set_table_free(T, m);
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        insert_key(vals[i], T, m,0, double_hashing);
    afisare(T, m);
    //k + i*(5 - k%5) mod m: 21, 36, 26, 5, 4, 19, 14

    //test hash function
    set_table_free(T, m);
    insert_key(-3, T, m,0, linear_probing);
    afisare(T, m);
    // T[4]=-3

 //test cautare
    set_table_free(T, m);
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        insert_key(vals[i], T, m,0, linear_probing);
    afisare(T, m);
      for(int i=0; i<sizeof(vals)/sizeof(int); i++) {
        int pos = search_key(vals[i], T, m,0, linear_probing);
        if (pos != -1){
            printf("cheia %d este pe pozitia %d\n", vals[i], pos);
        }
    }
    int key = -100;
    int pos = search_key(key, T, m,0, linear_probing);
    if (pos != -1){
        printf("cheia %d este pe pozitia %d\n", key, pos);
    }
    else
        printf("cheia %d nu se gaseste in tabela\n", key);

    free(T); /** */
    return 0;
}
