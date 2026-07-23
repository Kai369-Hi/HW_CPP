#include <iostream>
#include <array>
#include <string>
#include <limits>
using namespace std;
int main() {
    string name[3];
    double marks[3][3]; // rows for students, columns for subjects
    double total_marks[3] = {0}; // to store total marks for each student
    double average_marks[3] = {0}; // to store average marks for each student

    for (int i=0; i<3;i++){
        cout << "Enter name of student " << i+1 << ": ";
        getline(cin, name[i]);
        for (int j=0; j<3; j++){
            cout << "Enter marks for subject " << j+1 << " for " << name[i] << ": ";
            cin >> marks[i][j];
            total_marks[i] += marks[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        average_marks[i] = total_marks[i] / 3;
    }

    for (int i=0; i<3; i++){
        cout << "\nStudent Name: " << name[i] << endl;
        for (int j=0; j<3; j++){
            cout << "Marks for subject " << j+1 << ": " << marks[i][j] << endl;
        }
        cout << "Total Marks: " << total_marks[i] << endl;
        cout << "Average Marks: " << average_marks[i] << endl;
    }
    return 0;

}