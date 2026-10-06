#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next;
};

int HashFunction(int key, int TableSize){
    return key % TableSize;
}

void insert(Node* HashTable[],int key,int TableSize){
    int index = HashFunction(key,TableSize);
    Node *newnode = new Node();
    newnode->key = key;
    newnode->next = nullptr;

    if(HashTable[index] == nullptr){
        HashTable[index] = newnode;
    }
    else{
        newnode->next = HashTable[index];
        HashTable[index] = newnode;
    }
}

void display(Node *HashTable[], int TableSize){
    for(int i=0;i<TableSize;i++){
        cout<< "Index "<< i <<": ";
        Node *current = HashTable[i];
        while(current != nullptr){
            cout<< current->key << " -> ";
            current = current->next;
        }
        cout<< "nullptr" <<endl;
    }
}

int main(){
    int TableSize = 10,NumberOfKeys = 8;
    Node* HashTable[10];
    int keys[] = {99,5,14,23,45,67,89,12};

    for(int i=0;i<TableSize;i++){
        HashTable[i] = nullptr; // Initialize hash table with nullptr to indicate empty slots
    }

    for(int i=0;i<NumberOfKeys;i++){
        insert(HashTable, keys[i], TableSize);
    }
    display(HashTable, TableSize);

    return 0;

}