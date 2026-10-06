#include <iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    int i = left; // starting index for left subarray
    int j = mid + 1; // starting index for right subarray
    int k = left; // starting index for temporary array

    int temp[right - left + 1]; // temporary array to hold merged elements

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i]; //arr[i] is smaller than arr[j]
            i++;
        }
        else{
            temp[k] = arr[j]; //arr[j] is smaller than arr[i]
            j++;
        }
        k++;

    }
    while(i<=mid){
        temp[k]=arr[i]; // copying all elements from left subrray to temp as it is
        i++;
        k++;
    }
    while(j<=right){
        temp[k]=arr[j]; // copying all elements from right subrray to temp as it is
        j++;
        k++;
    }
    // Copy the merged elements back to the original array
    for(int s = left; s <= right; s++){
        arr[s] = temp[s];
    }

}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    return;
    
}

int main(){
    int len = 5;
    int myarr[len] = {4,6,1,2,7};
    cout << "Before sorting: ";
    for(int i=0;i<len;i++){
        cout<<myarr[i]<<" ";
    }
    cout << endl;
    mergeSort(myarr,0,len-1);
    cout << "After sorting: ";
    for(int i=0;i<len;i++){
        cout<<myarr[i]<<" ";
    }
    cout << endl;

    return 0;
}