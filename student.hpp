#include <string>
#include <iomanip>
#include <iostream>

class Student {
private:
    std::string name;
    std::string id;
    std::string gender;
    std::string course;
    

public:
    Student(const std::string& name, const std::string& id, const std::string& gender, const std::string& course)
        : name(name), id(id), gender(gender), course(course) {}

    std::string setName(const std::string& newName) { name = newName; }
    std::string setId(const std::string& newId) { id = newId; }
    std::string setGender(const std::string& newGender) { gender = newGender; }
    std::string setCourse(const std::string& newCourse) { course = newCourse; }

    std::string getName() const { return name; }
    std::string getId() const { return id; }
    std::string getGender() const { return gender; }
    std::string getCourse() const { return course; }

    void ViewStudent() const {
        std::cout << "------------------------------------------------------------------------------------------------------" <<std::endl;
        std::cout << "Student ID: " << id << std::endl;
        std::cout << "Student Name: " << name << std::endl;
        std::cout << "Student Gender: " << gender << std::endl;
        std::cout << "Student Course: " << course << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------" <<std::endl;
    }
};