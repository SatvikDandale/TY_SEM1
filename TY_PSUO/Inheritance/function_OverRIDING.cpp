/*
    CPP program to demonstrate function overriding in inheritance.
*/
#include<bits/stdc++.h>
using namespace std;

class M{
    // BASE Class
    protected: string m;
    public:
        M(){
            m = "Base";
        }
        void display(){
            cout<<m<<endl;
        }
};

class N: public M{
    // Derived class. "string m" and void display() from base class is inherited.
    protected: string n;
    public:
        N(){
            n = "Derived";
        }
        void display(){ // This has the same skeleton as that of the display() function in base class.
            // This will override the base class' function
            cout<<n<<endl;
            /*
                To call the display() function of base class:
                    M::display();
            */
        }
};

int main(){
    N n;
    n.display();
    // OUTPUT: Derived
    n.M::display(); 
    // OUTPUT: Base
}