/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/20/2023
   Instructor: Dr.Shrestha
   Description: ordering characters in an array
*/



#include <iostream>
using namespace std;

int main () {

char arr[]={'b','f','a','z','m','g','q','t'};

for (int i=0;i<8;++i) {
   for (int j=i+1;j<8;++j) {
      if(arr[i]<arr[j]){
      char temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      }
   }
}

for (int i=0;i<8;++i) {
      cout<<arr[i]<<"\t";
}

cout<<endl;

return 0;
}

