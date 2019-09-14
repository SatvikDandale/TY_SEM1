#include<bits/stdc++.h>
using namespace std;

// CLASS DEMO
// This class will have at least 2 data members
class Demo{
private:
	int a, b;
	int *p;		// This pointer will store the address of the DATA MEMBER "a";
public:
	// Default constructor
	Demo(){
		a = b = 0;
		p = &a;
	}
	// Parameterized Constructors
	Demo(int x){
		cout<<"Single Parameterized Constructor is called\n";
		a = x;
		b = 0;
		p = &a;
	}
	Demo(int x, int y){
		cout<<"Dual Parameterized Constructor is called\n";
		a = x;
		b = y;
		p = &a;
	}
	// Copy Constructor
	Demo(Demo &d){
		cout<<"Copy Constructor is called\n";
		a = d.a;
		b = d.b;
		p = &a;
	}
	// Overloaded Operators
	void operator=(Demo& d){
		cout<<"Operator is overloaded\n";
		a = d.a;
		b = d.b;
		p = &d.a;
	}
	// GETTERS
	int getA(){
		return a;
	}
	int getB(){
		return b;
	}
	int getP(){
		return *p;
	}
	void printData(){
		cout<<a<<"\n"<<b<<"\n";
	}

};

int main(){
	// SHALLOW COPY
	Demo *d1;
	d1 = new Demo(5, 10);
	Demo d2 = *d1;
	// This will call copy constructor
	cout<<"The value of \"p\" in d2 before deleting d1 is: "<<d2.getP()<<"\n";
	delete d1;
	cout<<"The value of \"p\" in d2 after deleting d1 is: "<<d2.getP()<<"\n";
	d1 = new Demo(5, 10);
	Demo d3;
	d3 = *d1;
	// This will NOT call copy constructor. This is operator overloading.
	cout<<"The value of \"p\" in d3 before deleting d1 is: "<<d3.getP()<<"\n";
	delete d1;
	cout<<"The value of \"p\" in d3 after deleting d1 is: "<<d3.getP()<<"\n";
	// This demostrates SHALLOW COPY IN C++;

	return 0;
}