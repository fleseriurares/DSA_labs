#include <stdio.h>
#include <stdlib.h>
#define M 7 //dimensiunea tabelei de dispersie

typedef struct node
{
    int val;
    struct node *next;
} nodeT;

int hFunction(int key)
{
    return key%M;
}

nodeT *newnode(int key)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->next=NULL;
    p->val=key;
}

void insert(nodeT* hTable[M], int key)
{
    nodeT *p=newnode(key);
    int h=hFunction(key);
    if(hTable[h]!=NULL)
    {
        p->next=hTable[h];
        hTable[h]=p;
    }
    else
    {
        hTable[h]=p;
    }

}


nodeT* search(nodeT* hTable[M], int key){
    int a=hFunction(key);
    nodeT *p=hTable[a];
    while(p!=NULL && p->val!=key)
    {
        p=p->next;
    }
    return p;
    return NULL;
}


void deleteKey(nodeT* hTable[M], int key){

    int a=hFunction(key);
    nodeT *prev;
    nodeT *p=hTable[a];
    if(hTable[a]->val==key)
    {
        prev=hTable[a];
        hTable[a]=hTable[a]->next;
        free(prev);
    }
    else{
    while(p!=NULL && p->val!=key)
    {   prev=p;
        p=p->next;
    }

    if(p==NULL)
    {
        printf("Nu exista nodul de sters\n");
    }
    else
    prev->next=p->next;
}}

//afisarea tuturor elmentelor din tebela de dispersie
void showAll(nodeT* hTable[M])
{
    int i;
    for(i = 0; i < M; i++)
    {
        printf(" %d :",i);
        //verificam daca la slotul i am adaugat ceva
        if(hTable[i] != NULL)
        {

            nodeT *p;
            p = hTable[i];
            while (p != NULL)
            {
                printf(" %d ",p->val);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{

    //initializare
    nodeT* hTable[M];
    for(int i = 0; i < M; i++)
    {
        hTable[i] = NULL;
    }

    //test inserare
    int vals[] = {36, 18, 6, 43, 72, 10, 5, 15,49};
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        {insert(hTable, vals[i]);}
    showAll(hTable);

    nodeT *p=search(hTable,43); printf("!");
    printf("%d\n",p->val);
        // 0:
        // 1: 15 43 36
        // 2: 72
        // 3: 10
        // 4: 18
        // 5: 5
        // 6: 6

        //test stergere
      int todel[] = {43, 36, 10, 61, 5};
        for(int i=0; i<sizeof(todel)/sizeof(int); i++)
           deleteKey(hTable, todel[i]);

        showAll(hTable);

        // 0:
        // 1: 15
        // 2: 72
        // 3:
        // 4: 18
        // 5: 5
        // 6: 6

    return 0;
}
