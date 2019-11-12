/*
    Write a program to extend complex class with following details:
    Public: 
            add_complex()
            subtract_complex()
            multiply_complex()
            print_complex()
            getcount_complex() 
            (Use of member functions and static variable)
*/

#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        float real_value, img_value;
    public:
        // Constructors
        Complex(/* DEFAULT */){
            this->real_value = this->img_value = 0;
        }
        Complex(double single){
            // In this case, the real and imaginary part will be set to the given number.
            this->real_value = this->img_value = single;
        }
        Complex(int single){
            // In this case, the real and imaginary part will be set to the given number.
            this->real_value = this->img_value = single;
        }
        Complex(double real_value, double img_value){
            this->real_value = real_value;
            this->img_value = img_value;
        }
        Complex(int real_value, double img_value){
            this->real_value = real_value;
            this->img_value = img_value;
        }
        Complex(double real_value, int img_value){
            this->real_value = real_value;
            this->img_value = img_value;
        }
        Complex(int real_value, int img_value){
            this->real_value = real_value;
            this->img_value = img_value;
        }

        // Copy Constructor
        Complex(Complex &c){
            this->real_value = c.real_value;
            this->img_value = c.img_value;
        }

        // Destructor
        ~Complex(){
            delete this;
        }

        // SETTERS
        void setReal(int real_value){
            this->real_value = real_value;
        }
        void setImg(int img_value){
            this->img_value = img_value;
        }
        void setReal(double real_value){
            this->real_value = real_value;
        }
        void setImg(double img_value){
            this->img_value = img_value;
        }

        // GETTERS
        float getReal(){    return this->real_value;    }
        
        float getImg(){     return this->img_value;     }

        // Displaying the complex number

        void display(){
            cout<<this->real_value<<" + "<<this->img_value<<"i";
        }

};

class ComplexOperations : public Complex{
    public:
        // static int count;
        // // Static Function to increment the count
        // static void incrementCount(){
        //     count++;
        // }
        
        // Constructors
        // ComplexOperations(/* DEFAULT */){
        //     Complex();
        //     incrementCount();
        // }


        ComplexOperations(int real, int img){
            cout<<"HELLO";
            //incrementCount();
            //Complex(real, img);
        }

        
        // ComplexOperations(double real, double img){
        //     incrementCount();
        //     Complex(real, img);
        // }
        // ComplexOperations(int real, double img){
        //     incrementCount();
        //     Complex(real, img);
        // }
        // ComplexOperations(double real, int img){
        //     incrementCount();
        //     Complex(real, img);
        // }

        // // Copy Constructor
        // ComplexOperations(ComplexOperations &c2){
        //     this->setReal(c2.getReal());
        //     this->setImg(c2.getImg());
        // }

        // // add_complex()
        // ComplexOperations& add_complex(ComplexOperations &c2){
        //     // Two complex numbers, *this and c2
        //     // Create a new object
        //     ComplexOperations *temp;
        //     temp->setReal(this->getReal() + c2.getReal());
        //     temp->setImg(this->getImg() + c2.getImg());
        //     return *temp;
        // }

        // //subtract_complex()
        // ComplexOperations& subtract_complex(ComplexOperations &c2){
        //     // Two complex numbers, *this and c2
        //     // Create a new object
        //     ComplexOperations *temp;
        //     temp->setReal(this->getReal() - c2.getReal());
        //     temp->setImg(this->getImg() + c2.getImg());
        //     return *temp;
        // }

        // // multiply_complex()
        // ComplexOperations& multiply_complex(ComplexOperations &c2){
        //     // a + bi   REAL: a     IMG: b
        //     // c + di   REAL: c     IMG: d
        //     // RESULT:
        //     //          REAL: ac - bd
        //     //          IMG:  ad + bc
        //     ComplexOperations *temp;
        //     double real = (this->getReal() * c2.getReal()) - (this->getImg() * c2.getImg());
        //     double img = (this->getReal() * c2.getImg()) - (this->getImg() * c2.getReal());
        //     temp->setReal(real);
        //     temp->setImg(img);
        //     return *temp;
        // }

};
//int ComplexOperations::count = 0;

int main(){
    
    Complex c1(1, 4);
    //c1.display();

    // Creating two different Complex Numbers
    // ComplexOperations c1(1, 22);
    //ComplexOperations c2(2, 3);

    //c1.display();
    //ComplexOperations c3(c1.add_complex(c2));
    //c3.display();

    
}