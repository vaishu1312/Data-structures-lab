#include<stdio.h>
#include<stdlib.h>
#include "SC.h"
#include "LP.h"

void main() 
{
hashtable t=NULL;
LinearTable lt=NULL;
int ch=1,ch1,ch2,tsize,ltsize,data;
do 
{
  printf("\n1.Separate Chaining\n2.Linear Probing\n3.Exit\n\nEnter choice: ");
  scanf("%d",&ch1);
  if(ch1==1)
  {
    printf("Enter the table Size: ");
    scanf("%d",&tsize);
    t=initializetable(tsize);
    printf("\n1.To enter the values\n2.Exit\n\nEnter choice: ");
    scanf("%d",&ch2);
    if(ch2==1)
    {
    printf("Enter -1 to stop\n");
    printf("\nEnter value: ");
    scanf("%d",&data);
    do{
        insert(data,t);
        //disp(t);
        printf("\nEnter value: ");
        scanf("%d",&data);
      }while(data!=-1);
    printf("\nThe hash table is\n");
    display(t);
    }
    else if(ch2==2)   {}
    else
        printf("Invalid choice");
             
   }
  else if(ch1==2)
  {
    printf("Enter the table Size: ");
    scanf("%d",&ltsize);
    lt=create(ltsize);
    printf("\n1.To enter the values\n2.Exit\n\nEnter choice: ");
    scanf("%d",&ch2);
    if(ch2==1)
    {
    printf("Enter -1 to stop\n");
    printf("\nEnter value: ");
    scanf("%d",&data);
    do{
        insertlinear(lt,data);
        //displaylinear(t);
        printf("\nEnter value: ");
        scanf("%d",&data);
      }while(data!=-1);
    printf("\nThe hash table is\n");
    displaylinear(lt);
    }
    else if(ch2==2)   {}
    else
        printf("Invalid choice");
             
   }
 
}while(ch1!=3);
}
