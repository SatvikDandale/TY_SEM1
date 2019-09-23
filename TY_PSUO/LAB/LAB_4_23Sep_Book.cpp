/*
    Write a program to implement a class for book details having the data members book Id, Name, author, price, etc.
    The class has two public functions: getDetails and putDetails.
    Get details of some book from some users and print in tabular format. Also find the total price of all books.
    
    Write the program to extend the book class with dynamic memory allocation by using "new" keyword and object pointers.
*/
#include<bits/stdc++.h>
using namespace std;
#define id_width 6
#define name_width 20
#define author_width 20
#define price_width 10


class Book{
    private:
        int id;
        float price;
        string name, author;
    public:
        Book(){
            id = 0;
            price = 0;
            name = "";
            author = "";
        }
        Book(int id, float price, string name, string author){
            // Paremeterized contructor
            this->id = id;
            this->price = price;
            this->name = name;
            this->author = author;
        }
        void setDetails(){
            cout<<"\nEnter the Book Id: ";
            cin>>this->id;
            cout<<"Enter the Price of this book: ";
            cin>>this->price;
            cin.ignore();   // Ignore the garbage remaining in the istream.

            cout<<"Enter the Name of the book: ";
            getline(cin, this->name);
            cout<<"Enter the name of the Author of this book: ";
            getline(cin, this->author);
        }
        int getId(){return this->id;}
        float getPrice(){return this->price;}
        string getName(){return this->name;}
        string getAuthor(){return this->author;}
        void putDetails(){
            cout<<setw(id_width)<<this->id;
            cout<<setw(name_width)<<this->name;
            cout<<setw(author_width)<<this->author;
            cout<<setw(price_width)<<this->price<<endl;
        }
        friend float getTotal(Book *, int);
};

float getTotal(Book *list, int count){
    // Iterate through the list and calculate the total price of books.
    int total = 0;
    for(int i=0; i<count; i++)
        total += list[i].price;
    return total;
}

int main(){
    int n;
    cout<<"Enter the number of books:\n";
    cin>>n;
    Book b[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the details for book no "<<i+1<<":\n";
        b[i].setDetails();
    }
    cout<<endl;
    cout<<setw(id_width)<<"BookId";
    cout<<setw(name_width)<<"Book Name";
    cout<<setw(author_width)<<"Book Author";
    cout<<setw(price_width)<<"Book Price"<<endl;
    for(int i=0; i<n; i++)
        b[i].putDetails();
    cout<<"The total cost of all books is: ";
    cout<<getTotal(b, n)<<endl;
}