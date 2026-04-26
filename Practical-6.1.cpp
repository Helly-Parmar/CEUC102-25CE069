#include<iostream>
using namespace std;


class Shape
{
protected:
    float radius;

public:

    void setRadius(float r)
    {
        radius=r;
    }

};


class Circle : public Shape
{
public:

    float calc_area()
    {
        return 3.14*radius*radius;
    }

};



int main()
{
    int ch;
    int n,i;

M:

    cout<<"\n1.Static Array Method";
    cout<<"\n2.Dynamic Array Method";
    cout<<"\n3.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;


    switch(ch)
    {

        case 1:
{
    Circle C[10];

    cout<<"How many circles (max 10) : ";
    cin>>n;

    if(n>10)
    {
        cout<<"Maximum 10 circles allowed\n";
        goto M;
    }

    for(i=0;i<n;i++)
    {
        float r;

        cout<<"Enter radius for Circle "<<i+1<<" : ";
        cin>>r;

        C[i].setRadius(r);
    }

    for(i=0;i<n;i++)
    {
        cout<<"Circle "<<i+1
            <<" Area = "
            <<C[i].calc_area()
            <<endl;
    }

    goto M;
}

        case 2:
        {
            cout<<"How many circles : ";
            cin>>n;


            Circle *D;

            D=new Circle[n];


            for(i=0;i<n;i++)
            {
                float r;

                cout<<"Enter radius for Circle "<<i+1<<" : ";
                cin>>r;

                D[i].setRadius(r);
            }



            cout<<"\nAreas of Circles\n";

            for(i=0;i<n;i++)
            {
                cout<<"Circle "<<i+1
                    <<" Area = "
                    <<D[i].calc_area()
                    <<endl;
            }


            delete[] D;

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
