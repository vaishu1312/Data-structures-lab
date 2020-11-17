#include<stdio.h>
#include<stdlib.h>
#include "intque.h"
#include "intstack.h"
#include "graphADT.h"


void visit(elementtype x)
{
	printf("%d ",x);
}

int unvisitedNeigh(int n,int ** adj_mat,int z,int visited[])
{
int i,j,y;
for(y=1;y<n+1;y++)
  if(adj_mat[z][y]==1 && visited[y]==0)
       return y;
return -1;
}

void dfs(graph g)
{    
int i,x=1,y,z,p=0;  //p  is the no of visited notes
int n=g->vertices;
int visited[n+1];  //array to check if a node has been visited
for(i=0;i<n+1;i++)
  visited[i]=0;
int_stack s=create_int_stack(n);
while(p!=n)
{
visit(x);
p++;
visited[x]=1;
intpush(x,s);
x++;
while(!int_isempty(s))
 { z=int_return_top(s);
   y=unvisitedNeigh(n,g->adj_mat,z,visited);
   if(y!=-1)
   {
      visit(y);
      p++;
      visited[y]=1;
      intpush(y,s);
   }
   else
      intpop(s);
 }
}
}

void bfs(graph g)
{
int i,x=1,y,z,p=0;  //p  is the no of visited notes
int n=g->vertices;
int visited[n+1];  //array to check if a node has been visited
for(i=0;i<n+1;i++)
  visited[i]=0;
queue q =createqueue(n);
while(p!=n)
{
visit(x);
p++;
visited[x]=1;
enqueue(q,x);
x++;
while(!isempty(q))
 { z=dequeue(q);
   for(y=1;y<n+1;y++)
   {  if(g->adj_mat[z][y]==1 && visited[y]==0)
     {
      visit(y);
      p++;
      visited[y]=1;
      enqueue(q,y);
     }
   }
 }
}
}

void main()
{
int n;
printf("Enter number of vertices: ");
scanf("%d",&n);
graph g=create_graph(n);
printf("\nThe adjacency matrix is\n");
for(int i=1;i<n+1;i++)
{ for(int j=1;j<n+1;j++)
     printf("%d ",g->adj_mat[i][j]);
  printf("\n");
}

printf("\nThe BFS is: ");
bfs(g);
printf("\nThe DFS is: ");
dfs(g);
printf("\n");
}

