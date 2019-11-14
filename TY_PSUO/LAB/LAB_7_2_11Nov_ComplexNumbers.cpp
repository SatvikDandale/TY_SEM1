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

class ExtendedComplex: public Complex{
    public:
        // Static Members
        static int count;
        static void incrementCount(){
            count++;
        }

        // Constructors
        ExtendedComplex(): Complex(){incrementCount();}
        
        ExtendedComplex(double single): Complex(single){incrementCount();}

        ExtendedComplex(int single): Complex(single){incrementCount();}

        ExtendedComplex(double real_value, double img_value):Complex(real_value, img_value){incrementCount();}
        
        ExtendedComplex(int real_value, double img_value):Complex(real_value, img_value){incrementCount();}

        ExtendedComplex(double real_value, int img_value): Complex(real_value, img_value){incrementCount();}

        ExtendedComplex(int real_value, int img_value): Complex(real_value, img_value){incrementCount();}

        // Copy Constructors
        ExtendedComplex(ExtendedComplex &c1): Complex(c1.getReal(), c1.getImg()){incrementCount();}

        ExtendedComplex(Complex &c1): Complex(c1){incrementCount();}

        // Destructors
        ~ExtendedComplex(){
            delete this;
        }

        // addComplex()
        ExtendedComplex* add_complex(ExtendedComplex &c2){
            // Two complex numbers, *this and c2
            // Create a new object
            static ExtendedComplex *temp = new ExtendedComplex();
            temp->setReal(this->getReal() + c2.getReal());
            temp->setImg(this->getImg() + c2.getImg());
            // Returns the address of the new Object created
            return temp;
        }

        // subComplex()
        ExtendedComplex* sub_complex(ExtendedComplex &c2){
            // Two complex numbers, *this and c2
            // Create a new object
            static ExtendedComplex *temp = new ExtendedComplex();
            temp->setReal(this->getReal() - c2.getReal());
            temp->setImg(this->getImg() - c2.getImg());
            // Returns the address of the new Object created
            return temp;
        }
        
        // multiply_complex()
        ExtendedComplex* multiply_complex(ExtendedComplex &c2){
            // this.r + (this.img)i   REAL: this.r     IMG: this.img
            // c2.r + (c2.img)i   REAL: c2.r     IMG: c2.img
            // RESULT:
            //          REAL: this.r * c2.r - this.img * c2.img
            //          IMG:  this.r * c2.img + this.img * c2.r
            ExtendedComplex *temp = new ExtendedComplex();
            double real = (this->getReal() * c2.getReal()) - (this->getImg() * c2.getImg());
            double img = (this->getReal() * c2.getImg()) + (this->getImg() * c2.getReal());
            temp->setReal(real);
            temp->setImg(img);
            return temp;
        }

        // print_Complex()
        void print_Complex(){
            this->display();
        }

        // get_count()
        static int get_count(){
            return count;
        }
};
int ExtendedComplex::count = 0;

int main(){
    
    ExtendedComplex *c1 = new ExtendedComplex(1, 4);
    ExtendedComplex *c2 = new ExtendedComplex(2, 8);
    ExtendedComplex *c3 = c1->add_complex(*c2);
    ExtendedComplex *c4 = c1->sub_complex(*c2);
    ExtendedComplex *c5 = c1->multiply_complex(*c2);
    
    cout<<"\"c1\" is: ";
    c1->display();
    cout<<endl<<"\"c2\" is: ";
    c2->display();
    cout<<endl<<"\"c3\": c1 + c2 is (c1.add_complex(c2)) : ";
    c3->display();
    cout<<endl<<"\"c4\": c1 - c2 is (c1.sub_complex(c2)) : ";
    c4->display();
    cout<<endl<<"\"c5\": c1 * c2 is (c1.multiple_complex(c2)) : ";
    c5->display();
    cout<<endl<<"Total Complex number objects formed are: "<<ExtendedComplex::get_count()<<endl;

}