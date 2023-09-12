/* Author: Bela Jere (belajeree@my.unt.edu)
   Date: 06/08/2023
   Instructor: Dr. Shrestha
   Description: finding a substring within a string
*/

#include <iostream>
using namespace std;

int main() {
  string my_str = "Welcome to CSCE 1030 lab. We will search inside C++ strings.";
  string substring;

  cout << "Enter a sub-string" << endl;
  cin >> substring;

  int location=my_str.find(substring);

  if (location >= 0 && location < my_str.size()-1) {
	cout << "Location is valid - " << location << endl; 
  }
  else {
	cout << "error - Location is not valid" << endl;
  }

return 0;
}

