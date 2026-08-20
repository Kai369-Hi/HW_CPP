#include <iostream>
#include <string>
using namespace std;

int top = -1; // index of the top element (-1 = empty)
string* history;
int maxSize;

bool isEmpty(){ return top == -1; }
bool isFull(){ return top == maxSize - 1; }

void push(string url){
    if(isFull()){
        cout << "History is full. Cannot visit a new page." << endl;
    }
    else{
        top++;
        history[top] = url;
        cout << "Page added successfully." << endl;
    }

}

void pop(){
    if(isEmpty()){
        cout << "History is empty. Cannot go back." << endl;

    }
    else{
        cout << "Going back from: " << history[top] << endl;
        top--;
        if(isEmpty()){
            cout << "No previous page available." << endl;
        }
        else{
            cout << "Current Page: " << history[top] << endl;
        }
    }
}

void peek() {
    if (isEmpty()) {
        cout << "History is empty. No current page." << endl;
    } else {
        cout << "Current Page: " << history[top] << endl;
    }
}

void DisplayHistory() {
    if (isEmpty()) {
        cout << "History is empty." << endl;
    } else {
        cout << "\n===== BROWSING HISTORY =====" << endl;
        int count = 1;
        for (int i = top; i >= 0; i--) {
            cout << count << ". " << history[i] << endl;
            count++;
        }
    }
}

void checkSize() {
    cout << "Total pages in history: " << (top + 1) << endl;
}

void clearHistory() {
    top = -1;
    cout << "Browsing history cleared." << endl;
}

void DisplayMenu(){
        cout << "===== BROWSER HISTORY =====\n" <<
        "1. Visit New Page\n"
        "2. Go Back\n"
        "3. Display Current Page\n"
        "4. Display History\n"
        "5. Check History Size\n"
        "6. Clear History\n"
        "7. Exit\n"
        "Enter your choice:";
}

int main(){
    int choice;
    string url;

    cout << "Enter maximum history size: ";
    cin >> maxSize;
    while (maxSize < 1) {
        cout << "Please enter a positive size: ";
        cin >> maxSize;
    }
    history = new string[maxSize];

    do{
        DisplayMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter webpage: ";
                cin >> url;
                push(url);
                break;
            
            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                DisplayHistory();
                break;

            case 5:
                checkSize();
                break;

            case 6:
                clearHistory();
                break;

            case 7:
                cout << "Exiting browser. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }while(choice !=7);

    delete[] history;
    history = nullptr;
    return 0;
}