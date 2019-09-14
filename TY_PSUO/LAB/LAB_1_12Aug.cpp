#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node *up, *down;
	node(int d){
		data = d;
		up = down = NULL;
	}
};

class Stack{
	private:
		node *top;
	
	public:
		Stack(){
			top = NULL;
		}
	
		void push(int d){
			// Empty stack
			if (top == NULL){
				top = new node(d);
			}
			else{
				while(1){
					if (top->up == NULL)
						break;
					top = top->up;
				}
				top->up = new node(d);
				top->up->down = top;
				top = top->up;
			}
		}
		bool checkEmpty(){
			if (top == NULL) return true; else return false;
		}
		
		int pop(){
			// Check for empty before calling this function
			int data = top->data;
			// Decrement top by once
			top = top->down;
			top->up = NULL;
			return data;
		}
};

int main(){
	Stack *s;	// s is an array of stack
	int data, c, current, count;
	cout<<"Enter the number of stacks you need:\n";
	cin>>count;
	s = new Stack[count];
	while(1){
		cout<<"1. Select a stack first\n2. Exit\n";
		cin>>c;
		switch(c){
			case 1:
				cout<<"Enter the stack number:\n";
				cin>>current;
				if(current > count){
					cout<<"Enter valid number for stack\n";
					continue;
				}
				current--;
				break;
			case 2:
				exit(1);
			default:
				cout<<"Enter valid choice.\n";
				continue;
		}
		cout<<"1. Push\n2. Pop\n3. Exit\n\n";
		cin>>c;
		switch(c){
			case 1:
				cout<<"Enter the element to push\n";
				cin>>data;
				s[current].push(data);
				break;
			case 2:
				if(!s[current].checkEmpty())
					cout<<"The popped element is: "<<s[current].pop()<<endl;
				else
					cout<<"This stack is empty\n";
				break;
			case 3:
				exit(1);
			default:
				cout<<"Enter valid choice.\n";
		}
	}	
}


