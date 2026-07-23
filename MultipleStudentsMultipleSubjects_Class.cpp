#include <iostream>
#include <string>
#include "SingleStudentMultipleSubjects_Class.h"
using namespace std;
int main() {
    static const int NUM_students = 3;
    Student classroom[NUM_students];

    for (int i=0;i<NUM_students;i++){
        cout << "\nEntering data for student " << i+1 << ":\n";
        classroom[i].inputData();
    }
    for (int i=0;i<NUM_students;i++){
        cout << "----------------------------------" <<endl;
        cout << "\nReport for student " << i+1 << ":\n";
        classroom[i].displayReport();
        cout << "----------------------------------" <<endl;
    }
    classroom[0].setName("John Doe");

    return 0;
}