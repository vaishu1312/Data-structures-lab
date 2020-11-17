#include<stdio.h>
#include<stdlib.h>
#include "heapadt.h"

void main()
{
priorityqueue q=NULL;
position pos;
int choice,element,n;
printf("Enter the maximum no of elements: ");
scanf("%d",&n);
q=create(n);
do{
printf("\n***PRIORITY QUEUE MENU***\n\n1.Insert element\n2.Delete element\n3.Display the elements\n4.Exit\n");
printf("\nEnter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
if(!isfull(q))
{ printf("Enter element to be inserted: ");
 scanf("%d",&element);
}
 insert(element,q);
break;
case 2:
if(isempty(q))
  printf("\nPriority Queue is empty\n");
else
{ element=deletemin(q);
  printf("\n%d deleted from priority queue\n",element);  }
break;
case 3:
display(q);
printf("\n");
break;
case 4:
 break;
default:
 printf("Invalid choice\n");
}
}while(choice!=4);
}
