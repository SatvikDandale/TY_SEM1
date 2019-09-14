#include<bits/stdc++.h>
#include<iostream>
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
		a = x;
		b = 0;
	}
	Demo(int x, int y){
		a = x;
		b = y;
	}
	// Copy Constructor
	/*
	Demo(Demo &d){
		a = d.a;
		b = d.b;
	}
	*/
	// WE WILL NOT HAVE A COPY CONSTRUCTOR THIS TIME.
	// INSTEAD, WE WILL HAVE AN OVERLOADED FUNCTION
	// THIS FUNCTION IS AUTOMATICALLY CALLED EVEN IF THE DEFINATION IS NOT GIVEN BY THE PROGRAMMER
	
	/*void operator=(int x){
		a = x;
	};
*/
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
	// ASSINGING AN IN-BUILT DATA TYPE, say 'int', TO AN CLASS OBJECT
	Demo d;
	d = 2;
	cout<<d.getB();

	return 0;
}