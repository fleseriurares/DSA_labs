#include <stdio.h>
#include <stdlib.h>

/*****************************************************
  Citirea datelor despre un graf dintr-un fisier
  cu reprezentarea grafului prin liste de adiacenta dinamice.
  In fisier se da numarul n de varfuri ale grafului,
  apoi muchiile sub forma de perechi i j, cu 0<=i,j<n
  (i si j reprezinta indicii varfurilor conectate prin
   arc (sau muchie)).
  Graful se parcurge BFS si se scriu într-un fisier
  nodurile în ordinea parcurgerii.
******************************************************/

typedef struct nod
{
    int v;
    struct nod* next;
} NodeT;

struct Queue
{
    NodeT *head, *tail;
};

typedef struct
{
    int n;      // numar de varfuri
    NodeT* *t;    // tabloul de liste (va fi alocat dinamic)
} Graf;     // structura pentru memorarea grafului prin liste de adiacenta dinamice

enum { NEVIZITAT, VIZITAT };

/// TODO: de definit o structura Coada si
/// operatiile initializeaza, enqueue, dequeue, goala

void printErr()
{
    printf("Memorie insuficienta!\n");
    exit(1);
}

void bfs( Graf G, int nodSursa,FILE *f )
{
    int* vizitate; /* pentru marcarea nodurilor vizitate */
    vizitate = calloc(G.n, sizeof(int));
    if (vizitate == NULL) printErr();

///	Coada Q; /* coada nodurilor - intregi */
    struct Queue *q=create_queue();
    int i, v, w; /* noduri */

///	initializeaza( Q );
    for ( i = 0; i < G.n; i++ ) /* marcam toate nodurile ca nevizitate */
        vizitate[ i ] = NEVIZITAT;
    vizitate[ nodSursa ] = VIZITAT; /* marcam nodul sursa ca vizitat */
    /*	procesam informatia pt nodSursa;*/
    enqueue( q,nodSursa );
    // nodSursa va fi primul nod scos din coada
    while(q->head!=NULL)
    {
       int v=deque(q);
       NodeT *p=G.t[v];

       while(p!=NULL)
       {
           if(vizitate[p->val]=NEVIZITAT)
           {

                vizitate[ p->v ] = VIZITAT;
                enqueue( q,p->v);

           }
           p=p->next;
       }
       /** v = dequeue( q );
        fprintf(f,"%d ",v);
        NodeT *p=G.t[v];
        while(p!=NULL)
        {
            if ( vizitate[p->v] == NEVIZITAT )
            {
                vizitate[ p->v ] = VIZITAT;

                enqueue( q,p->v);
            }
            p=p->next;
        }*/
    }
}



void citesteGraf(FILE* f, Graf* pG)
{
    fscanf(f, "%d", &pG->n);    // citeste nr. de varfuri

    // Alocam dinamic tabloul de liste de adiacenta de dimensiune n:
    pG->t = calloc(pG->n, sizeof(NodeT*));
    if (pG->t == NULL) printErr();  // alocare esuata

    int i;
    for (i=0; i<pG->n; i++)
    {
        // initializam (liste vide)
        pG->t[i] = NULL;
    }

    int v, w;
    // citeste pe rand perechi (v, w) si memoreaza arcul/muchia in listele de adiacenta:
    while (fscanf(f, "%d%d", &v, &w) == 2)
    {
        /// printf("%d - %d\n",v,w);
        if(pG->t[v]==NULL)
        {
            NodeT *p=(NodeT *)malloc (sizeof(NodeT));
            p->next=NULL;
            p->v=w;
            pG->t[v]=p;
        }
        else
        {
            NodeT *p=pG->t[v];
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=(NodeT *)malloc (sizeof(NodeT));
            p->next->v=w;
            p->next->next=NULL;
        }
        /// TODO: memoreaza arcul/muchia in listele de adiacenta
    }
}

void afisare_totala(NodeT **t,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d: ",i);
        while(t[i]!=NULL)
        {
            printf("%d ",t[i]->v);
            t[i]=t[i]->next;
        }
        printf("\n");
    }
}

int main()
{
    FILE* f = fopen("graf2.txt", "r");
    if (f == NULL)
    {
        perror("graf2.txt");
        exit(1);
    }
    Graf G;
    citesteGraf(f, &G);
    fclose(f);
    FILE *out=fopen("grafout.txt","w");
///   afisare_totala(G.t,G.n);
    int v;
    printf("Numarul de noduri: %d. \nDati nodul sursa: ", G.n);
    scanf("%d", &v);

    bfs(G, v,out);;
    fclose(out);

    return 0;
}
