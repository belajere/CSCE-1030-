/* Author: Bela Jere
   Date: 06/27/2023
   Instructor: Dr. Shrestha
   Description: finding the max value in a single array using functions
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Function: maxValue
   Parameters: an integer array and integer size
   Return: the Max value
   Description: calculating the max value in an  array
*/
int maxValue(int my_arr[],int size)
{
   int max=my_arr[0];
   for(int i=0;i<size;++i) 
   {
      if(my_arr[i]>max)
      {
         max = my_arr[i];
      }
   }
   return max;
}


int main()
{
   int size = 10;
   int my_arr[size];
   srand(time(0));
   for(int i=0;i<size;++i)
   {
      my_arr[i]=rand()%51+50;
      cout<<my_arr[i]<<" ";
   }
   
   int max=maxValue(my_arr,size);
   cout<<"Max value is: "<<max<<endl;


}
