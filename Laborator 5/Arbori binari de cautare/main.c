#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    struct _node *left;
    struct _node *right;
}nodeT;

nodeT *newnode(int val)
{
    nodeT *p=(nodeT *)malloc(sizeof(nodeT));
    p->key=val;
    p->left=NULL;
    p->right=NULL;
    return p;
}

nodeT *search(nodeT *root,int val)
{

    if(root==NULL || root->key==val)
    {
        return root;
    }
    if(root->key<val)
    {
        return search(root->right,val);
    }
    return search(root->left,val);
}

nodeT *insert_val(nodeT **root,int val)
{
    if(*root==NULL)
    {
        *root=newnode(val);
        return root;
    }
    else
    {
        if(val<(*root)->key)
        {
            return insert_val(&((*root)->left),val);
        }
        else
        {
            return insert_val(&((*root)->right),val);
        }
    }

}

nodeT *findMin(nodeT *root)
{
    if(root->left!=NULL)
    {
        return findMin(root->left);
    }
    return root;
}

nodeT *findMax(nodeT *root)
{
    if(root->right!=NULL)
    {
        return findMin(root->right);
    }
    return root;
}

nodeT *find_parent(nodeT *arbore,nodeT *p)
{

    if(arbore->left==p || arbore->right==p || arbore==NULL)
        return arbore;
    if(arbore==p)
        return NULL;
    if(p->key<arbore->key)
        {
            return (arbore->left,p);
        }
    if(p->key>arbore->key)
        return find_parent(arbore->right,p);

}

nodeT *predecesor(nodeT *arbore,nodeT *p)
{
    if(arbore==NULL || p==NULL)
        return NULL;
    if(p->left!=NULL)
    {
        return findMax(p->left);
    }
    else
    {
        if(arbore->key<p->key)
        {
            nodeT *min=findMin(arbore->right);
            if(min==p)
                return arbore;
            else
            {
                return predecesor(arbore->right,p);
            }
        }
        else
        {
            nodeT *min=findMin(arbore->left);
            if(min==p)
                return arbore;
            else
                return predecesor(arbore->left,p);
        }

    }
}


nodeT *succesor(nodeT *arbore,nodeT *p)
{
    if(arbore==NULL || p==NULL)
        return NULL;
    if(p->right!=NULL)
    {
        return findMin(p->right);
    }
    else
    {printf("%d ",arbore->key);
        if(p->key<arbore->key)
        {
            nodeT *max=findMax(arbore->left);
            if(max==p)
                return arbore;
            else
                return succesor(arbore->left,p);
        }
        else
        {
            nodeT *max=findMax(arbore->right);
            if(max==p)
                return arbore;
            else
                return succesor(arbore->right,p);

        }
    }
}

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int adancime(nodeT *arbore)
{
    if(arbore==NULL)
        return -1;
    return 1+max(adancime(arbore->right),adancime(arbore->left));
}
nodeT *delete_node(nodeT *root,int val)
{
nodeT *p=search(root,val);
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        if(val<root->key)
        {
            root->left=delete_node(root->left,val);
        }
        else if(val>root->key)
        {
            root->right=delete_node(root->right,val);
        }
        else
        {
            if(root->left==NULL)
            {
                p=root->right;
                free(root);
                return p;
            }
            else if(root->right==NULL)
            {
                p=root->left;
                free(root);
                return p;
            }
            p=findMax(root->left);
            root->key=p->key;
            root->left=delete_node(root->left,p->key);
        }
        return root;
    }
}
int inaltime(nodeT *arbore, int x)
{  nodeT *p=search(arbore,x);
    return adancime(p);
}
void inorder(nodeT *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}}

void preOrder(nodeT *root,int niv)
{
    if(root!=NULL)
    {
        for(int i=0;i<niv;i++)
        {
            printf("    ");
        }
        printf("%d\n",root->key);
        preOrder(root->left,niv+1);
        preOrder(root->right,niv+1);
    }
}
int main()
{
    nodeT *root=NULL;
    insert_val(&root,4);
    insert_val(&root,2);
    insert_val(&root,10);
    insert_val(&root,1);
    insert_val(&root,3);
    insert_val(&root,6);
    insert_val(&root,5);
    insert_val(&root,12);
   // insert_val(&root,11);
    insert_val(&root,13);
    insert_val(&root,15);
root=delete_node(root,15);
  nodeT *p=search(root,11);
   /// nodeT *r=succesor(root, p);
    printf("ADANCIME: %d\n",adancime(root));
    printf("inaltime: %d\n",inaltime(root ,5));

    /*nodeT *parent=find_parent(root,p);
   /// printf("\n parent: %d",parent->key);
    printf("\nMIN:%d",findMin(p)->key);
    printf("\nMAX:%d",findMax(p)->key);
    if(p!=NULL)
    printf("\nSEARCH: %d",p->key);
    */preOrder(root,0);
    return 0;
}
