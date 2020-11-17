#include<stdio.h>
#include<stdlib.h>
#include "stackadt.h"

void main()
{
int i,flag=0;
char temp[10];
stack s1=createstack();
printf("Enter the word: ");
scanf("%s", temp);
for(i=0; temp[i]!='\0'; i++)
  push(temp[i], s1);
for(i=0; temp[i]!='\0'; i++)
  if(temp[i] != return_top(s1))
  {
     flag = 1;
     break;
  }
  else  pop(s1);
if(flag == 0)
    printf("The given word %s is a palindrome!\n" ,temp);
else
    printf("The given word %s is not a palindrome!\n",temp);
}


