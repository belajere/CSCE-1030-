/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/01/2023
   Instructor: Dr. Shrestha
   Description: Comuputing and displaying the bonus earned by an employee
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

//declaring  variables
string name;
double salary;
int rate; 
double bonus;

cout << "Enter full name: " << endl;
getline(cin,name);

cout << "Enter salary: " << endl;
cin >> salary;

cout << "Enter percentage rate of bonus computation" << endl;
cin >> rate;

//calculating bonus 
bonus = salary * (static_cast<double>(rate)/100);

cout << name << " earned a bonus of " << bonus << endl;

return 0;
}
