#include<iostream>
using namespace std;

class Shape
{
public:
    virtual float area()
    {
        return 0;
    }

    virtual void input()
    {
        // base empty
    }

    virtual ~Shape()
    {
        // destructor
    }
};



class Rectangle : public Shape
{
private:
    float length, width;

public:

    void input()
    {
        cout<<"Enter Length : ";
        cin>>length;

        cout<<"Enter Width : ";
        cin>>width;
    }

    float area()
    {
        return length * width;
    }
};



class Circle : public Shape
{
private:
    float radius;

public:

    void input()
    {
        cout<<"Enter Radius : ";
        cin>>radius;
    }

    float area()
    {
        return 3.14 * radius * radius;
    }
};




int main()
{
    Shape *s[10];

    int ch, n, i;

M:

    cout<<"\n1.Static Array (Fixed Shapes)";
    cout<<"\n2.Dynamic Allocation";
    cout<<"\n3.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

        case 1:
        {
            cout<<"How many shapes (max 10) : ";
            cin>>n;

            for(i=0;i<n;i++)
            {
                int type;

                cout<<"\n1.Rectangle 2.Circle : ";
                cin>>type;

                if(type==1)
                    s[i] = new Rectangle;
                else
                    s[i] = new Circle;

                s[i]->input();
            }

            cout<<"\nAreas:\n";

            for(i=0;i<n;i++)
            {
                cout<<"Area = "<<s[i]->area()<<endl;
            }

            for(i=0;i<n;i++)
            {
                delete s[i];
            }

            goto M;
        }



        case 2:
        {
            cout<<"How many shapes : ";
            cin>>n;

            Shape **p = new Shape*[n];

            for(i=0;i<n;i++)
            {
                int type;

                cout<<"\n1.Rectangle 2.Circle : ";
                cin>>type;

                if(type==1)
                    p[i] = new Rectangle;
                else
                    p[i] = new Circle;

                p[i]->input();
            }

            cout<<"\nAreas:\n";

            for(i=0;i<n;i++)
            {
                cout<<"Area = "<<p[i]->area()<<endl;
            }

            for(i=0;i<n;i++)
            {
                delete p[i];
            }

            delete[] p;

            goto M;
        }



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
