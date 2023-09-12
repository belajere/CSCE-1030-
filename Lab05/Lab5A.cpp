/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 06/08/2023
   Instructor: Dr. Shrestha
   Description: Outputting messages using switch case.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
   enum season {fall='F', spring='G', summer='S', winter='W'};
   char blank;
   cout << "Enter 's' for summer, 'f' for fall, 'w' for winter, or 'g' for spring'" << endl;
   cin >> blank;
   blank = toupper(blank);

   switch(blank) {
      case fall:
	cout << "The weather looks good" << endl;
	break;
      case summer:
	cout << "It is rather hot outside" << endl;
	break;
      case spring:
	cout << "The flowers are blooming" << endl;
	break;
      case winter:
	cout << "It is rather cold outside." << endl;
	break;
      default:
	cout << "Wrong choice." << endl;
	break;
}

  return 0;
}

