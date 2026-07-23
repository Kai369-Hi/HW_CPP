#include <iostream>
#include <string>
using namespace std;
int main(){
    string name;
    float math_marks, science_marks, english_marks, total_marks, average_marks;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter marks for Math: ";
    cin >> math_marks;
    cout << "Enter marks for Science: ";
    cin >> science_marks;
    cout << "Enter marks for English: ";
    cin >> english_marks;

    total_marks = math_marks + science_marks + english_marks;
    average_marks = total_marks / 3;

    cout << "\nStudent Name: " << name << endl;
    cout << "Math Marks: " << math_marks << endl;
    cout << "Science Marks: " << science_marks << endl;
    cout << "English Marks: " << english_marks << endl;
    cout << "Total Marks: " << total_marks << endl;
    cout << "Average Marks: " << average_marks << endl;
    return 0;
}