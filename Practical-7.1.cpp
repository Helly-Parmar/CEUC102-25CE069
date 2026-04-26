#include<iostream>
using namespace std;

class Calculator
{
public:

    int add(int a, int b)
    {
        return a + b;
    }

    float add(float a, float b)
    {
        return a + b;
    }

    float add(int a, float b)
    {
        return a + b;
    }

    float add(float a, int b)
    {
        return a + b;
    }
};



int main()
{
    Calculator c;

    int ch;
    int x, y;
    float p, q;

M:

    cout<<"\n1: int + int";
    cout<<"\n2: float + float";
    cout<<"\n3: int + float";
    cout<<"\n4: float + int";
    cout<<"\n5: Exit";

    cout<<"\nEnter choice : ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            cout<<"Enter two integers : ";
            cin>>x>>y;

            cout<<"Result = "<<c.add(x,y)<<endl;
            goto M;

        case 2:
            cout<<"Enter two floats : ";
            cin>>p>>q;

            cout<<"Result = "<<c.add(p,q)<<endl;
            goto M;

        case 3:
            cout<<"Enter int and float : ";
            cin>>x>>p;

            cout<<"Result = "<<c.add(x,p)<<endl;
            goto M;

        case 4:
            cout<<"Enter float and int : ";
            cin>>p>>x;

            cout<<"Result = "<<c.add(p,x)<<endl;
            goto M;

        case 5:
            break;

        default:
            cout<<"Invalid Choice\n";
            goto M;
    }

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
