
/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/29/2023
   Instructor: Dr. Shrestha
   Description: Declaring the maximum values in 2 D arrays with functions 
*/

#include <iostream>
using namespace std;

const int COLS = 6;
const int ROWS = 10;

/* Function: max
   Parameters: a float array for the grades, integer number, and a float max
   Return: none
   Description: computing the max
*/
void computeMaximum(float grades[][COLS], int num, float maximum[])
{
  for(int i=0;i<num;++i)
  {
      maximum[i]=grades[i][0];
      for(int j=1;j<COLS;++j)
      {
         if(grades[i][j]>maximum[i])
         {
         maximum[i] = grades[i][j];
         }
      }
   }
}
/* Function: showArray
   Parameters: a float array and a integer size
   Return: none
   Description: displaying the array
*/
void showArray (float array[], int size)
{
   for(int i=0;i<size;++i)
   {
      cout<<array[i]<<" ";
   }
   cout<<endl;
}

int main()
{
   float grades[ROWS][COLS];
   float maximum[ROWS];
   int num;

   cout<<"How many student in the class?";
   cin>>num;

   for(int row = 0;row<num;row++)
   {
      
      for (int col=0; col<COLS;col++)
      {
         cout<<"Enter QUIZ #"<<col+1<<" for STUDENT #"<<row+1<<": ";
         cin>>grades[row][col];
      }
   }
   for(int row=0;row<num;row++)
   {
      for(int col=0; col<COLS;col++)
      {
         cout<<grades[row][col]<<" ";
      }
      cout<<endl;
   }
   computeMaximum(grades,num,maximum);
   cout<<"The maximum grades:\n";
   showArray(maximum,num);
   return 0;
}

