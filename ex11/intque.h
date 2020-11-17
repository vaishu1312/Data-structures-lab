typedef struct queuerecord* queue;
typedef int elementtype;

struct queuerecord
{
int capacity;
int front;
int rear;
int size;
elementtype *array;
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
q->array=(elementtype*)malloc(sizeof(elementtype) * maxelements);
if(q->array == NULL)
  printf("Out of space!");
q->capacity = maxelements;
makeempty(q);
return q;
}

void disposequeue(queue q)
{
if(q!=NULL)
{
free(q->array);
free(q);
}
}

int isempty (queue q)
{
return q->size == 0;
}

int isfull (queue q)
{
return q->size == q->capacity;
}


void enqueue(queue q, elementtype item)
{
if(isfull(q))
printf("Queue is full");
else
{
q->rear++;
q->array[q->rear]=item;
if(q->front==-1)
 q->front=0;
++q->size;
}
}

int dequeue(queue q)
{
int data;
if(isempty(q))
{
printf("Queue is empty");
return;
}
else
{
data = q->array[q->front];
if(q->front==q->rear)
{  makeempty(q);
   return data;  }
else if(q->front+1 == q->capacity)
  q->front=0;
else
  q->front++;
q->size--;
return data;
}
}

void displayq(queue q)
{
int i;
if(isempty(q))
  printf("\nContainer is empty");
else
{ printf("\nThe products in the container are: ");  
  i=q->front;
  while(i!=q->rear)
  {   printf("\n%d",q->array[i]); i=(i+1)%q->capacity; }  //end while
  printf("\n%d\n",q->array[q->rear]);
} //end else
}
