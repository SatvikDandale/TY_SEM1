/*
    Demonstrate how access modifiers affect the scope of data members in the derived classes.
*/
#include<bits/stdc++.h>
using namespace std;

class A{
    // This will be the parent class from whom other classes will inherit.
    private:
        int x;
    protected:
        int y;
    public:
        int z;
        A(){    // Default constructor
            x = 0;
            y = 1;
            z = 2;
        }
        void print(){
            cout<<"BASE CLASS:\n";
            cout<<"Private x: "<<x<<endl;
            cout<<"Protected y: "<<y<<endl;
            cout<<"Public z: "<<z<<endl;
        }
};

class B: public A{
    // This class will publically inherit all the data members of the base class.
    // Therefore, private data member is not accessible
    // Protected remains protected
    // Public data member from base class remains public
    public:
        void print(){
            cout<<"After publically inheriting.\n";
            cout<<"Protected y: "<<y<<endl;
            cout<<"Public z: "<<z<<endl;
        }
};

class C: protected A{
    // This class will inherit A in a protected way.
    // Only difference is that the public data member of base class becomes protected here.
    public:
        void print(){
            cout<<"After inheriting in a protected way.\n";
            cout<<"Protected y: "<<y<<endl;
            cout<<"Protected z: "<<z<<endl;
        }
};

class D: private A{
    // This class will inherit A in a private way.
    // The difference between this and public way is that the protected and the public data members of the base class become private in this class.
    public:
        void print(){
            cout<<"After inheriting in a private way.\n";
            cout<<"Private y: "<<y<<endl;
            cout<<"Private z: "<<z<<endl;
        }
};

int main(){
    A a1;
    a1.print();
    B b1;
    b1.print();
    C c1;
    c1.print();
    D d1;
    d1.print();
}