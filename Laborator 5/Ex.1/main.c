#include <stdio.h>
#include <stdlib.h>

/**
Ex. 1 — Inserarea în arbore a unui nod cu cheia key. Folositi o metoda nerecursiva.
NodeT *insertNode( NodeT *root, int key )
Inserati urmatoarele numere 15, 6, 18, 20, 17, 7, 13, 3, 2, 4, 9 pentru a obtine arborele din figura 5.5.
*/

typedef struct _node
{
    int key;
    struct _node *right;
    struct _node *left;
} nodeT;

nodeT *new_node(int val)
{
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    p->right=NULL;
    p->left=NULL;
    p->key=val;
}

void insert(nodeT **root,int val)
{
    int ind=0;
    nodeT *p=new_node(val);
    nodeT *aux;
    nodeT *r=*root;
    if((*root)==NULL)
    {
        *root=p;
    }
    else
    {
        while(ind==0)
        {
            while( r->left!=NULL && val<r->key)
            {
                r=r->left;
            }
            while( r->right!=NULL && val>r->key)
            {
                r=r->right;
            }
            if(r->left==NULL && val<r->key)
            {
                ind=1;
                r->left=p;
            }
            else if(r->right==NULL && val>r->key)
            {
                ind=1;
                r->right=p;
            }
        }
    }
}

nodeT* findMin(nodeT* root)
{
    if(root->left==NULL)
        return root;
    return findMin(root->left);
}

nodeT* findMax(nodeT* root)
{
    if(root->right==NULL)
        return root;
    return findMax(root->right);
}

nodeT *succesor(nodeT *root,nodeT *node)
{
    if(node->right!=NULL)
    {
        return findMin(node->right);
    }
    else
    {
        if(root->key>node->key)
        {
            nodeT *max=findMax(root->left);
            if(max->key==node->key)
                return root;
            else
                return succesor(root->left,node);
        }
        else if(root->key<node->key)
        {
            nodeT *max=findMax(root->right);
            if(max->key==node->key)
                return root;
            else
                return succesor(root->right,node);
        }
    }
}


nodeT *predecesor(nodeT *root, nodeT *node)
{
    if(node->left!=NULL)
    {
        return findMax(node->left);
    }
    else
    {
        if(root->key>node->key)
        {
            nodeT *min=findMin(root->left);
            if(min->key==node->key)
                return root;
            else
                return predecesor(root->left,node);
        }
        else if(root->key<node->key)
        {
            nodeT *min=findMin(root->right);
            if(min->key==node->key)
                return root;
            else
                return predecesor(root->right,node);
        }
    }
}

void inorder(nodeT *root)
{
    if(root!=NULL)
    {

        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

nodeT *searchkey(nodeT *root,int val)
{
    if(root==NULL || root->key==val)
        return root;
    if(val<root->key)
        return  searchkey(root->left,val);
    return searchkey(root->right,val);
}

nodeT *deleteNode(nodeT *root, int val)
{
nodeT *p=searchkey(root,val);
    if(p==NULL)
        return root;
    else
    {
        if(root->key>val)
        {
            root->left=deleteNode(root->left,val);
        }
        else if(root->key<val)
        {
            root->right=deleteNode(root->right,val);
        }
        else
        {
            if(root->left==NULL)
            {
                p=root->right;
                free(root);
                return p;
            }
            else if(root->right == NULL)
            {
                p=root->left;
                free(root);
                return p;
            }
        p=findMin(root->right);
        root->key=p->key;
        root->right=deleteNode(root->right,p->key);
        }
        return root;
    }
}

void postOrder(nodeT *root,int level)
{
    if(root!=NULL)
    {
        for(int i=0; i<level; i++)
        {
            printf("    ");
        }
        postOrder(root->left,level+1);
        postOrder(root->right,level+1);
        printf("%d\n",root->key);
    }
}

void inOrder(nodeT *root,int level)
{
    if(root!=NULL)
    {
        for(int i=0; i<level; i++)
        {
            printf("    ");
        }
        inOrder(root->left,level+1);
        printf("%d\n",root->key);
        inOrder(root->right,level+1);
    }
}

void preOrder(nodeT *root,int level)
{
    if(root!=NULL)
    {
        for(int i=0; i<level; i++)
            printf("    ");

        printf("%d\n",root->key);
        preOrder(root->left,level+1);
        preOrder(root->right,level+1);
    }
}
int main()
{
    nodeT *root=NULL;
    insert(&root,15);
    insert(&root,6);
    insert(&root,18);
    insert(&root,20);
    insert(&root,17);
    insert(&root,7);
    insert(&root,13);
    insert(&root,3);
    insert(&root,2);
    insert(&root,4);
    insert(&root,9);
   deleteNode(root,17);
    preOrder(root,0);

    nodeT *p=searchkey(root,2);
    nodeT *q=findMax(p);
    nodeT *k=predecesor(root,p);
    printf("%d ",k->key);

    return 0;
}
