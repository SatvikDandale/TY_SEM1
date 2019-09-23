/*
    Write a program to implement a class for book details having the data members book Id, Name, author, price, etc.
    The class has two public functions: getDetails and putDetails.
    Get details of some book from some users and print in tabular format. Also find the total price of all books.
    
    Write the program to extend the book class with dynamic memory allocation by using "new" keyword and object pointers.
*/
#include<bits/stdc++.h>
using namespace std;

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
            
        }
};

int main(){
    
}