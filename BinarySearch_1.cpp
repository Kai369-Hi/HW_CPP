#include <iostream>
using namespace std;

int main(){
    int arr[5] = {10,15,22,13,14};
    int length = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After sorting: " <<endl;
    for(int i=0;i<length;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int start,end,mid,target;
    bool found = false;
    start = 0;
    end = length - 1;
    mid = (start + end)/2;

    cout << "Enter the number to search: ";
    cin >> target;
    cin.ignore();

    // while(!found){
    //     if(target == arr[mid]){
    //         cout << "Number found at index: " << mid << endl;
    //         found = true;
    //     }
    //     else if(target < arr[mid]){
    //         end = mid - 1;
    //     }
    //     else{
    //         start = mid + 1;
    //     }
    //     mid = (start + end) / 2;
    // }

    while(start <= end){
        mid = (start + end) / 2;
        if(target == arr[mid]){
            cout << "Number found at index: " << mid << endl;
            break;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return 0;
    

}