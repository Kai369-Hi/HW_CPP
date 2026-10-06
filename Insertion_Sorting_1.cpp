#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cout << "Enter 10 elements: ";
        cin >> arr[i];
    }
    cout << "The elements in the unsorted array are: ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }

    int i,j,temp;
    for(i=1;i<10;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout << "\nThe elements in the sorted array are: ";
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    return 0;
}