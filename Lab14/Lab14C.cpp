/* Author: Bela Jere (belajere@my.unt.edu)
   Date: 07/20/2023
   Instructor: Dr. Shrestha
   Description:
*/

#include <iostream>
using namespace std;

void getGrades(int** grades, int num_students, double* averages)
{
    int number_of_tests;

    for (int i = 0; i < num_students; ++i)
    {
        cout << "How many tests for student #" << i + 1 << "? ";
        cin >> number_of_tests;

        grades[i] = new int[number_of_tests];

        for (int j = 0; j < number_of_tests; ++j)
        {
            cout << "Enter test score " << j + 1 << " for student " << i + 1 << ": ";
            cin >> grades[i][j];
        }

        double sum = 0;
        for (int j = 0; j < number_of_tests; ++j)
        {
            sum += grades[i][j];
        }
        averages[i] = sum / number_of_tests;
    }
}

void dispAverage(double* averages, int num_students)
{
    cout << "Average test scores for each student:\n";
    for (int i = 0; i < num_students; ++i)
    {
        cout << "Student " << i + 1 << ": " << averages[i] << endl;
    }
}

int main()
{
    int num_students;
    int** grades;
    double* averages;

    cout << "How many students? ";
    cin >> num_students;


    grades = new int*[num_students];
    averages = new double[num_students];

    getGrades(grades, num_students, averages);
    dispAverage(averages, num_students);

    for (int i = 0; i < num_students; ++i)
    {
        delete[] grades[i];
    }
    delete[] grades;
    delete[] averages;

    return 0;
}
