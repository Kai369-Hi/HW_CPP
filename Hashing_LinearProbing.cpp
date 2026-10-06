#include <iostream>
using namespace std;

int HashFunction(int key, int TableSize){
    return key % TableSize;
}

void insert(int HashTable[],int key,int TableSize){
    int index = HashFunction(key,TableSize);
    while(HashTable[index] != -1){
        index++;
        if(index >= TableSize){
            index = 0; // wrap around to the beginning of the table
        }
    }
    HashTable[index] = key;
}

int main(){
    int TableSize = 10,NumberOfKeys = 8;
    int HashTable[10]; 
    int keys[] = {99,5,14,23,45,67,89,12};

    for(int i=0;i<TableSize;i++){
        HashTable[i] = -1; // Initialize hash table with -1 to indicate empty slots
    }

    for(int i=0;i<NumberOfKeys;i++){
        insert(HashTable, keys[i], TableSize);
    }
    for(int i=0;i<TableSize;i++){
        cout<< "Index "<< i <<": "<< HashTable[i] <<endl;
    }

    return 0;

}