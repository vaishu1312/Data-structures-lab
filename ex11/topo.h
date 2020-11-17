typedef struct graph_node *graph;

struct graph_node
{
int vertices,edges;
int **adj_mat;
};

graph create_graph(int v)
{
int i,n,j,k;
graph g=(graph)malloc(sizeof(struct graph_node));
if(g==NULL)
{	printf("Out of space\n");
	exit(1);
}
g->vertices=v;
int**a=(int**)malloc(sizeof(int*)*v+1);
for(i=1;i<v+1;i++)
	a[i]=(int*)malloc(sizeof(int)*v+1);
for(i=1;i<v+1;i++)
  for(j=1;j<v+1;j++)
        a[i][j]=0;
printf("Enter the egdes as ViVj (Press -1 to stop):\n");
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

void display(graph g)
{
int i,j;
int n=g->vertices;
for(i=1;i<n+1;i++)
{ for(j=1;j<n+1;j++)
     printf("%d ",g->adj_mat[i][j]);
  printf("\n");
}
}


