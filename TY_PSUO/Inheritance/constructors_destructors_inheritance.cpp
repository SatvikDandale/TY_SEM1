/*
    Implement Constructors and Destructors in inheritance.
*/
#include<bits/stdc++.h>
using namespace std;

class A{
    protected: int a;
    public:
        A(){
            a = 0;
        }
        A(int a){
            this->a = a;
        }
};

class B: public A{
    float b;
    public:
        B(float b, int a):A(a){ // When constructor of B is called, this also calls constructor of A.
            this->b = b;
        }
        B(float b){ // This will implcitly call the default constructor of A.
            this->b = b;
        }
        /*
        We can also call the constructor of A from inside the constructor of B.
        B(float b, int a){
            this->b = b;
            A(a);
        }
        */
       void display(){
           cout<<"b: "<<b<<endl;
           cout<<"a: "<<a<<endl;
       }
};

int main(){
    B b(10.0, 5);
    b.display();
}
