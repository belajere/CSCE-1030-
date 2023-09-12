/* Author: Bela Jere(belajere@my.unt.edu)
   Date: 06/22/2023
   Instrucotr: Dr. Shrestha
   Description: comparing strings using cstring.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {

char str1[300];
char str2[300];

strcpy(str1,"We are completing Lab8 today.");
cout<<"Enter text: "<<endl;

cin.getline(str2,299);

int length_1 = strlen(str1);
int length_2 = strlen(str2);

if(length_1 == length_2) {
   cout<<"The strings are the same length."<<endl;
   if(strcmp(str1,str2)==0) {
      cout<<"The strings are the same."<<endl;
   }
   else {
      cout<<"The strings are not the same."<<endl;
   }
}
else {
   cout<<"The strings are not the same length."<<endl;
   return 0;
}

return 0;
}
