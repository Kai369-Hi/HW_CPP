#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Student {
    private:
        string name;
        double marks[3];
    public:
        Student() : name(""){
            for (int i=0;i<3;i++){
                marks[i]=0;
            }
        }
        void setName(const string& studentName) {
            name = studentName;
        }
        void setMarks(int index, double mark) {
            if (index >= 0 && index < 3) {
                marks[index] = mark;
            }
        }
        double getMarks(int index) const {
            return (index >= 0 && index < 3) ? marks[index] : 0;
        }
        string getName() const {
            return name;
        }
        void inputData() {
            cout << "Enter student name: ";
            getline(cin, name);
            for (int i=0;i<3;i++){
                cout << "Enter marks for subject " << i+1 << ": ";
                cin >> marks[i];
                setMarks(i, marks[i]);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        double calculateTotal() const{
            double total=0;
            for (int i=0;i<3;i++){
                total+=getMarks(i);
            }
            return total;
        }
        double calculateAverage() const {
            return calculateTotal()/3;
        }
        void displayReport() const {
            cout << "\nStudent Name: " << getName() << endl;
            for (int i=0;i<3;i++){
                cout << "Marks for subject " << i+1 << ": " << getMarks(i) << endl;
            }
            cout << "Total Marks: " << calculateTotal() << endl;
            cout << "Average Marks: " << calculateAverage() << endl;
        }
};