#include <string>
#include <iomanip>
#include <iostream>
#include "student.hpp"
using namespace std;

int main() {
    Student student1("John Doe", "QIU-202504-001234", "Male", "Computer Science");
    student1.ViewStudent();
    Student student2("Jane Smith", "QIU-202504-001235", "Female", "Information Technology");
    student2.ViewStudent();
    Student student3("Alice Johnson", "QIU-202504-001236", "Female", "Software Engineering");
    student3.ViewStudent();
    Student student4("Bob Brown", "QIU-202504-001237", "Male", "Data Science");
    student4.ViewStudent();
    Student student5("Charlie Davis", "QIU-202504-001238", "Male", "Cyber Security");
    student5.ViewStudent();
    Student student6("Emily Wilson", "QIU-202504-001239", "Female", "Artificial Intelligence");
    student6.ViewStudent();
    Student student7("Frank Miller", "QIU-202504-001240", "Male", "Machine Learning");
    student7.ViewStudent();
    Student student8("Grace Lee", "QIU-202504-001241", "Female", "Cloud Computing");
    student8.ViewStudent();
    Student student9("Henry Taylor", "QIU-202504-001242", "Male", "Blockchain Technology");
    student9.ViewStudent();
    Student student10("Isabella Martinez", "QIU-202504-001243", "Female", "Internet of Things");
    student10.ViewStudent();

    return 0;
}