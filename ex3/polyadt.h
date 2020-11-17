typedef struct poly *ptrtopoly;
typedef ptrtopoly polynomial;

struct poly
{
float coeff;
int exp;
struct poly *next;
};

polynomial Createhead()
{
ptrtopoly head;
head=(polynomial)malloc(sizeof(struct poly));
if(head==NULL)
   printf("\nPolynomial creation error");
else
   head->next=NULL;
return head;
}

polynomial Insert_term(polynomial start, float c, int e)
{
polynomial ptr,new_polynomial;
new_polynomial = (polynomial)malloc(sizeof(struct poly));
new_polynomial -> exp = e;
new_polynomial -> coeff = c;
new_polynomial -> next = NULL;
if(start->next == NULL)
  start->next = new_polynomial;
else
{   
ptr = start->next;
while(ptr->next != NULL)
  ptr = ptr -> next;   
ptr -> next = new_polynomial;
}
return start;
}

void display_poly(polynomial start)
{
polynomial ptr = start->next;
if(ptr==NULL)
  printf("0 ");
while(ptr!= NULL)
{
if(ptr->exp==0)
 printf("%.1f ", ptr -> coeff);
else if (ptr->exp==1)
 printf("%.1f x ", ptr -> coeff);
else
  printf("%.1f x^%d ", ptr -> coeff, ptr -> exp);
if (ptr->next!=NULL)
   if (ptr->next->coeff>0)
      printf("+ ");
ptr = ptr -> next;
}
}

polynomial create_poly()
{
polynomial poly1=Createhead();
polynomial ptr,new_polynomial= NULL;
int e; float c;
printf("\nEnter 0 as the coefficient to stop\n");
printf("\nEnter the coefficient : ");
scanf("%f", &c);
if(c!=0)
{
printf("Enter the exponent : ");
scanf("%d", &e);
}
while(c != 0)
{
new_polynomial = (polynomial)malloc(sizeof(struct poly));
new_polynomial -> coeff = c;
new_polynomial -> exp = e;
new_polynomial -> next = NULL;
if(poly1->next==NULL)
    poly1->next=new_polynomial;
else
{
ptr = poly1->next;
while(ptr -> next != NULL)
   ptr = ptr -> next;
ptr -> next = new_polynomial;
}
printf("\nEnter its coefficient : ");
scanf("%f", &c);
if(c!=0)
 { printf("Enter the exponent : ");
  scanf("%d", &e);
 }
}
printf("\nThe polynomial is: ");
display_poly(poly1);
return poly1;
}


polynomial add_poly(polynomial poly1, polynomial poly2)
{
polynomial ptr1,ptr2,new_poly,res_poly;
float sum_num;
res_poly = Createhead();
printf("\nDisplaying First Polynomial:");
display_poly(poly1);
printf("\nDisplaying Second Polynomial:");
display_poly(poly2);

ptr1 = poly1->next;
ptr2 = poly2->next;
while(ptr1 != NULL && ptr2 != NULL)
{ 
if(ptr1 -> exp == ptr2 -> exp)
{ 
  sum_num = ptr1 -> coeff + ptr2 -> coeff;
  res_poly=Insert_term(res_poly, sum_num, ptr1 -> exp);
  ptr1=ptr1->next;
  ptr2=ptr2->next;
}
else if(ptr1 -> exp > ptr2 -> exp)
{ 
  res_poly=Insert_term(res_poly,ptr1->coeff,ptr1 -> exp);
  ptr1=ptr1->next;
}
else if(ptr1 -> coeff < ptr2 -> coeff)
{ 
 res_poly=Insert_term(res_poly,ptr2 ->coeff,ptr2->exp);
 ptr2 = ptr2 -> next;
}
}
while(ptr2 != NULL)
{ 
res_poly = Insert_term(res_poly, ptr2 -> coeff, ptr2 -> exp);
ptr2 = ptr2 -> next;
}
while(ptr1 != NULL)
{ 
res_poly = Insert_term(res_poly, ptr1 -> coeff, ptr1 -> exp);
ptr1 = ptr1 -> next;
}
return res_poly;
}


polynomial mul_poly(polynomial h1,polynomial h2)
{
float res=0;
polynomial temp1,temp2,res_poly,h3;
printf("\nDisplaying First Polynomial:");
display_poly(h1);
printf("\nDisplaying Second Polynomial:");
display_poly(h2);

h3=Createhead();
res_poly=Createhead();

temp1=h1->next;
while(temp1!=NULL)
{
temp2=h2->next;
while(temp2!=NULL)
{
h3=Insert_term(h3,temp1->coeff*temp2->coeff,temp1->exp+temp2->exp);
temp2=temp2->next;
}
temp1=temp1->next;
}
printf("\nDisplaying Initial Result of Product:");
display_poly(h3);

temp1=h3->next;
while(temp1!=NULL)
{
temp2=temp1->next;
res=0;
while(temp2!=NULL)
{
if(temp1->exp==temp2->exp)
    res += temp2->coeff;
temp2=temp2->next;
}
if(search(res_poly,temp1->exp)==0)  //temp1->exp not found
    res_poly=Insert_term(res_poly,res+(temp1->coeff),temp1->exp);
temp1=temp1->next;
}
return res_poly;
}

int search(polynomial h,int val)
{
polynomial tmp=h->next;
while(tmp!=NULL)
{
 if(tmp->exp==val)
     return 1;
 tmp=tmp->next;
}
return 0;
}

