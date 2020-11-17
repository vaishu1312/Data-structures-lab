#include<stdio.h>
#include<stdlib.h>
#include "bstADT.h"

void main()
{
searchtree t=NULL;
position pos;
int choice,element;
do{
printf("\n***BINARY SEARCH TREE MENU***:\n\n1.Insert element\n2.Delete element\n3.Find element\n4.Find minimum\n5.Find maximum\n6.Display in ascending order\n7.Exit\n");
printf("\nEnter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter element to be inserted: ");
scanf("%d",&element);
t=insert(element,t);
break;
case 2:
printf("Enter element to be deleted: ");
scanf("%d",&element);
t=delete(element,t);
break;
case 3:
printf("Enter element to be found: ");
scanf("%d",&element);
if(find(element,t)==NULL)
	printf("\nElement %d not found!\n",element);
else
	printf("\nElement %d found!\n",element);
break;
case 4:
pos=findmin(t);
printf("Minimum element is %d\n",pos->element);
break;
case 5:
pos=findmax(t);
printf("Maximum element is %d\n",pos->element);
break;
case 6:
printf("\nAscending order of integers: \n");
inorder(t);
printf("\n");
break;
case 7:
 break;
default:
 printf("Invalid choice\n");
}
}while(choice!=7);
}
