/* Author: Bela Jere
   Date: 06/27/2023
   Instructor: Dr. Shrestha
   Description: Outputting the sum of adjecent integers in an array using functions
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Function: sum of two integers
   Parameters: 2 integers
   return: the sum of the 2 integers
   Description: This funciton computes the sum of two integers
*/
int sumInt(int a, int b)
{
   return a+b;
}

int main()
{

int arraySize = 10;
int array[arraySize];
srand(time(0));
for (int i=0; i<arraySize; ++i)
{
   array[i] = rand()%51+50;
}
cout<<"Original array: "<<endl;
for(int i=0;i<arraySize;++i)
{
   cout<<array[i]<<" ";
}
cout<<endl;

cout<<"Sum of pairs: "<<endl;
for(int i=0; i<arraySize-1; i+=2)
{
   int sum = sumInt(array[i],array[i+1]);
   cout<<sum<<" ";
}
cout<<endl;
return 0;
}


