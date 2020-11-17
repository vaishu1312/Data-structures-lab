#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "listadt.h"

void main()
{
int n,c,ch;
LIST l;
char k[50];

printf ("\nEnter the maximum number of books: ");
scanf ("%d",&n);
l=Createn(n);
printf("\nEnter the no of books to be added: ");
scanf ("%d",&n);
l=Input(l,n);
do{
printf("\n\n1.Insert a new book after a given book\n2.Delete a particular book\n3.Search a given book by name\n");
printf("4.Count the number of books under a particular genre\n5.Sort the books by author name and display\n");
printf("6. Display list of books\n7.Exit\nEnter your choice: ");
scanf ("%d",&ch);
switch(ch)
{
case 1:
 Insert(l);
 break;
case 2:
 printf ("\nEnter book name to be deleted: ");
 gets(k);
 Delete (k,l);
 break;
case 3:
 printf ("\nEnter book name to be searched: ");
 gets(k);
 Search(k,l);
 break;
case 4:
 printf ("\nEnter genre to be counted: ");
 gets(k);
 c=Count (k,l);
 printf ("\nNumber of records under the given genre %s : %d",k,c);
 break;
case 5:
 Sort(l);
 break;
case 6:
 Display(l);
 break;
case 7:
  break;
default:
 printf ("\nInvalid choice");
}
printf("\nPress 1 to go back to menu\nPress 2 to exit\n");
scanf("%d",&ch);
}while(ch==1);
}






