;
/* Author: Bela Jere (belajejre@my.unt.edu)
   Date: 06/01/2023
   Instructor: Dr. Shrestha
   Description: producing user input of vaiables using printf and scanf  
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
//declaring variables
char a;
char b;
int c;
int d;
double e;
double f;

//user input of characters
printf("Enter two characters: ");
scanf(" %c %c",&a,&b);

//user input of integers
printf("Enter two integers: ");
scanf("%d %d",&c,&d);

//user input of real number
printf("Enter two real numbers: ");
scanf("%lf %lf",&e,&f);

//out put user data 
printf("You just entered ");
printf("%c,%c,%d,%d,%lf,%.3E \n",a,b,c,d,e,f);

return 0;
}

