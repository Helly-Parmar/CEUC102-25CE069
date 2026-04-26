#include<iostream>
using namespace std;

class point
{
    int x;
    int y;

public :

//    point(int xval,int yval)
//    {
//        x=xval;
//        y=yval;
//    }

    point(int a,int b)
    {
        x=a;
        y=b;
    }

    point& move(int dx,int dy)
    {
        this->x+=dx;
        this->y+=dy;
        return *this;

    }

    void display()
    {
        cout<<"( "<<x<<" , "<<y<<" ) ";
    }

};


int main()
{
//    point p(0,0);
    int i,j;
    cout<<"Enter coordinates : ";
    cin>>i>>j;
    point p(i,j);

    p.move(2, 3).move(-1, 4);

    p.display();

    return 0;
}

// Name : Helly Parmar
// ID : 25CE069
