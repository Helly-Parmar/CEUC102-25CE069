#include<iostream>
#include<string>
using namespace std;

class university
{
private:
    int roll;
    string name;
    float m1,m2,m3;
    float avg;

public:

    university(); // default constructor
    university(int,string,float,float,float); // parameterized constructor

    void get_studata();
    void cal_avg();
    int display(int);
};



university::university()
{
    roll=0;
    name="Default";
    m1=m2=m3=40;

    cal_avg();
}



university::university(int r,string n,float a,float b,float c)
{
    roll=r;
    name=n;

    m1=a;
    m2=b;
    m3=c;

    cal_avg();
}



void university::get_studata()
{
    cout<<"Enter Student Roll Number : ";
    cin>>roll;

    cin.ignore();

    cout<<"Enter Student Name : ";
    getline(cin,name);

    cout<<"Enter Marks of 3 subjects : ";
    cin>>m1>>m2>>m3;

    cal_avg();
}



void university::cal_avg()
{
    avg=(m1+m2+m3)/3;
}



int university::display(int x)
{
    if(roll==x)
    {
        cout<<"\nRoll No : "<<roll<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks : "<<m1<<" "<<m2<<" "<<m3<<endl;
        cout<<"Average : "<<avg<<endl;

        return 1;
    }

    return 0;
}



int main()
{
    university U[100];   // default constructor called automatically

    int ch,last=0,i,rno;

M:

    cout<<"\n1.Enter Student Data";
    cout<<"\n2.Add Test Student (Parameterized Constructor)";
    cout<<"\n3.Display Student Record";
    cout<<"\n4.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

        case 1:

            if(last==100)
            {
                cout<<"Student storage full\n";
                goto M;
            }

            U[last].get_studata();

            last++;

            goto M;



        case 2:

            if(last==100)
            {
                cout<<"Student storage full\n";
                goto M;
            }

            // Demonstrating parameterized constructor
            U[last]=university(101+last,"Test Student",80,90,85);

            cout<<"Test student added successfully\n";

            last++;

            goto M;



        case 3:

            cout<<"Enter Student Roll Number : ";
            cin>>rno;

            for(i=0;i<last;i++)
            {
                if(U[i].display(rno)==1)
                    break;
            }

            if(i==last)
                cout<<"Student not found\n";

            goto M;



        case 4:
            break;



        default:
            cout<<"Invalid Choice\n";
            goto M;
    }

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069

