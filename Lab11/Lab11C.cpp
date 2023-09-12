/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 7/11/2023
   Instructor: Dr. Shrestha
   Description: sorting numbers in an array from one file and placing them in another. 
*/
#include <iostream>
#include <fstream>
using namespace std;
/* Function: sorting
   Parameters: the array and the size of the array
   Return: void
   Description: sorting in assending order
*/
void sorting(float arr[],int size)
{
   for (int i=0;i<size;++i) {
      for (int j=i+1;j<size;++j) {
         if(arr[i]>arr[j]){
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
}
int main()
{
   ifstream fin;
   ofstream fout;
   fin.open("unsorted.dat");
   if(fin.fail())
   {
      cout<<"Could not open file"<<endl;
      return 0;
   }
   const int max_size=100;
   int size=0;
   float my_arr[max_size];
   while(fin>>my_arr[size]&&size<max_size)
   {
      ++size;
   }
   fin.close();

   sorting(my_arr, size);

   fout.open("sorted.dat");
   if(fout.fail())
   {
      cout<<"could not open sorted.dat"<<endl;
      return 0;
   }
   for(int i=0;i<size;++i)
   {
      fout<< my_arr[i]<<endl;
   }
   fout.close();

return 0;
}
