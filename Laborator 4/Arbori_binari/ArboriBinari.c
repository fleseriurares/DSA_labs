#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
    int id; /* numele nodului */
    /* alte informatii  utile */
    struct node_type *left, *right;
} NodeT;

void fatalError( const char *msg )
{
    printf( msg );
    printf( "\n" );
    exit ( 1 );
}

void postorder( NodeT *r ){
if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->id);
    }
}

void inorder( NodeT *r ){
 if(r!=NULL)
    {
        inorder(r->left);
        printf("%d ",r->id);
        inorder(r->right);
    }
}

int leaf_node(NodeT *node){

if(node==NULL)
    return 0;
if(node!=NULL && (node->left==NULL && node->right==NULL))
{
    return 1;
}
return leaf_node(node->left)+leaf_node(node->right);
}


int noduri_interne(NodeT *node){
if(node!=NULL && (node->left!=NULL || node->right!=NULL))
{
    return 1+noduri_interne(node->left)+noduri_interne(node->right);
}

    return 0;
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int inaltime(NodeT *node){
  if(node == NULL)
    {
        return -1;
    }
    else
        return 1+max(inaltime(node->left),inaltime(node->right));
   return 0;
}


void preorder( NodeT *r )
 {
if(r!=NULL)
    {
        printf("%d ",r->id);
        preorder(r->left);
        preorder(r->right);
    }
}
//creaza un arbore binar prin citirea de la tastatura
NodeT *createBinTree( int branch, NodeT *parent )
{
    NodeT *p;
    int id;

    /* read node id */
    if ( branch == 0 )
        printf( "Valoarea pentru radacina [0 pt null] =" );
    else if ( branch == 1 )
        printf( "Fiul stang al nodului cu valoarea %d [0 pt null] =",
                parent->id );
    else
        printf( "Fiul drept al nodului cu valoarea %d [0 pt null] =",
                parent->id );
    scanf("%d", &id);
    if ( id == 0 )
        return NULL;
    else
    {
        /* construim nodul la care pointeaza p */
        p = ( NodeT *)malloc(sizeof( NodeT ));
        if ( p == NULL ){
            printf( "Nu mai avem memorie in createBinTree" );
            exit(1);
        }
        /* fill in node */
        p->id = id;
        p->left = createBinTree( 1, p );
        p->right = createBinTree( 2, p );
    }
    return p;
}
NodeT *createBinTreeFromFile(FILE* f)
{
  NodeT *p;
  int c;

  /* se citeste id-ul nodului */
  fscanf(f, "%d", &c);
  if ( c == 0 )
    return NULL; /* arbore vid, nu facem nimic */
  else /* else inclus pentru claritate */
  { /* construim nodul la care pointeaza p */
    p = ( NodeT *) malloc( sizeof( NodeT ));
    if ( p == NULL )
      fatalError( "Nu mai avem memorie in createBinTree" );
    /* se populeaza nodul */
    p->id = c;
    p->left = createBinTreeFromFile(f);
    p->right = createBinTreeFromFile(f);
  }
  return p;
}


int main()
{
    NodeT *root;
    FILE *f = fopen("ArboreBinar.txt", "r");
    if (!f){
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }
    root = createBinTreeFromFile(f);
    fclose(f);


    printf( "\nParcurgere in preordine\n" );
    preorder( root );
    printf( "\nParcurgere in postordine\n" );
	//TODO
	postorder(root);
printf( "\nParcurgere in inordine\n" );
	inorder(root);

	int nr_frunze = leaf_node(root);
	printf("\nNumarul de frunze este %d\n", nr_frunze);//3

    printf("Noduri interne = %d \n", noduri_interne(root));//5

    printf("Inaltimea arborelui = %d \n", inaltime(root)); //3
    return 0;
}
