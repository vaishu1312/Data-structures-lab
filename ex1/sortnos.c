#include<stdio.h>

int* input(int n)
{ int i;
  static  int a[30];
  printf("Enter the values: ");
 for(i=0;i<n;i++)
   scanf("%d",&a[i]);
 return a;
}

void display(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
    printf("%d ",a[i]);
 printf("\n");
}

int* insertion(int a[],int n)
{
 int i,j,key;
 for(i=1;i<n;i++)
 {
  key=a[i];
  j=i-1;
  while((j>=0) && (a[j]>key))
  {
   a[j+1]=a[j];
   j=j-1;
  }
 a[j+1]=key;
 }
 return a;
}


void main()
{
 int n,*arr;
 printf("Enter the no of values: ");
 scanf("%d",&n);
 arr=input(n);
 arr=insertion(arr,n);
 printf("The sorted array is(using insertion sort): ");
 display(arr,n);
}

