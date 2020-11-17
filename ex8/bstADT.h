typedef struct treenode *position;
typedef struct treenode *searchtree;
typedef struct treenode *ptrtonode;
typedef int elementtype;

struct treenode
{
elementtype element;
searchtree left;
searchtree right;
};

searchtree makeempty(searchtree t)
{
if (t!=NULL)
{
makeempty(t->left);
makeempty(t->right);
free(t);
}
return NULL;
}

position find(elementtype x, searchtree t)
{ static int cnt=0;
if(x==31)
{
cnt++;
if (t==NULL)
   return NULL;
if (x<t->element)
    return find (x, t->left);
else if (x>t->element)
   return find(x,t->right);
else
  {printf("No of times find function is called to find 31 is: %d",cnt); return t;  }
}
else  //x not 31
{
if (t==NULL)
   return NULL;
if (x<t->element)
    return find (x, t->left);
else if (x>t->element)
   return find(x,t->right);
else
  return t;  
}
}

position findmin(searchtree t)
{
if(t==NULL)
  return NULL;
else if(t->left==NULL)
    return t;
else
    return findmin(t->left);
}

/*position findmin(searchtree t)
{
position p=t;
if(p!=NULL)
while(p->left!=NULL)
	p=p->left;
return p;

int findmin(searchtree t)
{
position p=t;
if(p!=NULL)
while(p->left!=NULL)
	p=p->left;
return p->element;

}*/

position findmax(searchtree t)
{
position p=t;
if(p!=NULL)
while(p->right!=NULL)
	p=p->right;
return p;
}

searchtree insert(elementtype x, searchtree t)
{
if(t==NULL)
{
t=(searchtree)malloc(sizeof(struct treenode));
if(t==NULL)
	printf("Out of space");
else
{
t->element=x;
t->left=t->right=NULL;
}
}
else if(x<t->element)
	t->left=insert(x,t->left);
else if(x>t->element)
	t->right=insert(x,t->right);
return t;
}

searchtree delete(elementtype x, searchtree t)
{
position tmpcell;
if(t==NULL)
	printf("\nElement %d  not found\n",x);
else if(x<t->element)
	t->left=delete(x,t->left);
else if(x>t->element)
	t->right=delete(x,t->right);
else if(t->left && t->right)
{
	tmpcell=findmin(t->right);
	t->element=tmpcell->element;
	t->right=delete(t->element,t->right);
}
else
{
tmpcell=t;
if(t->left==NULL)
	t=t->right;
else if(t->right==NULL)
	t=t->left;
free(tmpcell);
}
return t;
}

void inorder(searchtree t) 
{ if ( t == NULL) 
          return; 
     inorder( t->left); 
     printf("%d ",  t->element);   
     inorder( t->right); 
} 
  




