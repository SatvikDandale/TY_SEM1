#include<bits/stdc++.h>
using namespace std;

// CLASS DEMO
// This class will have at least 2 data members
class Demo{
private:
	int a, b;
public:
	// Default constructor
	Demo(){
		a = b = 0;
	}
	// Parameterized Constructors
	Demo(int x){
		cout<<"Single Parameterized Constructor is called\n";
		a = x;
		b = 0;
	}
	Demo(int x, int y){
		a = x;
		cout<<"Dual Parameterized Constructor is called\n";
		b = y;
	}
	
	// Copy Constructor
	Demo(Demo &d){
		cout<<"Copy Constructor is called\n";
		a = d.a;
		b = d.b;
	}
	
	// GETTERS
	int getA(){
		return a;
	}
	int getB(){
		return b;
	}
	void printData(){
		cout<<a<<"\n"<<b<<"\n";
	}

};

int main(){
	// Passing Object of the Same class as an argument in the constructor
	
	Demo d1(5, 10);
	Demo d2 = d1;	// Assignment Operator: THIS CAN ALSO WORK WITH OPERATOR OVERLOADING
	// The above statement will call Copy Constructor.
	Demo d3(d2);	// Argument
	// The above statement will call Copy Constructor.
	d2.printData();
	d3.printData();
	
	return 0;
}