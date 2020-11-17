#include<stdio.h>
#include<string.h>
typedef struct
{
 int roll;
 char name[40];
 char add[80];
 long mobile;
}student;


student* input(int n)
{
 static student s[50];
 int i;
 for(i=0;i<n;i++)
 {
 printf("\nEnter details of student %d\n",i+1);
 printf("Enter Roll.No: ");
 scanf("%d",&s[i].roll);
 printf("Enter name: ");
 scanf("%s",s[i].name);
 getchar();
 printf("Enter address: ");
 gets(s[i].add);
 printf("Enter mobile number: ");
 scanf("%ld",&s[i].mobile);
 }
 return s;
}

void display(int n,student *record)
{int i;
 printf("\nROLL No NAME       ADDRESS\t\t\t\tMOBILE NUMBER\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",((record+i))->roll);
 printf("%s         ",(record+i)->name);
 printf("%s\t\t",(record+i)->add);
 printf("%ld\n",(record+i)->mobile);
 }
}
 
student* sort(int n,student *record)
{
 int i,j,minidx;
 student temp;
 for(i=0;i<n;i++)
 {
 minidx=i;
 for(j=i+1;j<n;j++)
   if (strcmp((record+minidx)->name,(record+j)->name)>0)
       minidx=j;
 temp=*(record+i);
 *(record+i)=*(record+minidx);
 *(record+minidx)=temp;
 }
 return record;
}


void search(int n,student *record)
{
 char name[50];
 int start=0,end=n-1,mid,flag=0;
 printf("\nEnter name whose mobile no is to be displayed: ");
 scanf("%s",&name);
 while(start<=end)
 {
  mid=(start+end)/2;
  if(strcmp((record+mid)->name,name)==0)
   { printf("\nThe mobile no of %s is %ld\n",(record+mid)->name,(record+mid)->mobile);
     flag=1;
     break;
   }
  else if(strcmp((record+mid)->name,name)>0)
    end=mid-1;
  else if(strcmp((record+mid)->name,name)<0)
    start=mid+1;  
  }
 if (flag==0)
   printf("Student data not found");
}
 
void main()
{
 student *record;
 int n;
 printf("Enter no of students: ");
 scanf("%d",&n);
 record=input(n);
 display(n,record);
 record=sort(n,record);
 display(n,record);
 search(n,record);
}
