typedef struct node *ptrtonode;
typedef ptrtonode stack;
struct node
{
char element;
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

void pop(stack s)
{
ptrtonode tmpcell;
if(isempty(s))
   printf("\nStack is empty");
else
{
tmpcell = s->next;
s->next = s->next->next;
free(tmpcell);
}
}

void dispose(stack s)
{
if(s==NULL)
  printf("Must use createstack first");
else
{  while(!isempty(s))
     pop(s);
  free(s);
  printf("Stack disposed" );
}
}

void push(char x, stack s)
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

char return_top(stack s)
{
char x;
if(!isempty(s))
{
x=s->next->element;
return x;
}
printf("\nStack is empty");
return 0;
}

void display(stack s)
{
ptrtonode temp=s->next;
printf("\nThe elements are: ");
while (temp!=NULL)
{  printf("%c",temp->element);
   temp=temp->next;
}
}
