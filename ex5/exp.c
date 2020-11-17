#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#include "intstack.h"
#include "charstack.h"

int getPriority(char x)
{
if(x=='/' || x == '*' || x=='%')
return 1;
else if(x=='+' || x=='-')
return 0;
}

int InfixtoPostfix(char infix[],char postfix[])
{
stack s1=createstack(strlen(infix));
int i=0, j=0;
while(infix[i]!='\0')
{ 
 if(infix[i]=='(')
 {
  push(infix[i],s1);
  i++;
 }
 else if(infix[i] == ')')
 {
   while((return_top(s1)!=-1) && (return_top(s1)!='('))
   {
     postfix[j] = topandpop(s1);
     j++;
   }
   pop(s1);//remove left parenthesis
   i++;
 }
 else if(isdigit(infix[i]) || isalpha(infix[i]))
 {
  postfix[j] = infix[i];
  j++;
  i++;
 }
 else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
 {
  while( (return_top(s1)!=-1) && (return_top(s1)!= '(') &&  (getPriority(return_top(s1)) >= getPriority(infix[i])   )       )
  {
   postfix[j] = topandpop(s1);
   j++;
  }
  push(infix[i],s1);
  i++;
 }
 else
 {
  printf("Invalid element: %c\n",infix[i]);
  return 0;
  }
}

while((return_top(s1)!=-1)) 
{
postfix[j] = topandpop(s1);
j++;
}
postfix[j]='\0';
 
return 1;
}

int evaluate(char postfix[])
{
int i=0;
int op1, op2, value;
int_stack s2=create_int_stack(strlen(postfix));
while(postfix[i] != '\0')
{
 if(isdigit(postfix[i]))
  intpush((int)postfix[i]-48,s2); 
 else
 {
  op2 = int_topandpop(s2);
  op1 = int_topandpop(s2);
  switch(postfix[i])
  {
   case '+':
      value = op1 + op2; break;
   case '-':
      value = op1 - op2; break;
   case '/':
      value = op1 / op2; break;
   case '*':
     value = op1 * op2;  break;
   case '%':
     value = op1 % op2; break;
  }  //end switch
  intpush(value,s2);  
 }  //end else
 i++;
}  //end while
return(int_return_top(s2));
}

void main()
{
int val;
char infix[100],postfix[100];
printf("Enter any infix expression : ");
gets(infix);
if(InfixtoPostfix(infix,postfix))
{ printf("The corresponding postfix expression is : %s\n",postfix);
printf("Enter the postfix expression with the values: ");
gets(postfix);
val = evaluate(postfix);
printf("Value of the postfix expression = %d\n", val);
}
}

