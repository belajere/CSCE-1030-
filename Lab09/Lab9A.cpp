/* Author: Bela Jere
   Date: 06/27/2023
   Instructor: Dr. Shrestha
   Description: Computing bonus with functions
*/

#include <iostream>
using namespace std;

double computeBonus(double baseSalary, int experience);

int main()
{
double baseSalary;
int experience;
cout<<"Enter your base salary: "<<endl;
cin>>baseSalary;
cout<<"Enter your years of experience: "<<endl;
cin>>experience;
double bonus = computeBonus(baseSalary,experience);
cout<<"Bonus: "<<bonus<<endl; 

return 0;
}

/* Function: bonus
   Parameters: Base Salary and Years of experience
   Return: Bonus amount
   Description: This function computes the bonus given base salary and years of experience
*/
double computeBonus (double baseSalary, int experience)
{
double bonus;
if (experience>5)
{
   bonus=0.05*baseSalary;
}
else
{
   bonus=0.03*baseSalary;
}

return(bonus);
}
