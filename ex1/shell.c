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

int* shell(int a[],int n)
{
 int incr,i,j,tmp;
 for(incr=n/2;incr>0;incr/=2)
 { 
   for(i=incr/2;i<n;i++)
   {   tmp=a[i];
       for(j=i;j>=incr;j-=incr)
       {
          if(tmp<a[j-incr])
             a[j]=a[j-incr];
          else
             break;
       }
       a[j]=tmp;
    }
  }
 return a;
}

 

void main()
{
 int n,*arr;
 printf("Enter the no of values: ");
 scanf("%d",&n);
 arr=input(n);
 arr=shell(arr,n);
 printf("The sorted array is(using shell sort): ");
 display(arr,n);
}

