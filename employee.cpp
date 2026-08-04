#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Employee {
    private:
        string name;
        string employee_id;
        string company;
    public:
        Employee() : name(""),employee_id(""),company("") {}
        // Employee(const string& emp_name, const string& emp_id, const string& emp_company) : name(emp_name), employee_id(emp_id), company(emp_company) {}
        Employee(string e_name, string e_id, string e_company){
            name = e_name;
            employee_id = e_id;
            company = e_company;
        }
        void setName(const string& emp_name) {
            name = emp_name;
        }
        void setEmployeeID(const string& emp_id) {
            employee_id = emp_id;
        }
        void setCompany(const string& emp_company) {
            company = emp_company;
        }
        string getName() const {
            return name;
        }
        string getEmployeeID() const {
            return employee_id;
        }
        string getCompany() const {
            return company;
        }

        void IntroduceYourself() const {
            cout << "Name - " << name << endl;
            cout << "Employee ID - " << employee_id << endl;
            cout << "Company - " << company << endl;
        }
};

int main() {
    Employee employee1("Peter Li","E0001","ABC Company");
    employee1.IntroduceYourself();

    Employee employee[5];
    string input_name, input_id, input_company;
    for(int i=0;i<5;i++){
        cout << "-------------------------------------------------------" <<endl;
        cout << "Enter name for employee " << i+1 << ": ";
        getline(cin, input_name);
        employee[i].setName(input_name);
        cout << "Enter employee ID for employee " << i+1 << ": ";
        getline(cin, input_id);
        employee[i].setEmployeeID(input_id);
        cout << "Enter company for employee " << i+1 << ": ";
        getline(cin, input_company);
        employee[i].setCompany(input_company);
        cout << "-------------------------------------------------------"<<endl;
    }
    for(int i=0;i<5;i++){
        cout << "-------------------------------------------------------"<<endl;
        cout << "Employee " << i+1 << " details:" << endl;
        employee[i].IntroduceYourself();
        cout << "-------------------------------------------------------"<<endl;
    }

    // Employee employee2("","","");
    // for(int i=0;i<5;i++){
    //     cout << "-------------------------------------------------------"<<endl;
    //     cout << "Enter name for employee " << i+1 << ": ";
    //     getline(cin, input_name);
    //     employee2.setName(input_name);
    //     cout << "Enter employee ID for employee " << i+1 << ": ";
    //     getline(cin, input_id);
    //     employee2.setEmployeeID(input_id);
    //     cout << "Enter company for employee " << i+1 << ": ";
    //     getline(cin, input_company);
    //     employee2.setCompany(input_company);
    //     cout << "-------------------------------------------------------"<<endl;
    // }
    // for(int i=0;i<5;i++){
    //     cout << "-------------------------------------------------------"<<endl;
    //     cout << "Employee " << i+1 << " details:" << endl;
    //     employee2.IntroduceYourself();
    //     cout << "-------------------------------------------------------"<<endl;
    // }

    Employee employee3 = Employee("Alice Johnson","E0002","XYZ Corporation");
    employee3.IntroduceYourself();
    return 0;
}