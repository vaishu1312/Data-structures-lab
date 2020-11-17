typedef struct list *ptrToNode;
typedef ptrToNode LIST;
typedef int position;

typedef struct 
{
long id;
char bname[40];
char genre[25];
char author[40];
long yr;
}book;

struct list
{
int capacity;
int size;
book *arr;
};

LIST Createn(int max)
{
LIST l;
l=(struct list*)malloc(sizeof(struct list));
if(l== NULL)
   printf("\nError");
else
{
  l->capacity=max;
  l->arr=(book*)malloc(sizeof(book)*max);
  if(l->arr==NULL)
    printf("\nList creation error");
  else
  {
    l->size=0;
    printf("\nList is Created successfully\n");
  }
}
return l;
}

LIST Input(LIST l,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
 printf("Enter the details for book-%d: \n",i+1);
 printf("Enter the ID: ");
 scanf("%ld",&(l->arr[i].id));
 getchar();
 printf("Enter the name of the book: ");
 gets(l->arr[i].bname);
// scanf("%s",l->arr[i].bname);
 printf("Enter the genre: ");
 gets(l->arr[i].genre);
 //scanf("%s",l->arr[i].genre);
 printf("Enter the author: ");
 gets(l->arr[i].author);
//scanf("%s",l->arr[i].author);
 printf("Enter the year of publication: ");
 scanf("%ld",&(l->arr[i].yr));
 }
 l->size=n;
 return l;
}


void Display(LIST l)
{
int i;
printf("\nThe details of the books are:");
printf("\n ID       TITLE           GENRE         AUTHOR       YOP\n");
for(i=0;i<l->size;i++)
{
 printf("%ld  ",l->arr[i].id);
 printf("%s\t\t",l->arr[i].bname);
 printf("%s\t",l->arr[i].genre);
 printf("%s\t",l->arr[i].author);
 printf("%ld\n\n",l->arr[i].yr);
}
}


position Findpos(char b[],LIST l)
{
position P;
P=0;
while(P!=l->size && (strcmp(l->arr[P].bname,b)!=0))
      P++;
return P;
}

void Search(char x[],LIST l)
{
position p=Findpos(x,l);
if (p==l->size)
  printf("Element not found");
else
{
printf("\nThe details of the books are:");
printf("\n ID       TITLE           GENRE         AUTHOR       YOP\n");
printf("%ld  ",l->arr[p].id);
 printf("%s\t\t",l->arr[p].bname);
 printf("%s\t",l->arr[p].genre);
 printf("%s\t",l->arr[p].author);
 printf("%ld\n\n",l->arr[p].yr);
}
}

book InsertInput(LIST l)
{ book x;
 printf("Enter the details for book to be inserted: \n");
 printf("Enter the ID: ");
 scanf("%ld",&x.id);
 getchar();
 printf("Enter the name of the book: ");
 gets(x.bname);
 //scanf("%s",x.bname);
 printf("Enter the genre: ");
 gets(x.genre);
 //scanf("%s",x.genre);
 printf("Enter the author: ");
 gets(x.author);
 //scanf("%s",x.author);
 printf("Enter the year of publication: ");
 scanf("%ld",&x.yr);
 return x;
}

void Insert(LIST l)   
{
int i;
char b[40];  //b is the name of the book after which a book is to be inserted
position P;
if(l->size==l->capacity)
     printf("\n List is Full");
else
{
book x=InsertInput(l);   //x is a structure variable
getchar();
printf("Enter the name of the book after which the given book is to be inserted: ");
//gets(b);
scanf("%s",b);
P=Findpos(b,l);
for(i=l->size;i>P+1;i--)       //book needs to be inserted at p+1 position
   l->arr[i]=l->arr[i-1];
l->size++;
l->arr[P+1]=x;               //will insert at position p+1
printf("\nInserted successfully");
printf("\nThe list after inserting a book:\n");
Display(l);
}
}


void Delete(char b[],LIST l)
{
int i;
position P;
P=Findpos(b,l);
if(P==l->size)
    printf("\n Book not found in the list");
else
{
 for(i=P;i<l->size;i++)
   l->arr[i]=l->arr[i+1];
 l->size--;
 printf("Deleted successfully");
 printf("\nThe list after deleting a book:\n");
 Display(l);
}
}

int Count(char g[],LIST l)
{
 int i,cnt=0;
 for(i=0;i<l->size;i++)   
   if(strcmp(l->arr[i].genre,g)==0)
       cnt++;
  return cnt;
}

void Sort(LIST l)
{
 int i,j,minidx;
 book temp;
 for(i=0;i<l->size;i++)
 {
  minidx=i;
  for(j=i+1;j<l->size;j++)
     if (strcmp(l->arr[minidx].author,l->arr[j].author)>0)
        minidx=j;
  temp=l->arr[i];
  l->arr[i]=l->arr[minidx];
  l->arr[minidx]=temp;
 }
 printf("The sorted list based on author name: \n");
 Display(l);
}

