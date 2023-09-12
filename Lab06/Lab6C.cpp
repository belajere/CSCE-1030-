
/* Author: Bela Jere(belajere@my.unt.edu)
   Date: 06/13/2023
   Instrucotr: Dr. Shrestha
   Description: finding minimum value of rows and columns using nested for-loops
*/

#include <iostream>
using namespace std;
int main() {

const int ROW_SIZE=2;
const int COLUMN_SIZE=5;
int matrix[ROW_SIZE][COLUMN_SIZE];
int i=0;
int j=0;
int min_row[ROW_SIZE];
int min_column[COLUMN_SIZE];

for(int i=0;i<ROW_SIZE;i++)
{
   for(int h=0;h<COLUMN_SIZE;h++)
   {
      cout<<"Enter data for row#"<<i+1<<" and column#"<<h+1<<":";
      cin>>matrix[i][h];
   }
}
cout<<"You entered: "<<endl;
for(int i=0;i<ROW_SIZE;++i)
{
   for(int h=0; h<COLUMN_SIZE; ++h)
   {
      cout<<matrix[i][h]<<"\t";
   }
   cout<<endl;
}

for(int i=0;i<ROW_SIZE;i++)
{
min_row[i]=matrix[i][0];
   for(int j=0;j<COLUMN_SIZE;j++)
   {
      if(min_row[i]>matrix[i][j])
      {
         min_row[i]=matrix[i][j];
      }
   }
}

for(int j=0;j<COLUMN_SIZE;j++)
{
min_column[j]=matrix[0][j];
   for(int i=0;i<ROW_SIZE;i++)
   {
      if(min_column[j]>matrix[i][j])
      {
         min_column[j]=matrix[i][j];
      }
   }
}

for(int i=0;i<ROW_SIZE;i++) {
cout<< "Minumum of row " << i+1<<": ";
cout<< min_row[i]<<endl;
}

for(int j=0;j<COLUMN_SIZE;j++) {
cout<< "Minumum of column "<<j+1<<": ";
cout<< min_column[j]<<endl;
}

return 0;

}
