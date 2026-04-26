#include<iostream>
#include<iomanip>
using namespace std;


// User-defined manipulator
ostream& currency(ostream& out)
{
    out<<"Rs. ";
    return out;
}



int main()
{
    string name[5];

    float marks[5];

    float fees[5];

    int n,i;


    cout<<"Enter number of students : ";
    cin>>n;


    for(i=0;i<n;i++)
    {
        cout<<"\nEnter Student Name : ";
        cin>>name[i];

        cout<<"Enter Marks : ";
        cin>>marks[i];

        cout<<"Enter Fees : ";
        cin>>fees[i];
    }



    cout<<endl;

    cout<<setfill('-')<<setw(55)<<"-"<<endl;

    cout<<setfill(' ');


    cout<<setw(15)<<"Name"
        <<setw(15)<<"Marks"
        <<setw(25)<<"Fees"<<endl;


    cout<<setfill('-')<<setw(55)<<"-"<<endl;

    cout<<setfill(' ');



    for(i=0;i<n;i++)
    {
        cout<<setw(15)<<name[i]

            <<setw(15)<<fixed<<setprecision(2)<<marks[i]

            <<setw(15)<<currency
            <<fees[i]

            <<endl;
    }



    cout<<setfill('-')<<setw(55)<<"-"<<endl;


    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
