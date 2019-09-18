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
            cout<<"Default Constructor is called.\n";
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
        Demo(double x, double y){
            cout<<"Constructor 4 is called\n";
            this->x = x;
            this->y = y;
        }
        Demo(int x, double y){
            cout<<"Constructor 5 is called\n";
            this->x = x;
            this->y = y;
        }
        void display(){
            cout<<this->x<<"\t"<<this->y<<endl;
        }
};

int main(){
    Demo d;
    float a = 1.5, b = 4.5;
    Demo d1(5, 5.4);    // This will be d1(int, double)
    Demo d2(1, 2);      // This will be int, int
    Demo d3(a, b);      // This will be float, float
}