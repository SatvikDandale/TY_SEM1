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
	friend istream& operator>>(istream&, Demo&);

};

istream& operator>>(istream& in, Demo &x){
	in>>x.a>>x.b;
	return in;
}

int main(){

	// Taking input of built-in dataypes can be done as: int a; cin>>a;
	// But, if we want to take input of an user-defined data-type (object):
	// by doing this: Demo d; cin>>d;
	// We have to overload >>"extraction operator"

	Demo d, d1;
	cin>>d>>d1;
	d.display();
	d1.display();


	cout<<"HI";
}