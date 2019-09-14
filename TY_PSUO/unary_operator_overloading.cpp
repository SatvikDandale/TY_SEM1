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
	Demo()
	{

	}
	Demo operator++(int)
	{
		Demo t;
		t.a=a++;
		t.b=b++;
		
		return t;
	}
};

int main(){


	Demo d1(2,3);
	Demo d2=d1++;
	d1.display();
	d2.display();
	cout<<"HI";
}