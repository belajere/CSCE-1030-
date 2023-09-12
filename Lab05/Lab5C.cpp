/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/08/2023
   Instructor: Dr. Shrestha
   Description: 
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main () {

string str;
//char ch = str.at(0);
cout << "Enter a string: " << endl;
getline (cin, str);
char ch=str.at(0);
if(isalpha(ch))
 {
	if(!(isupper(ch)))
	{
	cout << "error - first letter is not uppercase" << endl;
        str.at(0)= toupper(str.at(0));
        }
	else
	{
	cout<<"Format is correct"<<endl;
	}
}
else 
{
   cout << "error - please enter an alphabetical letter as the first character" << endl;
}


if(str.at(str.length()-1) == '.')
 {
	
cout << "Yay! This is in the correct format" << endl;
}
else 
{
cout << "error - missing a period at end" << endl;
	str=str+'.';
	//cout << str << endl;
	
}
cout<<str<<endl;


return 0;
}
