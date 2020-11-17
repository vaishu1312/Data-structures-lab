typedef struct treenode *tree;
typedef struct node *ptrtonode;
typedef ptrtonode stack;

struct treenode
{
char element;
tree left;
tree right;
};

struct node
{
tree element;
ptrtonode next;
};

int isempty(stack s)
{
return s->next==NULL;
}

stack createstack( )
{
stack s=(stack)malloc(sizeof(struct node));
if(s==NULL)
    printf("Out of space");
return s;
}

tree pop(stack s)
{
ptrtonode tmpcell;
tree x;
if(isempty(s))
   printf("\nStack is empty");
else
{
tmpcell = s->next;
x=tmpcell->element;
s->next = s->next->next;
free(tmpcell);
}
return x;
}

void push(tree x, stack s)
{
ptrtonode tmpcell=(stack)malloc(sizeof(struct node));
if(tmpcell==NULL)
    printf("Out of space");
else
{
tmpcell->element = x;
tmpcell->next = s->next;
s->next = tmpcell;
}
}

tree createtree( )
{
tree t=(tree)malloc(sizeof(struct treenode));
if(t==NULL)
    printf("Out of space");
return t;
}

void postorder(tree t) 
{ 
     if ( t == NULL) 
        return; 
     postorder( t->left); 
     postorder( t->right); 
     printf("%c ",  t->element); 
} 
  
void preorder(tree t) 
{ 
     if ( t == NULL) 
          return; 
     printf("%c ",  t->element);   
     preorder( t->left);   
     preorder( t->right); 
}     

void inorder(tree t) 
{ 
     if ( t == NULL) 
          return; 
     inorder( t->left); 
     printf("%c ",  t->element);   
     inorder( t->right); 
} 
  
