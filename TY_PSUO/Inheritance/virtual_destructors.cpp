/*
    The order of execution of destructors in an inheritance is necessary to be maintained.
    The derived class's destructor should be called first.
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    int *a;
    public:
        A(){
            a = new int(10);
            cout<<"Constructor of A is called.\n";
        }
        virtual ~A(){
            /*
                A *p = new B;
                delete p;
                
                The above statement will call the destructor of A but will never call the destructor of B.
                Therefore, destructor of A is made virtual.
            */
            delete a;
            cout<<"Destructor of A is called.\n";
        }
};

class B: public A{
    int *b;
    public:
        B(){
            b = new int (20);
            cout<<"Constructor of B is called.\n";
        }
        ~B(){
            delete b;
            cout<<"Destructor of B is called.\n";
        }
};

int main(){
    A *p = new B;   // Address of an object of B is stored in pointer of A
    delete p;
}