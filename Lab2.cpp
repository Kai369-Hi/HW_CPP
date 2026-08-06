#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        string Book_ID;
        string Book_Title;
        string Author_Name;
        int Number_of_Copies;
    
    public:
        //Default constructor
        Book():Book_ID{""},Book_Title{""},Author_Name{""},Number_of_Copies{0}{}
        //Parameterized constructor
        Book(string id,string title,string author,int num_copies):Book_ID{id},Book_Title{title},Author_Name{author},Number_of_Copies{0}{
            if(num_copies>=0){
                Number_of_Copies=num_copies;
            }
        }
        //Setter functions
        void setBookID(string id){Book_ID=id;}
        void setBookTitle(string title){Book_Title=title;}
        void setAuthorName(string name){Author_Name=name;}
        void setNumberOfCopies(int number_copies){
            if(number_copies>=0){
                Number_of_Copies=number_copies;
            }
            else{
                Number_of_Copies=0;
            }
        }
        //Getter functions
        string getBookID()const{return Book_ID;}
        string getBookTitle()const{return Book_Title;}
        string getAuthorName()const{return Author_Name;}
        int getNumberOfCopies()const{return Number_of_Copies;}

};

int main(){
    Book book[5];
    book[0]=Book("B101","Data Structures","Mark Allen",8);
    book[1]=Book("B102","C++ Programming","John Smith",12);
    book[2]=Book("B103","Database Systems","Peter Brown",5);
    book[3]=Book("B104","Operating Systems","Linda Tan",9);
    book[4]=Book("B105","Computer Networks","David Lee",7);

    Book *ptr1=book;
    for(int i=0;i<5;i++){
        cout << "--------------------------------------------------------" <<endl;
        cout << "The " << " object " << i+1 << " in the array: " <<endl;
        cout << "Book ID: " << (ptr1+i)->getBookID() << endl;
        cout << "Book Title: " << (ptr1+i)->getBookTitle() << endl;
        cout << "Author Name: " << (ptr1+i)->getAuthorName() << endl;
        cout << "Number of Copies: " << (ptr1+i)->getNumberOfCopies() <<endl;
        cout << "--------------------------------------------------------" <<endl;
    }

    Book *ptr2=book;
    cout << "--------------------------------------------------------" <<endl;
    cout << "Enter Book ID to search: ";
    string search_id;
    bool found=false;
    getline(cin,search_id);
    for(int i=0;i<5;i++){
        if((ptr2+i)->getBookID()==search_id){
            cout << "Book found!" << endl;
            found=true;
            cout << "--------------------------------------------------------" <<endl;
            cout << "Book ID: " << (ptr2+i)->getBookID() << endl;
            cout << "Book Title: " << (ptr2+i)->getBookTitle() << endl;
            cout << "Author Name: " << (ptr2+i)->getAuthorName() << endl;
            cout << "Number of Copies: " << (ptr2+i)->getNumberOfCopies() <<endl;
            cout << "--------------------------------------------------------" <<endl;
            cout << "Enter additional copies: ";
            int new_copies;
            cin >> new_copies;
            if(new_copies>=0){
                new_copies+=(ptr2+i)->getNumberOfCopies();
                (ptr2+i)->setNumberOfCopies(new_copies);
                cout << "--------------------------------------------------------" <<endl;
                cout << "Updated Book Information" <<endl;
                cout << "Book ID: " << (ptr2+i)->getBookID() << endl;
                cout << "Book Title: " << (ptr2+i)->getBookTitle() << endl;
                cout << "Author Name: " << (ptr2+i)->getAuthorName() << endl;
                cout << "Number of Copies: " << (ptr2+i)->getNumberOfCopies() <<endl;
                cout << "--------------------------------------------------------" <<endl;
            }
            else{
                cout << "Invalid input. Number of copies cannot be negative." << endl;
            }
            break;
        }
    
    }
    if(found==false){
        cout << "Book not found." << endl;
    }
    cout << "--------------------------------------------------------" <<endl;


    return 0;
}
    