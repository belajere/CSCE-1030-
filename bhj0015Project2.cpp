#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
enum state {Add=1,Remove=2,Display=3,Search=4,Results=5,Quit=6};
const int numTests = 5;


// Define the structure for student data
struct Student {
    string firstName;
    string lastName;
    int studentID;
    int numTests;
    int* testScores;
};


// Function to get the current number of students in the data file

int getNumber()
{
   ifstream fin;
   fin.open("student.dat");
   if (fin.fail())
   {
        cout<<"File error."<<endl;
        exit(1);
    }
    int count=0;
    string line;
    while(!fin.eof())
    {
        getline(fin, line);
        ++count;
    }
    fin.close();
return(count);
}

// Function to add a student's data to the file
int add_Student()
{
    // Prompt the user for student details
    cout << "Enter the first name: ";
    string firstName;
    cin >> firstName;

    cout << "Enter the last name: ";
    string lastName;
    cin >> lastName;

    cout << "Enter the student ID: ";
    int studentID;
    cin >> studentID;

    cout << "Enter the number of tests taken: ";
    int numTests;
    cin >> numTests;

    // Dynamically allocate memory for test scores array
    int* testScores = new int[numTests];

    for (int i = 0; i < numTests; ++i) {
        cout << "Enter test score " << i + 1 << ": ";
        cin >> testScores[i];
    }

    // Open the data file student.dat and write the data of the student to the file
    ofstream fout;
    fout.open("student.dat",ios::app);
    if(fout.fail())
    {
        cout<<"Unable to open student.dat file for writing";
        return 0;
    }
        // Write data to the file in the specified format
        fout << firstName << "," << lastName << "," << studentID << "," << numTests <<",";
        for (int i = 0; i < numTests; ++i) {
            fout << testScores[i] << ",";
        }
        fout << endl;

        // Close the file
        fout.close();

    	// Deallocate memory for the test scores array
    delete[] testScores;
}

// Function to remove a student from the file based on the student ID

int remove_Student(int studentIDToRemove)
{
    ifstream fin;
    fin.open("student.dat");
    if (fin.fail())
    {
        cout << "Unable to open student.dat for reading" << endl;
        return 0;
    }

    int numStudents = getNumber();

    // Create a dynamic array of the structure type Student
    Student* studentsArray = new Student[numStudents];

    // Read data from the file and store in the dynamic array
    for (int i = 0; i < numStudents; i++)
    {
        getline(fin, studentsArray[i].lastName, ',');
        getline(fin, studentsArray[i].firstName, ',');
        fin >> studentsArray[i].studentID;
        fin.ignore(); // Ignore the comma
        fin >> studentsArray[i].numTests;
        fin.ignore(); // Ignore the comma

        // Dynamically allocate memory for test scores array
        studentsArray[i].testScores = new int[studentsArray[i].numTests];

        for (int j = 0; j < studentsArray[i].numTests; j++)
        {
            fin >> studentsArray[i].testScores[j];
            fin.ignore(); // Ignore the comma or newline character
        }
        fin.ignore();
    }
    fin.close();

    bool studentRemoved = false;
    for (int i = 0; i < numStudents; i++)
    {
        if (studentsArray[i].studentID == studentIDToRemove)
        {
            studentRemoved = true;
            // Deallocate memory for test scores array of the student to be removed
            delete[] studentsArray[i].testScores;
            // Move the last student to the current position to overwrite the removed student
            studentsArray[i] = studentsArray[numStudents - 1];
            // Reduce the number of students after removal
            numStudents--;
            break; // Exit the loop as we found the student to be removed
        }
    }

    if (studentRemoved)
    {
        // Open the file for writing to update the data
        ofstream fout;
        fout.open("student.dat");
        if (fout.fail())
        {
            cout << "Unable to open student.dat for writing" << endl;
            return 0;
        }

        // Write data to the file, excluding the student that was removed
        for (int i = 0; i < numStudents; i++)
        {
            if(!studentsArray[i].lastName.empty() && !studentsArray[i].firstName.empty() && studentsArray[i].studentID != 0)
            {
            fout << studentsArray[i].lastName << "," << studentsArray[i].firstName << "," << studentsArray[i].studentID << "," << studentsArray[i].numTests << ",";
            for (int j = 0; j < studentsArray[i].numTests; j++)
            {
                fout << studentsArray[i].testScores[j];
                fout <<",";
            }
            fout << endl;
            }
            // Deallocate memory for test scores array of each student
            delete[] studentsArray[i].testScores;
        }

        // Close the file
        fout.close();
    }
    else
    {
        cout << "Student with ID " << studentIDToRemove << " does not exist." << endl;
    }

    // Deallocate memory for the dynamic array
    delete[] studentsArray;

    return studentRemoved ? 1 : 0; // Return 1 if student was removed successfully, otherwise 0.
}

int display()
{
    ifstream fin;
    fin.open("student.dat",ios::in);
    if(fin.fail())
    {
        cout<<"Unable to open student.dat"<<endl;
        return 0;
    }

    int numStudents;
    numStudents = getNumber();

    Student *studentsArray = new Student[numStudents];

   // Read data from the file and store in the dynamic array
    for (int i = 0; i < numStudents; i++)
    {
        // Read the full name until a comma is encountered
        getline(fin, studentsArray[i].firstName, ',');
//        fin.ignore(); // Ignore the comma
        getline(fin, studentsArray[i].lastName, ',');
  //      fin.ignore(); //ignore the comma
        fin >> studentsArray[i].studentID;
        fin.ignore(); // Ignore the comma
        fin >> studentsArray[i].numTests;
        fin.ignore(); // Ignore the comma

        // Dynamically allocate memory for test scores array
        studentsArray[i].testScores = new int[studentsArray[i].numTests];

        for (int j = 0; j < studentsArray[i].numTests; j++)
        {
            fin >> studentsArray[i].testScores[j];
            fin.ignore(); // Ignore the comma or newline character
        }
        fin.ignore(); //ignore the newline character??
    }
    fin.close();

    for (int i = 0; i < numStudents; i++) {
if(!studentsArray[i].lastName.empty() && !studentsArray[i].firstName.empty() && studentsArray[i].studentID != 0)
{
        cout.width(30);
        cout << left << studentsArray[i].firstName + "," + studentsArray[i].lastName;
        cout.width(15);
        cout << left << studentsArray[i].studentID;
        for (int j = 0; j < studentsArray[i].numTests; j++)
        {
           cout.width(5);
           cout << left << studentsArray[i].testScores[j];
        }
        //Deallocate memory for testScores array for each student
        delete[] studentsArray[i].testScores;
        cout<<endl;
    }
}
   //Deallocate memory for teh dynamic array
    delete[] studentsArray;
return 0;
}


int search(int studentIDToSearch)
{
    ifstream fin;
    fin.open("student.dat");
    if(fin.fail())
    {
        cout<<"Unable to open student.dat for reading"<<endl;
        return 0;
    }
    int numStudents = getNumber();


    Student* studentsArray = new Student[numStudents];
    bool matchFound = false;

//read the data 
for (int i = 0; i < numStudents; i++)
    {
        getline(fin, studentsArray[i].lastName, ',');
        getline(fin, studentsArray[i].firstName, ',');
        fin >> studentsArray[i].studentID;
        fin.ignore(); // Ignore the comma
        fin >> studentsArray[i].numTests;
        fin.ignore(); // Ignore the comma

        // Dynamically allocate memory for test scores array
        studentsArray[i].testScores = new int[studentsArray[i].numTests];

        for (int j = 0; j < studentsArray[i].numTests; j++)
        {
            fin >> studentsArray[i].testScores[j];
            fin.ignore(); // Ignore the comma or newline character
        }
//        fin.ignore();
    }
fin.close();
for (int i = 0; i < numStudents; i++)
    {
        if (studentsArray[i].studentID == studentIDToSearch)
        {
            matchFound = true;
            cout << studentsArray[i].lastName << "," << studentsArray[i].firstName << "," << studentsArray[i].studentID << "," << studentsArray[i].numTests << ","; 
            for (int j = 0; j < studentsArray[i].numTests; j++)
            {
                cout << studentsArray[i].testScores[j];
                if (j < studentsArray[i].numTests - 1)
                {
                    cout << ",";
                }
            }
            cout<<endl;
            // Deallocate memory for test scores array
            delete[] studentsArray[i].testScores;

        }
    }
        if(!matchFound)
        {
            cout << "Student with ID " << studentIDToSearch << " not found." << endl;
        }

           // Deallocate memory for the dynamic array
    delete[] studentsArray;

    return matchFound ? 1 : 0; // Return 1 if student was removed successfully, otherwise 0.
}

int findMinimum(int *testScores, int numTests)
{
    if (numTests < 5) {
        return 0; // If a student has taken less than 5 tests, the minimum score is 0
    }
    else { //if (numTests == 5) {
        // If a student has taken all 5 tests, find the minimum of the 5 scores in the array
        int minimum = testScores[0];
        for (int i = 1; i < numTests; i++) {
            if (testScores[i] < minimum) {
                minimum = testScores[i];
            }
        }
        return minimum;
    }
}





int exportResults()
{
    ofstream fout;
    fout.open("averages.dat",ios::out);
    if(fout.fail())
    {
        cout<<"Unable to open averages.dat"<<endl;
        return 0;
    }
    ifstream fin;
    fin.open("student.dat",ios::in);
    if(fin.fail())
    {
        cout<<"Unable to open student.dat for reading"<<endl;
        return 0;
    }
    int numStudents = getNumber();
    Student* studentsArray = new Student[numStudents];
    // Read data from the file and store in the dynamic array
for (int i = 0; i < numStudents; i++)
    {
        getline(fin, studentsArray[i].lastName, ',');
        getline(fin, studentsArray[i].firstName, ',');
        fin >> studentsArray[i].studentID;
        fin.ignore(); // Ignore the comma
        fin >> studentsArray[i].numTests;
        fin.ignore(); // Ignore the comma

        // Dynamically allocate memory for test scores array
        studentsArray[i].testScores = new int[studentsArray[i].numTests];

        for (int j = 0; j < studentsArray[i].numTests; j++)
        {
            fin >> studentsArray[i].testScores[j];
            fin.ignore(); // Ignore the comma or newline character
        }
        fin.ignore();
    }
    fin.close();
// Calculate averages and write them to the averages.dat file
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        int minScore = findMinimum(studentsArray[i].testScores, studentsArray[i].numTests);
        double average = 0;
        for (int j = 0; j < studentsArray[i].numTests; j++) {
            sum += studentsArray[i].testScores[j];
        }
        sum = sum-minScore;
        if(minScore==0)
        {
           average = static_cast<double>(sum)/5;
        }
        else {
           average = static_cast<double>(sum) /((studentsArray[i].numTests)-1);
        }
        if(!studentsArray[i].lastName.empty() && !studentsArray[i].firstName.empty() && studentsArray[i].studentID != 0)
        {
        // Write student ID and average to the averages.dat file
        fout << studentsArray[i].studentID << "      " << fixed << setprecision(1) << average << endl;
        }
        // Deallocate memory for test scores array
        delete[] studentsArray[i].testScores;
    }
    // Deallocate memory for the dynamic array
    delete[] studentsArray;
    // Close the averages.dat file
    fout.close();

cout<<"Results exported to averages.dat"<<endl;
return 0;
}

int main()
{

    cout<<"+---------------------------------------------------------------+"<<endl;
    cout<<"|               Computer Science and Engineering                |"<<endl;
    cout<<"|                CSCE 1030 - Computer Science I                 |"<<endl;
    cout<<"|              Bela Jere bhj0015 bhj0015@my.unt.edu             |"<<endl;
    cout<<"+---------------------------------------------------------------+"<<endl;

    int menu;
    cout<<"1. Add"<<endl<<"2. Remove"<<endl<<"3. Display"<<endl<<"4. Search"<<endl<<"5. Results"<<endl<<"6. Quit"<<endl;
    cout<<"Enter choice: ";
    cin>>menu;
    int studentID;
    switch (menu) {
        case 1:
            add_Student();
            break;
        case 2:
            //int studentID;
            cout << "Enter the student ID to remove: ";
            cin >> studentID;
            remove_Student(studentID);
            break;
        case 3:
            display();
            break;
        case 4:
            //int studentID;
            cout<<"Enter ID of student to search: "<<endl;
            cin>>studentID;
            search(studentID);
            break;
        case 5:
            exportResults();
            break;
        case 6:
            cout<<"Bye!"<<endl;
            break;
        default:
            cout<<"Please enter a number from the menu above. "<<endl;
    }
 return 0;
}
