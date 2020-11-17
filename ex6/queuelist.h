typedef struct node* ptrtonode;
typedef struct queuelist* queue;

struct node
{
char element[20];
ptrtonode next;
};

struct queuelist
{
ptrtonode front;
ptrtonode rear;
};

void initqueue(queue q)
{  q->front = q->rear = NULL;  }

int isempty(queue q)
{ return q->front==NULL; }

queue createqueue()
{
queue q=(queue)malloc(sizeof(struct queuelist));
if(q==NULL)
{	printf("Out of space");
	exit(0);
}
initqueue(q);
return q;
}

void enqueue(char x[], queue q)
{
ptrtonode tmpcell=(ptrtonode)malloc(sizeof(struct node));
if(tmpcell==NULL)
{
	printf("Out of space");
	exit(0);
}
else
{
	strcpy(tmpcell->element, x);
	tmpcell->next = NULL;
}
if(q->front==NULL)
	q->rear=q->front=tmpcell;
else
{
	q->rear->next=tmpcell;
	q->rear=q->rear->next;
}
}

char* dequeue(queue q)
{
ptrtonode temp;
static char data[20]; 
if(isempty(q))
{
	printf("Empty Queue");
	return NULL;
}
else
{
	strcpy(data,q->front->element);
	temp=q->front;
	q->front=q->front->next;
	free(temp);
	return data;
}
}

void displayQueue(queue q)
{
ptrtonode tmp=q->front;
printf("\nFiles to be printed: \n");
while(tmp!=NULL)
{
	printf("\n%s",tmp->element);
	tmp=tmp->next;
}
printf("\n");
}

void disposeQueue(queue q)
{
ptrtonode temp;
while(!isempty(q))
{
	temp=q->front;
	q->front=q->front->next;
	if(isempty(q))
		initqueue(q);
	free(temp);
}
}

