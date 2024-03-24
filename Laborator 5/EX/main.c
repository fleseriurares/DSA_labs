#include <stdio.h>
#include <stdlib.h>


typedef struct nodeT {
    int key;
    struct NodeT *left;
    struct NodeT *right;
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


nodeT* searchKey(nodeT *root, int val) {
if(root==NULL || root->key==val)
        return root;
    if(val<root->key)
        return  searchKey(root->left,val);
    return searchKey(root->right,val);
}

nodeT *findMin(nodeT *root) {
    if(root->left==NULL)
        return root;
    return findMin(root->left);
}

nodeT *findMax(nodeT *root) {
if(root->right==NULL)
        return root;
    return findMax(root->right);
}

nodeT* succesor(nodeT *root, nodeT *node) {
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

nodeT* predecesor(nodeT *root, nodeT *node) {
if(root==NULL || node==NULL)
    return NULL;
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

nodeT *deleteNode(nodeT *root, int val) {
nodeT *p=searchKey(root,val);
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

void inOrder(nodeT *root,int level) {
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

void preOrder(nodeT *root,int level) {
if(root!=NULL)
    {
        for(int i=0; i<level; i++)
            printf("    ");

        printf("%d\n",root->key);
        preOrder(root->left,level+1);
        preOrder(root->right,level+1);
    }
}

void postOrder(nodeT *root,int level) {
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

int main() {

    nodeT *root = NULL;
    nodeT *p;

    int n = 11;
    int keys[] = {15, 6, 18, 17, 20, 3, 7, 2, 4, 13, 9};

    insert(&root, keys[0]);

    for (int i = 1; i < n; i++) {
        insert(&root, keys[i]);
    }

    printf( "\nPreorder listing\n" );
    preOrder( root,0);
    printf( "\nInorder listing\n" );
    inOrder( root,0 );
    printf( "\nPostorder listing\n" );
    postOrder( root,0 );

    int key = 15;
    p = searchKey( root, 2 );
    if ( p != NULL ){
        printf( "\nNod cu cheia = %d gasit\n" , key);
        nodeT *m = findMin(p);
        printf("Minimul din subarborele care are ca radacina nodul %d este %d \n", p->key, m->key);
    }
    else
        printf( "Nodul NU a fost gasit \n" );

    nodeT *s = succesor(root, p);
    if ( s != NULL && p!=findMax(root)){
        printf( "Nodul cu cheia = %d are succesor pe %d\n" , p->key, s->key);
    }
    else
        printf( "Nodul NU are succesor !\n" );

    nodeT *q = predecesor(root, p);
    if ( q != NULL && p!=findMin(root) ){
        printf( "Nodul cu cheia = %d are predecesor pe %d\n" , p->key, q->key);
    }
    else
        printf( "Nodul NU are predecesor !\n" );


    key = 15;
    printf("Nodul de sters este: %d\n", key);
    root = deleteNode( root, key );
    inOrder( root,0 );

    return 0;
}
