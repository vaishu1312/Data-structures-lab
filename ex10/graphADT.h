typedef struct graphnode* graph;
struct graphnode
{
int vertices;
int **adj_mat;
};

graph create_graph(int v)
{
int i,n,j,k;
graph g=(graph)malloc(sizeof(struct graphnode));
if(g==NULL)
{	printf("Out of space\n");
	exit(1);
}
g->vertices=v;
int**a=(int**)malloc(sizeof(int*)*v+1);
for(int i=1;i<v+1;i++)
	a[i]=(int*)malloc(sizeof(int)*v+1);
for(int i=1;i<v+1;i++)
  for(int j=1;j<v+1;j++)
        a[i][j]=0;
printf("Enter the egdes as ViVj (Press -1 to stop):\n ");
scanf("%d",&n);
do
{
k=n%10;
j=n/10;
a[j][k]=1;
scanf("%d",&n);
}while(n!=-1);
g->adj_mat=a;
return g;
}

