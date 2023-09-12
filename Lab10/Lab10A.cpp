/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/29/2023
   Instructor: Dr. Shrestha
   Description: Comparing a random number to a users number using functions 
*/

#include <iostream>
#include <ctime>
using namespace std;

/* Function: getRandom
   Parameters: none
   Return: the random number
   Desription: seeding and storing the random number
*/

int getRandom()
{
   srand(time(0));
   int x;
   x=rand()%101+1;
   return x;
}

/* Function: compare
   Parameters: an integer value for the user guess
   Return: none
   Description: comparing the users guess to the random number
*/

void compare(int guess)
{
   cout<<"Random number: "<<getRandom()<<endl;
   if(getRandom()>guess)
   {
      cout<<"The random number was greater than your guess."<<endl;
   }
   else if(getRandom()<guess)
   {
      cout<<"The random number was less than your guess."<<endl;
   }
   else
   {
      cout<<"The random number was equal to your guess."<<endl;
   }
}

int main()
{
   int guess;
   cout<<"Enter a guess between 1-100: ";
   cin>>guess;
   compare(guess);
   return 0;

}
