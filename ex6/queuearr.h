typedef struct queuerecord* queue;
typedef char elementtype[30];  //elementtype can hold 30 characters -a string

struct queuerecord
{
int capacity;
int front;
int rear;
int size;
elementtype *arr;  //arr is a pointer to string
};

void makeempty(queue q)
{
q->size = 0;
q->front = -1;
q->rear = -1;
}

queue createqueue(int maxelements)
{
int i;
queue q=(queue)malloc(sizeof(struct queuerecord));
if(q==NULL)
  printf("Out of space!");
q->arr=(elementtype*)malloc(sizeof(elementtype) * maxelements);
if(q->arr == NULL)
  printf("Out of space!");
q->capacity = maxelements;
makeempty(q);
return q;
}

int isempty (queue q)
{ return q->size == -1;  }

void display(queue q)
{
int i;
if(isempty(q))
  printf("\nContainer is empty");
else
{ printf("\nThe products in the container are: ");  
  i=q->front;
  while(i!=q->rear)
  {   printf("\n%s",q->arr[i]); i=(i+1)%q->capacity; }  //end while
  printf("\n%s\n",q->arr[q->rear]);
} //end else
}

void disposequeue(queue q)
{
if(q!=NULL)
{
free(q->arr);
free(q);
}
}

int isfull (queue q)
{  return q->size == q->capacity;  }

void enqueue(queue q, elementtype item)
{
   if(q->rear+1==q->capacity)
	q->rear=0;
   else
	q->rear++;
   strcpy(q->arr[q->rear],item);
   if(q->front==-1) 
       q->front=0;
   ++q->size;
}

char* dequeue(queue q)
{
static char data[15];
if(isempty(q))
   {  return NULL;  }
else
{
 strcpy(data,q->arr[q->front]);
 if(q->front==q->rear)  //only one element is present
    makeempty(q);
 else if(q->front+1 == q->capacity)
     q->front=0;  //front is pointing to end of arr
 else
     q->front++;
 q->size--;
 return data;
}
}
