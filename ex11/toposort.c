#include<stdio.h>
#include<stdlib.h>
#include "intque.h"
#include "topo.h"

int indegree(graph g,int v)
{
int j,count=0;
for(j=1;j<=g->vertices;j++)
  if (g->adj_mat[j][v]==1)
    count++;
return count;
}

void topologicalsort(graph g)
{
int counter=0,i;
int v,w;
queue q=createqueue(g->vertices);
for(i=1;i<=g->vertices;i++)
 if(indegree(g,i)==0)
   enqueue(q,i);
while(!isempty(q))
{
v=dequeue(q);
printf("%d  ",v);
++counter;
for(w=1;w<=g->vertices;w++) //for each vertex
{
 if(g->adj_mat[v][w]==1) //check if its adjacent
  {  
   g->adj_mat[v][w]-=1;
   if(indegree(g,w)==0)
     enqueue(q,w);
  }
}
}
if(counter!=g->vertices)
 printf("\n\nThe graph is cyclic\n");
else
 printf("\n\nThe graph is acyclic\n");
}

void main()
{
graph g;
int i,j,v,e;
printf("Enter number of vertices: ");
scanf("%d",&v);
g=create_graph(v);
printf("\nThe adjacency matrix is\n\n");
display(g);
printf("\nTopological sorting:\n");
topologicalsort(g);
}

 
