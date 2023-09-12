/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 7/18/2023
   Instructor: Dr. Shrestha
   Description: Calculating average with structs
*/

#include <iostream>
#include <fstream>
using namespace std;

const int maxRows= 10;
const int maxData = 10;

struct DataRow
{
    int length;
    int data[maxData];
    double average;
};

int main() {

   DataRow rows[maxRows];
   ifstream fin;
   fin.open("data.dat");
   if(fin.fail())
   {
      cout<<"Error opening file."<<endl;
      return 0;
   }

   int rowNumber =0;
   while (fin >> rows[rowNumber].length)
   {
	double sum=0;
      for(int i=0; i<rows[rowNumber].length-1; ++i)
      {
         fin >> rows[rowNumber].data[i];
 	sum += rows[rowNumber].data[i];
      }
      /*double sum=0;
      for (int i=0; i< rows[rowNumber].length; ++i)
      {
         sum += rows[rowNumber].data[i];
      }
*/
      rows[rowNumber].average = sum / (rows[rowNumber].length-1);
      rowNumber++;
   }
   fin.close();

   for(int i=0;i<rowNumber;++i)
   {
      cout<<"Average of row "<<i+1<<": "<<rows[i].average<<endl;
   }
return 0;
}
