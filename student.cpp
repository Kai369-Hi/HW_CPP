#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        string student_ID;
        string course;
    public:
        Student() : name(""),student_ID(""),course(""){}
        Student(const string& student_name, const string& student_id, const string& student_course): name(student_name),student_ID(student_id),course(student_course){}

        void setName(const string& student_name){
            name=student_name;
        }
        void setID(const string& student_id){
            student_ID=student_id;
        }
        void setCourse(const string& student_course){
            course=student_course;
        }

        string getName() const { return name; }
        string getID() const { return student_ID; }
        string getCourse() const { return course; }

        void IntroduceYourself() const {
            cout << "Name - " << name << endl;
            cout << "Student ID - " << student_ID << endl;
            cout << "Course - " << course << endl;
        }

};

int main() {
    Student student1("John Doe","S0001","Computer Science");
    student1.IntroduceYourself();
    Student student2;
    student2.setName("Peter Li");
    student2.setID("S0002");
    student2.setCourse("Information Technology");
    student2.IntroduceYourself();
    return 0;
}