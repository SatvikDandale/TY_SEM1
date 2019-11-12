/*
    Write a program to implement Complex class as follows:
    Private:    real_value
                imag_value 
    Public:
                Parameterized constructor(1 and 2 parameter)
                Copy constructor
                Getter and setter functions.
                (Use of constructors and destructors)
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

int main(){
    
    // Creating two different Complex Numbers
    Complex *c1 = new Complex(1, 22);
    Complex *c2;

    // Getter
    cout<<"c1 is: "<<c1->getReal()<<" + "<<c1->getImg()<<"i\n";

    // Setter
    c1->setImg(4.5);

    cout<<"c1 now is: ";
    c1->display();
    cout<<endl;

    // Copy Constructor
    c2 = new Complex(*c1);
    cout<<"c2 after copying from c1 is: ";
    c2->display();
    cout<<endl;
}