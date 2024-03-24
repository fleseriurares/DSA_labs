#include <stdio.h>
#include <stdlib.h>
/**
5. Operatii cu polinoame: sa se conceapa o structura dinamica eficienta pentru reprezentarea în memorie a polinoamelor.
 Se vor scrie functii de calcul a sumei, diferentei si produsului a doua polinoame. .
I/O description. Intrare:
p1=3x^7+5x^6+22.5x^5+0.35x-2
p2=0.25x^3+.33x^2-.01
p1+p2
p1-p2
p1*p2
Iesire:
<Afiseaza suma polinoamelor>
<Afiseaza diferenta polinoamelor>
<Afiseaza produsul polinoamelor>
*/

typedef struct _node
{
    float coef;
    int grad;
    struct _node *next;
} nodeT;

nodeT *newnode(float val,int gr)
{
    nodeT *p=((nodeT *)malloc(sizeof(nodeT)));
    p->next=NULL;
    p->coef=val;
    p->grad=gr;
    return p;
}

void insert(nodeT **first,nodeT **last, float val, int gr)
{
    int ind=0;
    nodeT *p=newnode(val,gr);
    nodeT *aux=*first,*prev=*first;
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        if(aux->next==NULL)
        {
            if(p->grad>aux->grad)
            {
                p->next=*first;
                *first=p;
            }
            else if (!(p->grad>aux->grad))
            {
                (*first)->next=p;
                *last=p;
            }
            else
            {
                (*first)->coef+=val;
            }
        }
        else
        {
            if(p->grad>aux->grad)
            {
                p->next=*first;
                *first=p;
            }
            else if (p->grad==aux->grad)
            {
                (*first)->coef+=val;
            }
            else
            {
                while(aux->next!=NULL && p->grad<aux->next->grad )
                {
                    prev=aux;
                    aux=aux->next;
                }

                if(aux->next!=NULL && p->grad!=aux->next->grad)
                {
                    p->next=aux->next;
                    aux->next=p;
                }
                else if(aux->next!=NULL)
                {
                    (aux->next)->coef+=val;
                }
                else
                {
                    if(p->grad!=aux)
                    {
                        aux->next=p;
                        *last=p;
                    }
                    else
                    {
                        (aux->next)->coef+=val;
                    }
                }
            }
        }
    }
}

nodeT *suma(nodeT *first1,nodeT *first2)
{
    nodeT *rez,*p;
    if(first1->grad>first2->grad)
    {
        rez=newnode(first1->coef,first1->grad);
        p=rez;
        first1=first1->next;
    }
    else if(first1->grad<first2->grad)
    {
        rez=newnode(first2->coef,first2->grad);
        p=rez;
        first2=first2->next;
    }
    else
    {
        rez=newnode(first2->coef+first1->coef,first2->grad);
        p=rez;
        first2=first2->next;
        first1=first1->next;
    }

    while(first1!=NULL && first2!=NULL)
    {
        if(first1->grad>first2->grad)
        {
            p->next=newnode(first1->coef,first1->grad);
            first1=first1->next;
            p=p->next;
        }
        else if(first1->grad<first2->grad)
        {
            p->next=newnode(first2->coef,first2->grad);
            p=p->next;
            first2=first2->next;
        }
        else
        {
            p->next=newnode(first2->coef+first1->coef,first2->grad);
            p=p->next;
            first2=first2->next;
            first1=first1->next;
        }
    }
    while(first1!=NULL)
    {
        p->next=newnode(first1->coef,first1->grad);
        first1=first1->next;
        p=p->next;
    }
    while(first2!=NULL)
    {
        p->next=newnode(first2->coef,first2->grad);
        first2=first2->next;
        p=p->next;
    }
    return rez;
}

nodeT *inmultire(nodeT *first1,nodeT *first2)
{
    nodeT *rez=NULL,*p1=first1,*p2=first2,*last=NULL;
    while(p1!=NULL)
    {
        while(p2!=NULL)
        {
            insert(&rez,&last,p1->coef*p2->coef,p1->grad+p2->grad);
            p2=p2->next;
        }
        p1=p1->next;
        p2=first2;
    }
    return rez;
}
nodeT *diferenta(nodeT *first1,nodeT *first2)
{
    nodeT *rez,*p;
    if(first1->grad>first2->grad)
    {
        rez=newnode(first1->coef,first1->grad);
        p=rez;
        first1=first1->next;
    }
    else if(first1->grad<first2->grad)
    {
        rez=newnode(first2->coef,first2->grad);
        p=rez;
        first2=first2->next;
    }
    else
    {
        rez=newnode(first2->coef-first1->coef,first2->grad);
        p=rez;
        first2=first2->next;
        first1=first1->next;
    }

    while(first1!=NULL && first2!=NULL)
    {
        if(first1->grad>first2->grad)
        {
            p->next=newnode(first1->coef,first1->grad);
            first1=first1->next;
            p=p->next;
        }
        else if(first1->grad<first2->grad)
        {
            p->next=newnode(first2->coef,first2->grad);
            p=p->next;
            first2=first2->next;
        }
        else
        {
            p->next=newnode(first2->coef-first1->coef,first2->grad);
            p=p->next;
            first2=first2->next;
            first1=first1->next;
        }
    }
    while(first1!=NULL)
    {
        p->next=newnode(first1->coef,first1->grad);
        first1=first1->next;
        p=p->next;
    }
    while(first2!=NULL)
    {
        p->next=newnode(first2->coef,first2->grad);
        first2=first2->next;
        p=p->next;
    }
    return rez;
}


void afisare(nodeT *first)
{
    printf("polinomul:  ");
    while(first->next!=NULL)
    {
        printf("%.1f*x^%d + ",first->coef,first->grad);
        first=first->next;
    }
    printf("%.1f*x^%d",first->coef,first->grad);

}

int main()
{
    nodeT *first1=NULL,*last1=NULL,*first2=NULL,*last2=NULL;
    insert(&first1,&last1,2,5);
    insert(&first1,&last1,1,7);
    insert(&first1,&last1,2,4);
    insert(&first2,&last2,2.5,6);
    insert(&first2,&last2,4,8);
    insert(&first2,&last2,2,9);
    ///nodeT *rez=suma(first1,first2);
    nodeT *rez=inmultire(first1,first2);
    afisare(rez);
    return 0;
}
