#include <iostream>
using namespace std;
int main() {
    int students[5],total=0,highest=0,lowest=0;
    double average=0;
    int *ptr = students;
    for (int i=0;i<5;i++){
        cout << "Enter marks for student " << i+1 << ": ";
        cin >> students[i];
        total += *(ptr + i);
    }
    average = double(total) / 5;

    highest = *(ptr + 0);
    lowest = *(ptr + 0);
    for (int i=0;i<5;i++){
        if(*(ptr + i)>highest){
            highest = *(ptr + i);
        }
        if(*(ptr + i)<lowest){
            lowest = *(ptr + i);
        }
    }

    cout << "----------------------------------" <<endl;
    for (int i=0;i<5;i++){
        cout << "Enter score for Student" << i+1 << ":" << *(ptr + i) << endl;
    }
    cout << "----------------------------------" <<endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "----------------------------------" <<endl;

    int *ptr2 = students;
    int temp;
    for (int i=0;i<5;i++){
        for (int j=0;j<4-i;j++){
            if(*(ptr2 + j) > *(ptr2 + j+1)){
                temp = *(ptr2 + j);
                *(ptr2 + j) = *(ptr2 + j+1);
                *(ptr2 + j+1) = temp;
            }
        }
    }
    for (int i=0;i<5;i++){
        cout << "Sorted score for Student" << i+1 << ":" << *(ptr2 + i) << endl;
    }
    cout << "Highest: " << *(ptr2 + 4) << endl;
    cout << "Lowest: " << *(ptr2 + 0) << endl;
    cout << "----------------------------------" <<endl;


    return 0;
}