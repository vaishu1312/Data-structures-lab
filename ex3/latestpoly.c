#include <stdio.h>
#include <malloc.h>
#include "polyadt.h"
void main()
{
int option;
polynomial poly1,poly2,sum_poly,pro_poly;
do
{
printf("\n******* MAIN MENU *******");
printf("\n 1. Enter the first polynomial");
printf("\n 2. Enter the second polynomial");
printf("\n 3. Add the polynomials");
printf("\n 4. Multiply the polynomials");
printf("\n 5. Display the sum of the polynomials");
printf("\n 6. Display the product of the polynomials: ");
printf("\n 7. Exit");
printf("\nEnter your option : ");
scanf("%d", &option);
switch(option)
{
case 1: poly1 = create_poly();  
break;
case 2: poly2 = create_poly();  
break;
case 3: sum_poly = add_poly(poly1, poly2);
break;
case 4: pro_poly = mul_poly(poly1, poly2);
break;
case 5: printf("\nThe sum of the two polynomials is: ");
        display_poly(sum_poly);
break;
case 6: printf("\nThe product of the two polynomials is: ");
        display_poly(pro_poly);
break;
case 7:
break;
default:
printf("\nInvalid choice\n");
}
printf("\n\nPress 1 to go back to menu\nPress 2 to exit\n");
scanf("%d",&option);
}while(option==1);
}
