#define minpqsize 2
#define mindata -1
typedef struct heapstruct * position;
typedef struct heapstruct *priorityqueue;
typedef int elementtype;

struct heapstruct
{
int capacity;
int size;
elementtype *elements;
};

priorityqueue create(int maxelements)
{
priorityqueue h;
if(maxelements<minpqsize)
  printf("Priority Queue is too small");
h=(priorityqueue)malloc(sizeof(struct heapstruct));
if(h==NULL)
   printf("Out of space");
h->elements=(priorityqueue)malloc((maxelements+1)*sizeof(elementtype));
if(h->elements==NULL)
   printf("Out of Space");
h->capacity=maxelements;
h->size=0;
h->elements[0]=mindata;
return h;
}

int isfull(priorityqueue h)
{
return h->size==h->capacity;
}

int isempty(priorityqueue h)
{
return h->size==0;
}

void insert(elementtype x, priorityqueue h)
{
int i;
if(isfull(h))
{
printf("Priority Queue is full\n");
return;
}
for(i=++h->size;h->elements[i/2]>x; i/=2)
  h->elements[i] = h->elements[i/2];
h->elements[i]=x;
}

elementtype deletemin(priorityqueue h)
{
int i, child;
elementtype minelement, lastelement;
minelement=h->elements[1];
lastelement=h->elements[h->size--];
for(i=1;(i*2)<=h->size;i=child)
{
child=i*2;
if(child!=h->size && h->elements[child+1] < h->elements[child])
    child++;
if(lastelement > h->elements[child])
   h->elements[i]=h->elements[child];
else
   break;
}
h->elements[i]=lastelement;
return minelement;
}

void display (priorityqueue h)
{
 int i;
if(isempty(h))
  printf("Priority Queue is empty");
else
{
 printf("\nThe elements are:  \n");
 for(i=1;i<h->size+1;i++)
   printf("%d ",*(h->elements+i));
}
}

