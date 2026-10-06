#include <iostream>
using namespace std;

int main(){
    int Max;
    bool valid=false;
    cout << "Enter the number of elements in the array: ";
    cin >> Max;
    int arr[Max];
    for(int i=0;i<Max;i++){
        cout << "Enter the elements of the array: ";
        cin >> arr[i];
    }

    int temp;
    for(int i=0;i<Max-1;i++){
        for(int j=1;j<Max-i;j++){
            if(arr[j-1]>arr[j]){
                valid=true;
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    if(!valid){
        cout << "\nThe array is already sorted.";
    }
    else{
        cout << "\nThe elements in the sorted array are: ";
        for(int i=0;i<Max;i++){
            cout << arr[i] << " ";
        }
    }
    return 0;
}