/*
    Write a cpp program to implement the concept of function overloading.
 */

#include<bits/stdc++.h>
using namespace std;

class Demo{
    private:
        float x, y;
    public:
        Demo(){
            this->x = 0;
            this->y = 0;
        }
        Demo(int x, int y){
            cout<<"Constructor 1 is called\n";
            this->x = x;
            this->y = y;
        }
        Demo(float x, int y){
            cout<<"Constructor 2 is called\n";
            this->x = x;
            this->y = y;
        }
        Demo(float x, float y){
            cout<<"Constructor 3 is called\n";
            this->x = x;
            this->y = y;
        }
        void display(){
            cout<<this->x<<"\t"<<this->y<<endl;
        }
};

int main(){
    Demo d;
    Demo d1(5, 5.4);
    Demo d2(1, 2);
    Demo d3(3.4, 4.5);

}