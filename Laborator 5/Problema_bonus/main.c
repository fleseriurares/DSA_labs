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
    return p;
}

nodeT *insert(nodeT *root,int val)
{
    if(root==NULL)
    {
        root=newnode(val);
        return root;
    }
    else
    {
        if(val<root->key)
        {
            root->left=insert(root->left,val);
        }
        else
            root->right=insert(root->right,val);
    }
    return root;
}

typedef struct node
{
    int val;
    struct node *next;
} lisT;

lisT *newnod(int a)
{
    lisT *p=(lisT *)malloc(sizeof(lisT));
    p->next=NULL;
    p->val=a;
    return p;

}
void insert_last(lisT **first,lisT **last,int a)
{
    lisT *p=newnod(a);
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        (*last)->next=p;
        *last=p;
    }
}
void insert_first(lisT **first,lisT **last, int a)
{
    lisT *p=newnod(a);
    if(*first==NULL)
    {
        *first=p;
        *last=p;
    }
    else
    {
        p->next=*first;
        p->val=a;
        *first=p;
    }
}
void del_last(lisT **p)
{
    if(*p!=NULL)
    {
        if((*p)->next==NULL)
        {
            *p=NULL;
        }
        else
        {   lisT *k=*p;
            while((k)->next->next!=NULL)
            {
                k=(k)->next;
            }
            lisT *aux=(k)->next;
            (k)->next=NULL;
            free(aux);
        }
    }
}
void preorder(nodeT *p, int niv)
{
    if(p!=NULL)
    {
        for(int i=0; i<niv; i++)
        {
            printf("    ");
        }
        printf("%d\n",p->key);
        preorder(p->left,niv+1);
        preorder(p->right,niv+1);
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

void afisare(lisT *first)
{
    if(first!=NULL)
    {
        while(first->next!=NULL)
        {
            printf("%d -> ",first->val);
            first=first->next;
        }
        printf("%d\n",first->val);
    }
}

int sum_list(lisT *p)
{
    int suma=0;
    if(p!=NULL)
    {
        while(p!=NULL)
        {
            suma+=p->val;
            p=p->next;
        }
    }
    return suma;
}

void calc(nodeT *root,int k,int m,int *sum)
{
    if(root!=NULL)
    {
     nodeT *root_b=root;
     *sum=*sum

    }
}

int main()
{
    int k,m;
    printf("k=");
    scanf("%d",&k);
    printf("m=");
    scanf("%d",&m);

    nodeT *root=NULL;
    root=insert(root,2);
    insert(root,5);
    insert(root,10);
    insert(root,4);
    insert(root,7);
    insert(root,-26);
    insert(root,-12);
    insert(root,0);
    preorder(root,0);

    lisT *first=NULL,*last=NULL;
    insert_last(&first,&last,1);
    insert_last(&first,&last,2);
    insert_last(&first,&last,5);
    insert_last(&first,&last,-10);
    afisare(first);

    return 0;
}


