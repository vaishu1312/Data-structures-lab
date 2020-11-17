typedef struct listnode *Node;
typedef struct listnode *position;
typedef struct hashtbl *hashtable;
typedef position list;
typedef int elementtype;

struct listnode
{
elementtype element;
position next;
};

struct hashtbl
{
int tablesize;
list *thelists;
};


int nextprime(int x)
{
int i,j,c;
for(i=x;;i++)
{
c=0;
for(j=2;j<=(i/2);j++)
 if(i%j==0)
    c++;
if(c==0)
return i;
}
}

int hash(int key, int tablesize)
{
return key % tablesize;
}


position find(elementtype key,hashtable h)
{
position pos;
pos=h->thelists[hash(key,h->tablesize)];
return pos;
}

void display(hashtable t) 
{
  Node temp;
  for(int i=0;i<t->tablesize;i++) 
  {
    printf("%d ",i);
    temp=t->thelists[i];
    while(temp->next!=NULL) 
    {
      temp=temp->next;
      printf("-> %d ",temp->element);
    }
    printf("\n");
  }
}


hashtable initializetable(int tablesize)
{
int i;
hashtable h = malloc(sizeof(struct hashtbl));
h->tablesize = nextprime(tablesize);
h->thelists = malloc(sizeof(list) * h->tablesize);
for(i=0;i<h->tablesize;i++)
{
h->thelists[i]=malloc(sizeof(struct listnode)); 
h->thelists[i]->next=NULL;
}
return h;
}


void insert(elementtype key,hashtable h)
{
position newcell;
list l;
l=find(key,h);
newcell=malloc(sizeof(struct listnode));
newcell->element=key;
newcell->next=NULL;
if(l->next==NULL)
  l->next=newcell;
else
{
newcell->next=l->next;
l->next=newcell;
}
}




