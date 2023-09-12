/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 05/30/2023
   Instructor: Dr. Shrestha
   Description: Calculating an arthimatic equation 
*/
#include <iostream>
using namespace std;

int main()
{
// Decalring  Variables
int var1;
char var2;
float var3; 
float var4; 

//assigning values to var1, var2, var3
var1=40;
var2='J';
var3=4.6;

//computing var4
var4=var3 + var2 % var1; 

//printing out variable 4  and adding new line
cout << var4 << endl;

return 0;
} 
