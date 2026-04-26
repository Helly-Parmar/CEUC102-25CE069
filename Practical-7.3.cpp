#include<iostream>
using namespace std;

class Fahrenheit;   // forward declaration


class Celsius
{
    float temp;

public:

    Celsius()
    {
        temp = 0;
    }

    Celsius(float t)
    {
        temp = t;
    }

    void getData()
    {
        cout<<"Enter Temperature in Celsius : ";
        cin>>temp;
    }

    float getTemp()
    {
        return temp;
    }

    // Celsius -> Fahrenheit
    operator Fahrenheit();

    bool operator == (Celsius c)
    {
        return temp == c.temp;
    }
};



class Fahrenheit
{
    float temp;

public:

    Fahrenheit()
    {
        temp = 0;
    }

    Fahrenheit(float t)
    {
        temp = t;
    }

    void show()
    {
        cout<<temp<<endl;
    }

    float getTemp()
    {
        return temp;
    }

    // Fahrenheit -> Celsius
    operator Celsius()
    {
        float c = (temp - 32) * 5 / 9;
        return Celsius(c);
    }

    bool operator == (Fahrenheit f)
    {
        return temp == f.temp;
    }
};



// Celsius -> Fahrenheit conversion
Celsius::operator Fahrenheit()
{
    float f = (temp * 9/5) + 32;
    return Fahrenheit(f);
}




int main()
{
    int ch, n, i;

    Celsius c[10];
    Fahrenheit f[10];



M:

    cout<<"\n1.Static Storage Conversion";
    cout<<"\n2.Dynamic Conversion";
    cout<<"\n3.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;



    switch(ch)
    {

    case 1:
    {
        cout<<"How many temperatures (max 10) : ";
        cin>>n;

        for(i=0;i<n;i++)
        {
            c[i].getData();
            f[i] = c[i];
        }

        cout<<"\nConverted Temperatures:\n";

        for(i=0;i<n;i++)
        {
            cout<<"C = "<<c[i].getTemp()
                <<" | F = ";

            f[i].show();
        }

        goto M;
    }



    case 2:
    {
        cout<<"Enter number of values : ";
        cin>>n;

        Celsius *cq = new Celsius[n];
        Fahrenheit *fq = new Fahrenheit[n];

        for(i=0;i<n;i++)
        {
            cq[i].getData();
            fq[i] = cq[i];
        }

        cout<<"\nConverted Values:\n";

        for(i=0;i<n;i++)
        {
            cout<<"C = "<<cq[i].getTemp()
                <<" | F = ";

            fq[i].show();
        }

        delete[] cq;
        delete[] fq;

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
