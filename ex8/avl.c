#include<stdio.h>
#include<stdlib.h>
#include "avltree.h"

void main()
{
avltree t=NULL;
position pos;
int choice,element;
do{
printf("\n***AVL SEARCH TREE MENU***:\n\n1.Insert element\n2.Find element\n3.Find minimum\n4.Find maximum\n5.Display in ascending order\n6.Exit\n");
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
printf("Enter element to be found: ");
scanf("%d",&element);
if(find(element,t)==NULL)
	printf("\nElement %d not found!\n",element);
else
	printf("\nElement %d found!\n",element);
break;
case 3:
pos=findmin(t);
printf("Minimum element is %d\n",pos->element);
break;
case 4:
pos=findmax(t);
printf("Maximum element is %d\n",pos->element);
break;
case 5:
printf("\nAscending order of integers: \n");
inorder(t);
printf("\n");
break;
case 6:
 break;
default:
 printf("Invalid choice\n");
}
}while(choice!=6);
}
