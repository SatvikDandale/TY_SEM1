/*
    Write a program to implement following class hierarchy:
        (Using inheritance, object pointers and virtual functions)
                Animal(eat())
                    ||
                    \/
                Dog(eat())
                    ||
                    \/
                Labrador(eat()) 
        Every class is having eat() method. 
    Apply concept of run-time polymorphism.
*/

#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
        virtual void eat(){ // The function is virtual to avoid compile time binding
            cout<<"Animal is eating now.\n";
        }
};

class Dog: public Animal{
    public:
        virtual void eat(){ // The function is virtual to avoid compile time binding
            cout<<"Dog is eating now.\n";
        }
};

class Labrador: public Dog{
    public:
        void eat(){
            cout<<"Labrador is eating now.\n";
        }
};


int main(){
    // Two objects:
        // 1. Animal *obj <- new Dog();
        // 2. Dog *obj <- new Labrador();

    // 1.
    Animal *animal = new Dog();
    // Calling animal->eat()
    animal->eat();     // OUTPUT: Dog is eating now.
    // Even though the obj is of type animal, the method from the class Dog is called.

    // 2.
    Dog *dog = new Labrador();
    // Calling dog->eat()
    dog->eat();         // OUTPUT: Labrador is eating now.
    // Even though the obj is of type Dog, the method from the class Dog is called.
}