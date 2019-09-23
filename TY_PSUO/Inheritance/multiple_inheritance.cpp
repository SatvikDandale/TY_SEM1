/*
    Demonstrate multiple inheritance.
*/
#include<bits/stdc++.h>
using namespace std;

class P{
    protected: int p;
    public:
        P(){
            p = 0;
        }
        void setP(int p){
            this->p = p;
        }
};

class Q{
    protected: int q;
    public:
        Q(){
            q = 0;
        }
        void setQ(int q){
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
    r1.setP(10);
    r1.setQ(20);
    r1.display();
}