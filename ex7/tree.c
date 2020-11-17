#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include "exptree.h"

void main()
{
char postfix[100];
int i=0;
tree t;
stack s=createstack();
printf("Enter the postfix expression: ");
gets(postfix);
while(postfix[i]!='\0')
{
 if(isalpha(postfix[i]) || isdigit(postfix[i]))
 {
  t=createtree();
  t->element=postfix[i];
  t->left=t->right=NULL;
  push(t,s);
 }
 else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%')
 {
  t=createtree();
  t->element=postfix[i];
  t->right=pop(s);
  t->left=pop(s);
  push(t,s);
 }
 i++;
}
printf("\nPRE ORDER TRAVERSAL\n");
preorder(t);
printf("\nPOST  ORDER TRAVERSAL\n");
postorder(t);
printf("\nIN ORDER TRAVERSAL\n");
inorder(t);
printf("\n");
}

  
