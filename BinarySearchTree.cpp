#include <iostream>
using namespace std;

struct Node{
    int Data;
    Node *Left;
    Node *Right;
    Node(int data): Data{data},Left{nullptr},Right{nullptr}{};
};

Node* insertNode(Node *root, int value, bool &inserted){
    if(root == nullptr){ // found an empty spot
        inserted = true;
        return new Node(value);
    }
    if(value < root->Data){
        root->Left = insertNode(root->Left, value, inserted); // go left
    }
    else if(value > root->Data){
        root->Right = insertNode(root->Right, value, inserted); // go right
    }
    return root; // equal -> duplicate, inserted stays false
}

bool searchNode(Node *root, int value){
    if(root == nullptr) return false; // reached the end, not found
    if(value == root->Data) return true;
    if(value < root->Data) return searchNode(root->Left, value);
    return searchNode(root->Right, value);
}

Node* findMin(Node *root){
    while(root->Left != nullptr){
        root = root->Left; // smallest is always the far left
    }
    return root;
}

Node* removeNode(Node *root, int value, bool &removed){
    if(root == nullptr) return nullptr; // not found
    if(value < root->Data){
        root->Left = removeNode(root->Left, value, removed);
    }
    else if(value > root->Data){
        root->Right = removeNode(root->Right, value, removed);
    }
    else{ // found the node to remove
        removed = true;
        if(root->Left == nullptr){ // 0 child or only right child
            Node *temp = root->Right;
            delete root;
            return temp;
        }
        if(root->Right == nullptr){ // only left child
            Node *temp = root->Left;
            delete root;
            return temp;
        }
        Node *successor = findMin(root->Right); // 2 children
        root->Data = successor->Data; // copy successor value up
        bool dummy = false;
        root->Right = removeNode(root->Right, successor->Data, dummy); // delete the successor
    }
    return root;
}

void display(Node *root){ // inorder: left -> self -> right
    if(root == nullptr) return;
    display(root->Left);
    cout << root->Data << " ";
    display(root->Right);
}

void freeTree(Node *root){
    if(root == nullptr) return;
    freeTree(root->Left);
    freeTree(root->Right);
    delete root;
}

int main(){
    Node *root = nullptr;
    bool ok = false;
    int choice, value;
    do{
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter numbers to insert (type a letter to stop): ";
                while(cin >> value){
                    ok = false; // reset the flag before every call
                    root = insertNode(root, value, ok);
                    if(ok) cout << value << " inserted." << endl;
                    else cout << value << " is duplicate. Not inserted." << endl;
                }
                cin.ignore();
                break;
            case 2:
                cout << "Enter a number to search: ";
                cin >> value;
                if(searchNode(root, value)) cout << value << " found." << endl;
                else cout << value << " not found." << endl;
                break;
            case 3:
                cout << "Enter a number to remove: ";
                cin >> value;
                ok = false; // reset the flag before every call
                root = removeNode(root, value, ok);
                if(ok) cout << value << " removed." << endl;
                else cout << value << " not found." << endl;
                break;
            case 4:
                cout << "Tree items (ascending): ";
                display(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while(choice != 5);

    freeTree(root);
    return 0;
}