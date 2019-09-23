/*
    Ambiguity when a same function skeleton is in two classes and a third class inherits the class.
*/
#include<bits/stdc++.h>
using namespace std;

class P{
    protected: int p;
    public:
        P(){
            p = 0;
        }
        void set(int p){
            this->p = p;
        }
};

class Q{
    protected: int q;
    public:
        Q(){
            q = 0;
        }
        void set(int q){
            this->q = q;
        }
};

class R: public P, public Q{    // Inheriting from both classes
    public:
        void display(){
            cout<<p<<"\t"<<q<<endl;
        }
};

int main(){
    R r1;
    //r1.set(10);    // This gives an error: request for member ‘set’ is ambiguous
    // To access a function from a specific class, use its name with the scope resolution operator.
    r1.P::set(10);
    r1.Q::set(20);
    r1.display();
}