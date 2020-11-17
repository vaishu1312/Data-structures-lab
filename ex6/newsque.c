#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "queuearr.h" 

void main()
{
int max,choice;
char ele[15];
char*x;
printf("Enter maximum no of items that can be stored in the container: ");
scanf("%d",&max);
queue q =createqueue(max);
do
{
printf("\n**MENU**\n1.Producer\n2.Consumer\n3.Display items in the container\n4.Exit\n\nEnter choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:  if(!isfull(q))
         {  printf("\nEnter item that is to be stored in the container: ");
            scanf("%s",ele);
            enqueue(q,ele);  }
         else
             printf("\nContainer is full! Could not store\n");
         break;

case 2:  x=dequeue(q);
         if(x!=NULL)
            printf("Item %s consumed.\n",x);
         else
            printf("Container is empty.Could not consume!\n");
            break;

case 3:  display(q);
         break;

case 4:  disposequeue(q);
         break;

default:  printf("Incorrect choice!");
}//switch
}while(choice!=4);
}
