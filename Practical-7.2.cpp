#include<iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:

    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    void getData()
    {
        cout<<"Enter Real Part : ";
        cin>>real;

        cout<<"Enter Imaginary Part : ";
        cin>>imag;
    }

    void display()
    {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

    Complex operator + (Complex c)
    {
        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    Complex operator - (Complex c)
    {
        Complex temp;

        temp.real = real - c.real;
        temp.imag = imag - c.imag;

        return temp;
    }
};



int main()
{
    Complex c1, c2, c3;

    int ch;

M:

    cout<<"\n1:Add Complex Numbers";
    cout<<"\n2:Subtract Complex Numbers";
    cout<<"\n3:Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            cout<<"\nEnter First Complex Number\n";
            c1.getData();

            cout<<"\nEnter Second Complex Number\n";
            c2.getData();

            c3 = c1 + c2;

            cout<<"\nResult = ";
            c3.display();

            goto M;

        case 2:
            cout<<"\nEnter First Complex Number\n";
            c1.getData();

            cout<<"\nEnter Second Complex Number\n";
            c2.getData();

            c3 = c1 - c2;

            cout<<"\nResult = ";
            c3.display();

            goto M;

        case 3:
            break;

        default:
            cout<<"Invalid Choice\n";
            goto M;
    }

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
