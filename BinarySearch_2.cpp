#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void binarySearch(list<int> &data, int target){
        int comparisons=0, start=0, end=data.size()-1, mid;
        while(start<=end){
            mid=(start+end)/2;

            list<int>::iterator it = data.begin();
            advance(it, mid);

            comparisons++;

            if(*it==target){
                cout << "List size: " << data.size() <<endl;
                cout << "Search value: " << target <<endl;
                cout << "Result: Element found" <<endl;
                cout << "Comparisons: " << comparisons <<endl;
                cout <<endl;
                return;
            }
            else if(*it<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        cout << "List size: " << data.size() <<endl;
        cout << "Search value: " << target <<endl;
        cout << "Result: Element not found" <<endl;
        cout << "Comparisons: " << comparisons <<endl;
}

int main(){
    list<int> list1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    list<int> list2,list3,list4;

    for(int i=1;i<=10000;i++){
        if(i<=100){
            list2.push_back(i);
        }
        if(i<=1000){
            list3.push_back(i);
        }
        if(i<=10000){
            list4.push_back(i);
        }
    }

    int target,num1,num2,num3,num4;
    cout << "Enter the number to search: ";
    cin >> target;
    cin.ignore();

    num1 = (target/1000)*10;
    num2 = target/100;
    num3 = target/10;
    num4 = target;

    

    cout << "========== BINARY SEARCH ==========" <<endl;
    binarySearch(list1,num1);
    binarySearch(list2,num2);
    binarySearch(list3,num3);
    binarySearch(list4,num4);

    return 0;

}