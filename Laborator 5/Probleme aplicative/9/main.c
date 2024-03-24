#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int key;
    struct _node *left;
    struct _node *right;
} nodeT;

nodeT *newnode(int val)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->left=NULL;
    p->right=NULL;
    p->key=val;
}
nodeT *insert(nodeT **arbore,int val)
{
    if(*arbore==NULL)
    {
        *arbore=newnode(val);
        return arbore;
    }
    else if(val<(*arbore)->key)
        return insert(&((*arbore)->left),val);
    return insert(&((*arbore)->right),val);
}

int verif_oglinda(nodeT *arbore1,nodeT *arbore2)
{
    if(arbore1==NULL && arbore2==NULL)
        return 1;
    if((arbore1==NULL && arbore2!=NULL) || (arbore1!=NULL && arbore2==NULL) )
        return -1;
    if(arbore1->key!=arbore2->key)
        return -1;

    return verif_oglinda(arbore1->left,arbore2->right);
    return verif_oglinda(arbore1->right,arbore2->left);
}

nodeT* oglindire_arbore(nodeT *arbore)
{
    if(arbore!=NULL)
    {
        nodeT *p=newnode(arbore->key);
        p->right=oglindire_arbore(arbore->left);
        p->left=oglindire_arbore(arbore->right);
        return p;
    }
    return NULL;
}
///10 INTERCLASARE:

nodeT *interclas(nodeT *arbore1,nodeT *arbore2)
{
    nodeT *p=newnode(arbore1->key);
    if(arbore2->key<p->key)
    {
        p->left=1;
    }
}

///11 GASIRE DRUM

nodeT *search(nodeT *arbore,int val)
{
    if(arbore==NULL)
        return arbore;
    if(arbore->key==val)
        return arbore;
    if(val<arbore->key)
    {
        return search(arbore->left,val);
    }
    return search(arbore->right,val);
}

nodeT *rad_min(nodeT *arbore,nodeT *p1,nodeT *p2)
{
    if(search(arbore->left,p1->key)!=NULL && search(arbore->left,p2->key)!=NULL)
        return rad_min(arbore->left,p1,p2);
    if(search(arbore->right,p1->key) && search(arbore->right,p2->key))
        return rad_min(arbore->right,p1,p2);
    ///if((search(arbore->right,p1->key) && search(arbore->left,p2->key)) || (search(arbore->left,p1->key) && search(arbore->right,p2->key)))
    ///  if(search(arbore,p1)==NULL || search(arbore,p2)==NULL)
    ///   return NULL;
    return arbore;
}

void afisare_rad_nod(nodeT* arbore,int val)
{
    if(search(arbore,val)==NULL)
    {
        printf("error");
    }
    else
    {
        if(val<arbore->key)
        {
            afisare_rad_nod(arbore->left,val);
        }
        else if(val>arbore->key)
        {
            afisare_rad_nod(arbore->right,val);
        }
        printf("%d  ",arbore->key);
    }
}
void afisare_nod_rad(nodeT* arbore,int val)
{
    if(search(arbore,val)==NULL)
    {
        printf("error");
    }
    else
    {
        printf("%d  ",arbore->key);
        if(val<arbore->key)
        {
            afisare_rad_nod(arbore->left,val);
        }
        else if(val>arbore->key)
        {
            afisare_rad_nod(arbore->right,val);
        }

    }
}

void drum(nodeT* arbore,int val1,int val2)
{
    nodeT *rad=rad_min(arbore,search(arbore,val1),search(arbore,val2));
    if(rad==NULL)
    {
        printf("Nu exista nodurile!");
    }
    afisare_rad_nod(rad,val1);
    afisare_nod_rad(rad->right,val2);
}

nodeT *findMin(nodeT *arbore)
{
    if(arbore->left!=NULL)
    {
        return arbore->left;
    }
    return arbore;
}
nodeT *delete_node(nodeT *arbore, int val)
{
    if(search(arbore,val)==NULL)
    {
        return arbore;
    }else
    {
    if(val<arbore->key)
    {
        arbore->left=delete_node(arbore->left,val);
    }
    else if(val>arbore->key)
    {
        arbore->right=delete_node(arbore->right,val);
    }
    else
    {
        if(arbore->left==NULL)
        {
            nodeT *p=arbore;
            arbore=arbore->right;
           free(p);
            return arbore;
        }
        if(arbore->right==NULL)
        {
            nodeT *p=arbore;
            arbore=arbore->left;
            free(p);
            return arbore;
        }
        nodeT *p=findMin(arbore->right);
        arbore->key=p->key;
        arbore->right=delete_node(arbore->right,p->key);
    }
    return arbore;
}}

void preordine(nodeT *arbore)
{
    if(arbore!=NULL)
    {
        printf("%d ",arbore->key);
        preordine(arbore->left);
        preordine(arbore->right);
    }
}

void preordine_nice(nodeT *arbore,int niv)
{
    if(arbore!=NULL)
    {
        for(int i=0; i<niv; i++)
        {
            printf("   ");
        }
        printf("%d\n ",arbore->key);
        preordine_nice(arbore->left,niv+1);
        preordine_nice(arbore->right,niv+1);
    }
}
int main()
{
    nodeT *arbore=NULL, *arbore2=NULL;
    insert(&arbore,6);
    insert(&arbore,2);
    insert(&arbore,3);
    insert(&arbore,10);
    insert(&arbore,8);
    insert(&arbore,12);
    insert(&arbore,7);
    nodeT *p1=search(arbore,7);
    nodeT *p2=search(arbore,12);
    nodeT *rad=rad_min(arbore,p1,p2);
    delete_node(arbore,10);
    ///printf("%d",rad->key);
    ///drum(arbore,7,12);
    ///nodeT *oglindit=oglindire_arbore(arbore);
    ///preordine(oglindit);
    ///printf("%d",verif_oglinda(arbore,oglindit));
 preordine_nice(arbore,0);
    return 0;
}
