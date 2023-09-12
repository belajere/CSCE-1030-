/* Author: Bela Jere(belajere@my.unt.edu)
   Date:7/11/2023
   Instructor: Dr.Shrestha
   Description: storing the average of numbers in one file into another.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

   ifstream inFS;
   ofstream tFS;
   int var1;
   int var2;
   int var3;
   int var4;
   float average;
   inFS.open("data.dat");
   if(inFS.fail())
   {
      cout<<"Could not open file data.dat."<<endl;
      return 0;
   }
   tFS.open("average.dat");
      if(tFS.fail())
      {
         cout<<"Could not open file average.dat"<<endl;
         return 0;
      }

   while(inFS>>var1>>var2>>var3>>var4)
   {
      //inFS>>var1;
      //inFS>>var2;
      //inFS>>var3;
      //inFS>>var4;
      average = (static_cast<float>(var1+var2+var3+var4))/4.0;
      tFS<<fixed<<setprecision(2)<<average<<endl;
  }
  inFS.close();
  tFS.close();
return 0;
}
