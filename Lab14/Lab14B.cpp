/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 07/20/2023
   Instructor: Dr. Shrestha
   Description:
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct employee
{
   string name;
   double salary;
};

int main()
{
ifstream fin;
fin.open("data.dat");
if(fin.fail())
{
   cout<< "Unable to open file data.dat"<<endl;
   return 0;
}

int numEmployees=0;
employee *mem;
mem = new employee;
double total=0;

while(!fin.eof())
{
   getline(fin,mem->name,',');
   fin>>mem->salary;
   total += mem->salary;
   numEmployees++;
}
fin.close();

double average = total/numEmployees;
cout<<"Average slaray is: "<<average<<endl;

delete mem;
return 0;
}
