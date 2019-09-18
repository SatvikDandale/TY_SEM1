/*
    Write a CPP program to implement the concept of friend function and function overloading.
 */

#include<bits/stdc++.h>
using namespace std;

class Demo{
    private:
        int *array;
        int size;
    public:
        Demo(){
            array = NULL;
            size = 0;
        }
        Demo(int *array, int size){
            // Allocate memory for this->array
            this->array = new int [size];
            for(int i=0; i < size; i++)
                this->array[i] = array[i];
            this->size = size;
        }
        
        void input(){
            // Ask for size then take the array
            cout<<"Enter the size of the array\n";
            cin>>this->size;
            this->array = new int [size];
            cout<<"Enter the array:\n";
            for(int i=0; i < size; i++){
                cout<<"Enter element no. "<<i+1<<": ";
                cin>>this->array[i];
            }
        }

        void display(){
            for(int i=0; i < size; i++)
                cout<<this->array[i]<<"\t";
        }
        friend int mean(Demo&);
};

int mean(Demo& d){
    // This will calculate the avg of the elements in the array of d
    int sum = 0;
    for(int i=0; i < d.size; i++)   // We can access the private data members because it is a friend function.
        sum += d.array[i];
    return sum/d.size;
}

int main(){
    Demo d;
    d.input();
    cout<<"The mean of the entered array is:\n";
    cout<<mean(d);
}