#include <stdio.h>
#include <stdlib.h>

///Ex. 1 — Implementati functia NodeT *createBinTreeFromFile(FILE* f) de creare a unui arbore binar folosind
///datele din fisierul ArboreBinar.txt. Scrieti functia main() care apeleaza crearea arborelui.

typedef struct _arbore_binar
{
    int id;
    struct _arbore_binar *left, *right;
} nodeT;

nodeT *createBinTreeFromFile(FILE* f)
{
    nodeT *p;
    int a;
    fscanf(f,"%d",&a);
    if(a==0)
        return NULL;
    p=(nodeT *)malloc(sizeof(nodeT));
    if(p==NULL)
    {
        printf("Nu se poate aloca memorie!");
        exit(1);
    }
    p->id=a;
    p->left=createBinTreeFromFile(f);
    p->right=createBinTreeFromFile(f);
    return p;

}

void preorder(nodeT *r)
{
    if(r!=NULL)
    {
        printf("%d ",r->id);
        preorder(r->left);
        preorder(r->right);
    }
}

void inorder(nodeT *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d ",r->id);
        inorder(r->right);
    }
}

void postorder(nodeT *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->id);
    }
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int noduri_interne(nodeT *node){
if(node!=NULL && (node->left!=NULL || node->right!=NULL))
{
    return 1+noduri_interne(node->left)+noduri_interne(node->right);
}

    return 0;
}

int leaf_node(nodeT *node){

if(node==NULL)
    return 0;
if(node!=NULL && (node->left==NULL && node->right==NULL))
{
    return 1;
}
return leaf_node(node->left)+leaf_node(node->right);
}



///Inaltimea unui arbore:
int inaltime(nodeT *node)
{
    if(node == NULL)
    {
        return -1;
    }
    else
        return 1+max(inaltime(node->left),inaltime(node->right));
}
int main()
{
    FILE  *fisier=fopen("ArboreBinar.txt","r");
    nodeT *r=createBinTreeFromFile(fisier);
    printf("preordine: ");
    preorder(r);
    printf("\ninordine: ");
    inorder(r);
    printf("\npostordine: ");
    postorder(r);
    printf("\ninaltime: %d",inaltime(r));
    printf("\n nr. de noduri interne: %d",noduri_interne(r));
    printf("\n nr. de frunze: %d",leaf_node(r));

    return 0;
}
