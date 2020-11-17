typedef struct avlnode *position;
typedef struct avlnode *avltree;
typedef int elementtype;

struct avlnode
{
elementtype element;
avltree left;
avltree right;
int height;
};

static int height (position p)
{
if(p==NULL)
return -1;
else
return p->height;
}

int max(int a, int b)
{
if (a>b)
 return a;
else 
  return b;
}

static position singlerotatewithleft(position k2)
{
position k1;
k1=k2->left;
k2->left=k1->right;
k1->right=k2;
k2->height=max(height(k2->left),height(k2->right))+1;
k1->height=max(height(k1->left),k2-> height)+1;
return k1;
}

static position singlerotatewithright(position k2)
{
position k1;
k1=k2->right;
k2->right=k1->left;
k1->left=k2;
k2->height=max(height(k2->right),height(k2->left))+1;
k1->height=max(height(k1->right),k2-> height)+1;
return k1;
}


static position doublerotatewithleft(position k3)
{ //rotate between k1 and k2
k3->left=singlerotatewithright(k3->left);
//rotate between k3 and k2
return singlerotatewithleft(k3);
}

static position doublerotatewithright(position k3)
{ //rotate between k1 and k2
k3->right=singlerotatewithleft(k3->right);
//rotate between k3 and k2
return singlerotatewithright(k3);
}

avltree insert(elementtype x, avltree t)
{
if(t==NULL)
{
 t=(avltree)malloc(sizeof(struct avlnode));
 if(t==NULL)
  printf("Out of Space");
 else
 {
 t->element=x;
 t->height=0;
 t->left=t->right=NULL;
 }
}
else if(x<t->element)
{
t->left=insert(x,t->left);
if(height(t->left) - height(t->right) ==2)
 if(x<t->left->element)
    t=singlerotatewithleft(t);
 else
   t=doublerotatewithleft(t);
}
else if(x>t->element)
{
 t->right=insert(x,t->right);
 if(height(t->right) - height(t->left) == 2)
   if(x>t->right->element)
      t=singlerotatewithright(t);
 else
   t=doublerotatewithright(t);
}
t->height=max(height(t->left),height(t->right))+1;
return t;
}


position find(elementtype x, avltree t)
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

position findmin(avltree t)
{
position p=t;
if(p!=NULL)
while(p->left!=NULL)
	p=p->left;
return p;
}

position findmax(avltree t)
{
position p=t;
if(p!=NULL)
while(p->right!=NULL)
	p=p->right;
return p;
}

void inorder(avltree t) 
{ if ( t == NULL) 
          return; 
     inorder( t->left); 
     printf("%d ",  t->element);   
     inorder( t->right); 
} 
  
