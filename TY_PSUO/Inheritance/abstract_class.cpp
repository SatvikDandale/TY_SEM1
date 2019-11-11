/*
    CPP program to demostrate how abstract (do nothing) functions are inherited and the rules for the same.
*/
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        // Declaring just one function as virtaul AND do nothing will make the class abstract.
        virtual void f1() = 0;
        void f2(){
            cout<<"This is f2\n";
        }
};

class B: public A{
    public:
        void f1(){
            cout<<"This is from f1 function of class B.\n";
        }
};

int main(){
    // A a1;
    // Abstract class cannot be instantiated.
    A *p;
    B b;
    b.f1(); // This will obviously work. No other concept involved.

    p = &b;
    p -> f1();  // Here calling entity, according to compiler at the (time of compilation) is A.
    // But making the abstract function virtual will not let the compiler bind this f1() to A.
    // This f1() will be bound to B at RUNTIME.
}