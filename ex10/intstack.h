typedef struct int_stackrecord* int_stack;

struct int_stackrecord
{
int capacity;
int topofstack;
int *array;
};

int_stack create_int_stack(int maxelements)
{
int_stack s=malloc(sizeof(struct int_stackrecord));
if(s==NULL)
  printf("Out of space!");
s->array=malloc(sizeof(int) * maxelements);
if(s->array == NULL)
  printf("Out of space!");
s->capacity = maxelements;
s->topofstack = -1;
return s;
}

void int_disposestack(int_stack s)
{
if(s!=NULL)
{
free(s->array);
free(s);
}
}

int int_isempty(int_stack s)
{
return s->topofstack == -1;
}

int int_isfull(int_stack s)
{
return s->topofstack==s->capacity-1;
}

void intpush(int x,int_stack s)
{
if(int_isfull(s))
    printf("Stack is full");
else
  s->array[++s->topofstack] = x;

}

void intpop(int_stack s)
{
if(int_isempty(s))
    printf("Stack is empty");
else
  s->topofstack--;
}

void int_display(int_stack s)
{
int i;
for(i=0;i<s->topofstack;i++)
 printf("%c",s->array[i]);
}

int int_return_top(int_stack s)
{
if(!int_isempty(s))
   return s->array[s->topofstack];
else
   return s->topofstack;
}

int int_topandpop(int_stack s)
{
if(!int_isempty(s))
    return s->array[s->topofstack--];
else
   return s->topofstack;
}


