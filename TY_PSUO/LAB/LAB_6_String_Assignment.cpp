#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

class String
{
    private:
        char *array;
    public:
        void getstring()
        {
            char *temp = new char [20];
            cout<<"Enter new string"<<endl;
            cin.getline(temp,20);
            int i=0;
            while(temp[i]!='\0')
            {
                i++;
            }
            array = new char[i];
            i=0;
            while(temp[i]!='\0')
            {
                array[i] = temp[i];
                i++;
            }
            array[i]='\0';
            delete[] temp;
        }
        void printstring()
        {
            int i=0;
            while(array[i]!='\0')
            {
                cout<<array[i];
                i++;
            }cout<<"\n";
        }
        String operator+(String str)
        {
            String temp;
            temp.array = new char[strlen(str.array) + strlen(array)] ;
            int i=0;
            while(array[i]!='\0')
                temp.array[i]=array[i++];
            

            int ind=0;
            while(str.array[ind]!='\0')
                temp.array[i++] = str.array[ind++];
            temp.array[i]='\0';
            return temp;
        }`
        void operator=(String str)
        {
            delete[] array;
            array = new char[strlen(str.array)];
            int i=0;
            while(str.array[i]!='\0')
                array[i]= str.array[i++];
            array[i]='\0';
        }
        bool operator==(String str)
        {
            if(strlen(array)==strlen(str.array))
            {
                int i=0;
                while(array[i]!='\0')
                {
                    if(array[i]==str.array[i])
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(i == strlen(array))
                    return true;
                else
                    return false;
            }
            else
            {
                return false;
            }
        }

};

int main()
{
    String s1;
    s1.getstring();
    s1.printstring();
    String s2;
    s2.getstring();
    s2.printstring();
    String s3;
    s3 = s1 + s2;
    cout<<"Added string is:"<<endl;
    s3.printstring();
    String s4;
    s4 = s1;
    cout<<"Copied string is:"<<endl;
    s4.printstring();
    bool b = (s1 == s2);
    if(b==false)
        cout<<"String is Not same";
    else
        cout<<"String is same";
}