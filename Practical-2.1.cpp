#include<iostream>
using namespace std;

class Manage_rect
{
private:
    float length;
    float width;

public:

    void setData(float l,float w)
    {
        length=l;
        width=w;
    }

    void updateData(float l,float w)
    {
        length=l;
        width=w;
    }

    void calc_area()
    {
        cout<<"Area = "<<length*width<<endl;
    }

    void calc_perimeter()
    {
        cout<<"Perimeter = "<<2*(length+width)<<endl;
    }
};

int main()
{
    Manage_rect R[10];

    int ch,last=0;
    int rectNo;

    float l,w;

M:

    cout<<"\n1.Add Rectangle";
    cout<<"\n2.Calculate Area";
    cout<<"\n3.Calculate Perimeter";
    cout<<"\n4.Update Rectangle Dimensions";
    cout<<"\n5.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

    case 1:

        if(last==10)
        {
            cout<<"Rectangle storage full\n";
            goto M;
        }

        cout<<"Enter Length : ";
        cin>>l;

        cout<<"Enter Width : ";
        cin>>w;

        R[last].setData(l,w);

        cout<<"Rectangle "<<last+1<<" added successfully\n";

        last++;

        goto M;



    case 2:

        if(last==0)
        {
            cout<<"No rectangles added yet\n";
            goto M;
        }

        cout<<"Enter Rectangle Number : ";
        cin>>rectNo;

        if(rectNo<1 || rectNo>last)
        {
            cout<<"Invalid rectangle number\n";
            goto M;
        }

        R[rectNo-1].calc_area();

        goto M;



    case 3:

        if(last==0)
        {
            cout<<"No rectangles added yet\n";
            goto M;
        }

        cout<<"Enter Rectangle Number : ";
        cin>>rectNo;

        if(rectNo<1 || rectNo>last)
        {
            cout<<"Invalid rectangle number\n";
            goto M;
        }

        R[rectNo-1].calc_perimeter();

        goto M;



    case 4:

        if(last==0)
        {
            cout<<"No rectangles added yet\n";
            goto M;
        }

        cout<<"Enter Rectangle Number to Update : ";
        cin>>rectNo;

        if(rectNo<1 || rectNo>last)
        {
            cout<<"Invalid rectangle number\n";
            goto M;
        }

        cout<<"Enter New Length : ";
        cin>>l;

        cout<<"Enter New Width : ";
        cin>>w;

        R[rectNo-1].updateData(l,w);

        cout<<"Rectangle "<<rectNo<<" updated successfully\n";

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
//ID : 25CE069
