/* Author: Bela Jere (belajere@my.unt.edu) 
   Date: 05/30/2023 
   Instructor: Dr. Shrestha
   Description: Calculating volume of a sphere. 
*/ 

#include <iostream> 
using namespace std; 
#include <cmath>
int main()
{ 
float pi ;
pi= 3.14159;
float radius;
float volume;
cout << "Enter the radius of the sphere (in cm):";
cin >> radius;
volume = 4.0/3.0 * pi *pow(radius,3);
cout << "The volume of the sphere is: "; 
cout << volume << endl; 

return 0;
}
