#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queuelist.h"

void main()
{
queue q =createqueue();
int choice;
char ele[20];
do
{
printf("\n**MENU**\n\n1.Input file to print\n2.Print file\n3.Display items to be printed\n4.Exit\n\nEnter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\nEnter the name of the file you want to print: ");
getchar();
gets(ele);
printf("%s queued\n",ele);
enqueue(ele,q);
break;

case 2:
if(!isempty(q))
{
printf("%s printed \n",dequeue(q));
}
else
printf("\nNo file to print. Could not print.\n");
break;

case 3:
if(!isempty(q))
   displayQueue(q);
else
    printf("\nQueue is empty.No items to be printed.\n");
break;

case 4:
disposeQueue(q);
printf("\nAll files in queue have been discarded.\n");
break;

default:
printf("Incorrect choice!");
}//switch
}while(choice!=4);

}
