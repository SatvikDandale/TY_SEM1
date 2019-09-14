#include<bits/stdc++.h>
using namespace std;

class Demo{

private:
	int a, b;
public:
	void display(){
		cout<<a<<b;
	}
	Demo(int a, int b){
		this->a = a;
		this->b = b;
	}
	Demo& compare(Demo& x){
		if(a > x.a)
			return *this;
		else
			return x;
	}

};

int main(){

	// Make two objects of Demo class.
	// Compare the first data member of the two objects.
	// Return the OBJECT which has a greater value of that data member.
	Demo d1(5, 10), d2(10, 20);
	Demo d3 = d1.compare(d2);

	d3.display();

	cout<<"HI";
}