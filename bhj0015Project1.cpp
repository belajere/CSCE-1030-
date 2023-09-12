#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {

// header
cout<<"+---------------------------------------------------------------+"<<endl;
cout<<"|               Computer Science and Engineering                |"<<endl;
cout<<"|                CSCE 1030 - Computer Science I                 |"<<endl;
cout<<"|              Bela Jere bhj0015 bhj0015@my.unt.edu             |"<<endl;
cout<<"+---------------------------------------------------------------+"<<endl;

//variable
int userPoints = 100;
enum state {displayLeft=1,displayRight=2,Guess=3,Change=4,Exit=5};
bool valid = false;
int menu;
int userGuess;
bool bound1 = false;
bool bound2 = false;

//name - creates an error if anything other than spaces or lettes. Capatilizes first intials and lowercase for all other letters.
string name;

cout<<"Enter your name: "<<endl;
getline(cin,name);

while (!valid){
   valid = true;
   for(int i=0;i<name.size();++i) {
      if(!isalpha(name.at(i))&&!isspace(name.at(i)))  {
         valid = false;
         cout<<"Error - please re-enter your name only using letters and spaces."<<endl;
         getline(cin,name);
         break;
      }
      else {
         if(isalpha(name.at(i))) {
            if(i==0) {
               name.at(i)=toupper(name.at(i));
            }
            else if (isspace(name.at(i-1))) {
               name.at(i)=toupper(name.at(i));
            }
            else {
               name.at(i)=tolower(name.at(i));
            }
	         }
      }
   }
}

//generate seeded random numbers between 100-200
srand(time(0));

int rand1 = rand()%101+100;
int rand2 = rand()%101+100;

//generating random numbers until the first is less than the second
while(!(rand1 < rand2)) {
   rand2 = rand()%101+100;
   rand1 = rand()%101+100;
}

//bounds for guesses
int displayLowerBound = -1;
int displayUpperBound = -1;

//Menu displayed to user
while(userPoints>-1) {
cout<<displayLowerBound<<"          "<<displayUpperBound<<endl;
cout<<"Menu:"<<endl<<"Type (1) to display the lower bound"<<endl<<"Type (2) to display the upper bound"<<endl<<"Type (3) to make a guess"<<endl<<"Type (4) to change the random numbers"<<endl<<"Type (5) to exit"<<endl;
cout<<"Enter your number: "<<endl;
cin>>menu;
  switch (menu) {
      case 1:
         //first bound
         if (bound2==true) {
            cout<<"You have already displayed the right boundary, you cannot display both boundaries"<<endl;
         }
         else {
            displayLowerBound = rand1;
            cout<<"a correct guess = +1 point"<<endl;
            cout<<"an incorrect guess = -10 points"<<endl;
            bound1=true;
         }
         break;
      case 2:
         //second bound
         if (bound1==true) {
            cout<<"You have already displayed the left boundary, you cannot display both boundaries."<<endl;
         }
         else {
            displayUpperBound = rand2;
            cout<<"a correct guess = +1 point"<<endl;
            cout<<"an incorrect guess = -10 points"<<endl;
            bound2=true;
         }
         break;
       case 3:
         //user guesses
         cout<< "Enter your guess: "<<endl;
         cin>>userGuess;
         if (bound1==true || bound2==true) {
            if (userGuess > rand1 && userGuess < rand2) {
               userPoints = userPoints+1;
               cout<<"You guessed correctly and earn 1 point. "<<"Your remaining points: "<<userPoints<<endl;
            }
            else {
               userPoints = userPoints-10;            }
         }
         else {
            if (userGuess > rand1 && userGuess < rand2) {
               userPoints = userPoints+5;
               cout<<"You guessed correctly and earn 5 points. "<<"Your remaining points: "<<userPoints<<endl;
            }
            else {
               userPoints = userPoints-5;
               cout<<"You guessed incorrectly and lose 5 points. "<<"Your remaining points: "<<userPoints<<endl;
            }
         }
         break;   
      case 4:
         //regenerate random numbers
         while(rand1>rand2) {
            rand2 = rand()%101+100;
            rand1 = rand()%101+100;
         }
         cout<<"New numbers have been generated! "<<endl;
         userPoints = userPoints-1;
         cout<<"Your remaining points: "<<userPoints<<endl;
         break;
       case 5:
         //exit the game
         cout<<"Bye "<<name<<"!"<<endl<<"Your final score is: "<<userPoints<<endl;
         break;
       default:
         //wrong input
         cout<<"Error - Please choose 1,2,3,4,or 5."<<endl;
}
if (menu == 5) {
   break;
}
}
if(!menu == 5) {
cout<<"Bye "<<name<<"!"<<endl; 
cout<<"Your final point balance: "<<userPoints<<endl;
}
if(userPoints<0){
cout<<"You are out of points!!"<<" Bye "<<name<<"!"<<endl;
}
return 0;
}
