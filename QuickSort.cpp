#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int arr[],int start,int end){
    int pivot = arr[end];
    int pIndex = start;
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex],arr[end]);
    return pIndex;
}

void QuickSort(int arr[],int start,int end){
    if(start<end){
        int p = Partition(arr,start,end);
        QuickSort(arr,start,p-1);
        QuickSort(arr,p+1,end);
    }
    return;
}

int main(){
    int len = 5;
    int myarr[5] = {4,6,1,2,7};
    cout << "Before sorting: ";
    for(int i=0;i<len;i++){
        cout<<myarr[i]<<" ";
    }
    cout << endl;

    QuickSort(myarr,0,len-1);
    cout << "After sorting: ";
    for(int i=0;i<len;i++){
        cout<<myarr[i]<<" ";
    }
    cout << endl;
    return 0;
}