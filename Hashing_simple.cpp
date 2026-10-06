#include <iostream>
using namespace std;

int HashFunction(int key, int TableSize){
    return key % TableSize;
}

int main(){
    int TableSize = 10,NumberOfKeys = 8;
    int HashTable[10] = {-1}; // Initialize hash table with zeros
    int keys[] = {99,5,14,23,45,67,89,12};

    for(int i=0;i<NumberOfKeys;i++){
        int index = HashFunction(keys[i],TableSize);
        HashTable[index] = keys[i];
    }
    for(int i=0;i<TableSize;i++){
        cout<< "Index "<< i <<": "<< HashTable[i] <<endl;
    }

    return 0;

}