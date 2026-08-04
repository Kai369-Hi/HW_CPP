#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int x = 10;
    int* ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;

    *ptr = 50;
    cout << "New value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;

    return 0;
}
