typedef struct stackrecord* stack;

struct stackrecord
{
int capacity;
int topofstack;
char *array;
};

stack createstack(int maxelements)
{
stack s=(stack)malloc(sizeof(struct stackrecord));
if(s==NULL)
  printf("Out of space!");
s->array=malloc(sizeof(char) * maxelements);
if(s->array == NULL)
    printf("Out of space!");
s->capacity = maxelements;
s->topofstack = -1;
return s;
}

void disposestack(stack s)
{
if(s!=NULL)
{
free(s->array);
free(s);
}
}

int isempty(stack s)
{
return s->topofstack == -1;
}

int isfull(stack s)
{
return s->topofstack==s->capacity-1;
}

void push(char x,stack s)
{
if(isfull(s))
    printf("Stack is full");
else
  s->array[++s->topofstack] = x;

}

void pop(stack s)
{
if(isempty(s))
    printf("Stack is empty");
else
  s->topofstack--;
}

void display(stack s)
{
int i;
for(i=0;i<s->topofstack;i++)
 printf("%c",s->array[i]);
}

char return_top(stack s)
{
if(!isempty(s))
   return s->array[s->topofstack];
else
   return s->topofstack;
}

char topandpop(stack s)
{
if(!isempty(s))
    return s->array[s->topofstack--];
else
   return s->topofstack;
}