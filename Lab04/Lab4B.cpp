/* Author:  Bela Jere (belajere@my.unt.edu)
   Date: 06/06/2023
   Instructor: Dr. Sreshtha
   Description: Nested if-else statements
*/


#include <iostream>
using namespace std;

int main()
{

//declaring variables
   double a;
   int b;
   char c;
   double d;

//getting input from user
   printf("Enter your salary: ");

   scanf(" %lf",&a);

   printf("Enter number of years of expierence: ");

   scanf(" %d",&b);

   printf("Enter performance level: ");

   scanf(" %c",&c);

   if (c == 'y' or c == 'Y')
{
	if(b > 9)
	{
	   d = a * 0.10;
	   printf("$");
           printf("%.2lf \n",d);
	}
	else
	{
	   d = a * 0.050;
	   printf("$");
           printf("%.2lf \n",d);
	}
}
   else
{
	if(b > 9)
	{
	   d = a * 0.030;
	   printf("$");
	   printf("%.2lf \n",d);
	}
	else
	{
	   printf("No bonus for you :( ");
	}
}
return 0;
}
