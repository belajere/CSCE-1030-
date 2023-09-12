/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/06/2023
   Instructor: Dr. Shrestha
   Description: if-else statements 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

srand(time(0)); // seeding random number

   int x;
   int y = (rand()%(101))+100;

   cout << "Enter a value between 100 and 200, inclusive: ";
   cin >> x;


   if(x < 100 ||  x > 200) 
   {
	cout << "ERROR - Your number is outside the range" << endl;
   }
   else
   {
	cout << "A random number between 100 and 200, inclusive: " << y << endl;

	if (y < x)
	{
	    cout << "your number is greater than the random number." << endl;
	}
	else
	{
	   cout << "your number is less than or equal to the random number." << endl;
	}
   }

   return 0;
}

