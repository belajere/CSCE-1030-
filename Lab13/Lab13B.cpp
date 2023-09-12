/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 7/18/2023
   Instructor: Dr. Shrestha
   Description: working with pointers and memeory allocation
*/

#include <iostream>
using namespace std;
int main() {
    int my_int = 12;
    int* my_iptr1;
    int* my_iptr2;
    my_iptr1 = &my_int;
    cout << "Value of my_int using variable name: " << my_int <<endl;
    cout << "Address of my_int using variable name: " << &my_int <<endl;
    cout << "Address of my_int using the pointer: " << my_iptr1 <<endl;
    cout << "Value of my_int using the pointer: " << *my_iptr1 <<endl;

    *my_iptr1 = 15;

    cout << "Value of my_int using variable name after dereferencing: " << my_int <<endl;

    my_iptr1 = new int;
    *my_iptr1 = 20;
    cout << "Value of my_int using variable name after dynamic allocation: " << my_int <<endl;
    my_iptr2 = new int;
    my_iptr2 = my_iptr1;
    cout << "Value pointed by my_iptr2: " << *my_iptr2 <<endl;
    delete my_iptr1;
    // delete my_iptr2;

    return 0;
}
