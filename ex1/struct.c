#include<stdio.h>
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
 printf("\nROLL No NAME       ADDRESS\t\t\t\t\tMOBILE NUMBER\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",((record+i))->roll);
 printf("%s         ",(record+i)->name);
 printf("%s\t\t",(record+i)->add);
 printf("%ld\n",(record+i)->mobile);
 }
}

void search(int n,student *record)
{
 char name[50];
 int flag=0,i;
 printf("\nEnter name whose mobile no is to be displayed: ");
 scanf("%s",&name);
 for(i=0;i<n;i++)
 {
  if(strcmp(name,(record+i)->name)==0)
   { printf("\nThe mobile no of %s is %ld\n",(record+i)->name,(record+i)->mobile);
     flag=1;
     break;
    }
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
 search(n,record);
}
