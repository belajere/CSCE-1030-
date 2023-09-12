/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/13/2023
   Instructor: Dr. Shrestha
   Description: Using forloops and arrays to state the amount above average. 
*/

#include <iostream>
using namespace std;
int main() {

const int SIZE=12;
int sum_height=0;
int height[SIZE];
int above_average[SIZE];
double average;
int i = 0;
int n = 0;

for(int i=0;i<SIZE;++i) {
cout<<"Enter height in inches of student #"<<i+1<<":";
cin>>height[i];
sum_height=sum_height+height[i];
}
average = sum_height/SIZE;

//cout<<average<<endl;

int arr[n];
for(i=0;i<SIZE;++i)
  if (height[i]>average){
  above_average[n]=height[i];
  n++;
}

cout<<"You entered:"<<endl;
for(int i=0;i<SIZE;++i) {
   cout<<height[i]<<endl;
}

cout<< "Average is: "<<average<<endl;

cout<<"Above average: "<<endl;
for(int i=0;i<n;i++) {
cout<<above_average[i]<<endl;
}

return 0;

}
