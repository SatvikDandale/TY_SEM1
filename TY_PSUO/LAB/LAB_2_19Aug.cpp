/*
Write a CPP to create a student class with details like Roll no, name, marks of five subjects, percentage, grade, and Class. Write following functions:
1. Parameterized contructor
2. Destructor
3. Display
4. Calculate%
5. Calculate grade
6. Calculate class
*/
#include<bits/stdc++.h>
using namespace std;

#define subs 3
// The number of Subjects

class student{
private:
	int *roll = new int, *marks;
	float *percent = new float;
	char *name;
	const char *grade;
public:
	student(int r, int *m, char *n){
		// r is roll, m is marks array, n is name array
		*roll = r;
		marks = new int[subs];
		for(int i=0; i < subs; i++)
			marks[i] = m[i];
		name = new char[sizeof(n)/sizeof(char)];
		for(int i=0; i < sizeof(n)/sizeof(char); i++)
			name[i] = n[i];

		calculatePercentage();
		calculateGrade();
	}
	~student(){
		delete roll, marks, percent, name, grade;
	}
	void display(){
		cout<<"Name of the student: ";
		cout<<name;
		cout<<"\nRoll no: "<<*roll<<"\n";
		cout<<"The percentage is: "<<*percent<<"\n";
		cout<<"The grade is: ";
		cout<<grade;
		cout<<"\n\n";
	}
	void calculatePercentage(){
		// Percentage is Sum of marks from all subjects / Sum of max marks
		int sum = 0;
		for(int i=0; i < subs; i++)
			sum += marks[i];
		*percent = (float)sum/(100*subs) * 100;
	}
	void calculateGrade(){		
		if (*percent > 90){
			grade = "A++";
		}
		else if(*percent > 80 && *percent < 90)
			grade = "A+";
		else if(*percent > 70 && *percent < 80)
			grade = "A";
		else if(*percent > 60 && *percent < 70)
			grade = "B";
		else
			grade = "C";
	}
};

int main(){
	student *s1;
	int roll, *marks = new int[subs];
	
	cout<<"Enter the details of student as following:\n";
	string *n = new string;
	cout<<"Enter the name of student:\n";
	getline(cin, *n);

	char *name = new char[n->length() + 1];
	strcpy(name, n->c_str());
	delete n;
	
	cout<<"Enter the roll number:\n";
	cin>>roll;
	cout<<"Enter the marks of "<<subs<<" subjects:\n";
	for(int i=0; i < subs; i++){
		cout<<"SUBJECT "<<i+1<<": ";
		cin>>marks[i];
	}
	fflush(stdin);
	s1 = new student(roll, marks, name);
	s1->display();
}
