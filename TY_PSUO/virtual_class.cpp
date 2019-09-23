/*
            Student
            |   |
        ----    -----
        |           |
       Test       Sports
        |           |
        ----    -----
            |   |
            Result

        The class Result will inherit twice from the class student.
        Whenever a function of the class Student is called from the class Result, it will create an ambiguity as to which function amongst the inherited function was referred.

        To resolve this, make the Class Test and Sports virtual which ensures that only one copy of the inherited members of the class Student reach the derived class Result.
*/
#include<bits/stdc++.h>
using namespace std;

class Student{
    protected: int roll;
    public:
        Student(){
            roll = 10;
        }
        void setRoll(int roll){
            this->roll = roll;
        }
};

class Test: virtual public Student{ // Virtual Class.
    protected: int marks;
    public:
        Test(){
            marks = 45;
        }
        void setMarks(int marks){
            this->marks = marks;
        }
};

class Sports: public virtual Student{   // Syntax is different but result is same.
    protected: int goals;
    public:
        Sports(){
            goals = 1;
        }
        void setGoals(int goals){
            this->goals = goals;
        }
};

class Result: public Test, public Sports{   // Inherited from Test and Sports
    protected: float percent;
    public:
        Result(){
            percent = marks/(float)50 * 100;
        }
        float getPercent(){
            return percent;
        }
        void display(){
            cout<<"Result is: "<<roll<<endl;
        }
};

class M: public virtual Result{
    public:
        void disp(){
            cout<<roll;
        }
};

int main(){
    M m;
    m.disp();
}
