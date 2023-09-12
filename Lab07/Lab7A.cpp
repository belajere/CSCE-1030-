/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/20/2023
   Instructor: Dr.Shrestha
   Description: creating random numbers and converting to characters
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main () {

int arr[5];
int i;
srand(time(0));
for(i=0;i<5;i++) {
    arr[i] = rand()%26+65;
}
for(i=0;i<5;i++) {
cout<<static_cast<char>(arr[i]);
}
cout<<endl;
return 0;
}


