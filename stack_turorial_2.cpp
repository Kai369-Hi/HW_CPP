#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    static const int DEFAULT_SIZE = 5;  // used by the default constructor
    string* actions;                    // pointer to the dynamic array
    int capacity;                       // how many actions can be stored
    int top;                            // next free index / element count

public:
    // default constructor
    Stack(){
        capacity = DEFAULT_SIZE;
        actions = new string[capacity];     // allocate memory at run time
        top = 0;
    };
    // parameterized constructor                
    Stack(int size){
        if (size >= 1) {
            capacity = size;
        } 
        else {
            capacity = DEFAULT_SIZE;
        }
        actions = new string[capacity];     // allocate memory at run time
        top = 0;
    };
    // destructor
    ~Stack(){
        delete[] actions;                   // note: delete[] , not delete
        actions = NULL;                     // avoid a dangling pointer
    };

    bool isEmpty(){ return top == 0; };
    bool isFull(){ return top == capacity; };
    void push(string action){
        if (isFull()) {
            cout << "Stack Overflow! Cannot store more than " << capacity << " actions." << endl;
            return;
        }
        actions[top] = action;
        top++;
        cout << "Action added successfully." << endl;
    };
    void pop(){
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to undo." << endl;
            return;
        }
        top--;                                      // move down first
        cout << "Undo: " << actions[top] << endl;   // then read that slot
    };
    void peek(){
        if (isEmpty()) {
            cout << "Stack is empty. No action to view." << endl;
            return;
        }
        cout << "Last Action: " << actions[top - 1] << endl;
    };
    void display(){
        if (isEmpty()) {
            cout << "Stack is empty. No action recorded." << endl;
            return;
        }
        cout << "\n===== ACTION HISTORY =====" << endl;
        int number = 1;
        for (int i = top - 1; i >= 0; i--) {
            cout << number << ". " << actions[i] << endl;
            number++;
        }
    };
    int  count(){ return top; };
    void clear(){
        top = 0;
        cout << "All actions cleared." << endl;
    };
    int  getCapacity(){ return capacity; };
};

void showMenu() {
    cout << "\n===== TEXT EDITOR =====" << endl;
    cout << "1. Perform Action" << endl;
    cout << "2. Undo Last Action" << endl;
    cout << "3. View Last Action" << endl;
    cout << "4. Display All Actions" << endl;
    cout << "5. Count Actions" << endl;
    cout << "6. Clear All Actions" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    int size;
    cout << "Enter stack capacity: ";
    cin >> size;

    Stack editor(size);         // parameterized constructor

    int choice;
    string action;

    do {
        showMenu();
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\nEnter action: ";
                getline(cin, action);   // getline allows spaces in the action
                if (action.empty()) {
                    cout << "Action cannot be empty." << endl;
                } else {
                    editor.push(action);
                }
                break;

            case 2:
                cout << endl;
                editor.pop();
                break;

            case 3:
                cout << endl;
                editor.peek();
                break;

            case 4:
                editor.display();
                break;

            case 5:
                cout << "\nTotal actions: " << editor.count()
                     << " / " << editor.getCapacity() << endl;
                break;

            case 6:
                cout << endl;
                editor.clear();
                break;

            case 7:
                cout << "\nExiting Text Editor. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter 1 to 7." << endl;
        }

    } while (choice != 7);

    return 0;   // the destructor runs automatically here
}