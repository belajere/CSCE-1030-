/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 07/20/23
   Instructor: Dr. Shrestha
   Description: finding max value in a dynamic array
*/

#include <iostream>
using namespace std;

/* Function: maxVal
   Parameters: dynamic array, and size
   Retrun: max value
   Description: finding th maximum value in the dynamic array
*/ 
int maxVal(int* arr, int size)
{
   int max = *arr;
   for(int i=0;i<size;++i)
   {
      if(*(arr+i) > max)
      {
	 max = *(arr+i);
      }
   }
return max;
}

int main()
{
int size;
cout<<"Enter size of the array: "<<endl;
cin>>size;
int *numlist=new int[size];

cout<<"Enter the elements: "<<endl;
for(int i=0;i<size;++i)
{
   cin>>*(numlist+i);
}
int max = maxVal(numlist,size);
cout<< "maximum value: "<<max<<endl;

delete[] numlist;

return 0;
}
