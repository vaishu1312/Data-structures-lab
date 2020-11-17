typedef struct lineartable* LinearTable;

struct lineartable {
  int lt_size;
  int* arr;
};


LinearTable create(int tsize) 
{
  LinearTable l=malloc(sizeof(struct lineartable));
  l->lt_size=tsize; 
  l->arr=(int*)malloc(sizeof(int)*tsize);
  for(int i=0;i<l->lt_size;i++) 
      l->arr[i]=-1;
  return l;
}

void displaylinear(LinearTable l) 
{
  for(int i=0;i<l->lt_size;i++) 
  {
    printf("%d: ",i);
    if(l->arr[i]!=-1)
       printf("%d\n",l->arr[i]);
    else
       printf("\n");
  }
}

void insertlinear(LinearTable l,int data) 
{
  int pos;
  static int cnt=0;
  if(cnt==l->lt_size) 
    printf("NO SPACE\n");
  else 
  {
    pos=data%l->lt_size;
    while((l->arr[pos]!=-1)) 
        pos=(pos+1)%l->lt_size;
    l->arr[pos]=data;
    cnt++;
  }
}

