/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 7/11/2023
   Instructor: Dr. Shrestha
   Description: Outputting contents of a file using get(c)
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
   char c;
   ifstream in_s;
   char input_file[15];
   cout<<"Enter the name of the input file: ";
   cin>>input_file;

   in_s.open(input_file);
   if(in_s.fail())
   {
      cout<<"Unable to open input file "<<input_file<<endl;
      exit(EXIT_FAILURE);
   }
   cout<<"*** Here are the conents of the input file ***"<<endl;

   while(!in_s.eof())
   {
      in_s.get(c);
      cout<<c;
   }

   cout<<endl<<"*** Done writing the contents of the file ***"<<endl;

   in_s.close();

   return 0;
}
