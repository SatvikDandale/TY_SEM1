/*
    CPP Program to demostrate an inline function.
    When a function is made inline, at the time of the function call, the code gets copied to the point where the function was called to prevent the function jumps.
*/
#include<bits/stdc++.h>
using namespace std;

class Demo{
    private:
        int a, b;
    public:
        Demo(){
            a = 0;
            b = 0;
        }

        Demo(int a, int b){
            this->a = a;
            this->b = b;
        }
        
        inline int get_Max(){   // This function is inline so the control won't jump to this code block.
        // Instead, the following statements will get copied to the point where this function was called.
            cout<<"LOCATION OF THE STATEMENTS INSIDE THE FUNCION get_max is inside the function: ";
            cout<<typeid(*this).name();
            return (a > b)?  a: b;
        }
};

int main(){
    Demo d1(10, 20);
    d1.get_Max();
}
