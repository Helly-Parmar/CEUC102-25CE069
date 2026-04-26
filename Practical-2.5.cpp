#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class emi_sys
{
private:
    int id;
    string name;
    float loan_amt;
    float interest;
    int loan_tenure;

public:

    // Default constructor
    emi_sys()
    {
        id=0;
        name="Default";
        loan_amt=100000;
        interest=8;
        loan_tenure=12;
    }

    // Parameterized constructor
    emi_sys(int i,string n,float l,float r,int t)
    {
        id=i;
        name=n;
        loan_amt=l;
        interest=r;
        loan_tenure=t;
    }

    void get_data();
    void emi_calc();
    int display(int);
};



void emi_sys::get_data()
{
    cout<<"Enter Customer ID : ";
    cin>>id;

    cout<<"Enter Customer Name : ";
    cin>>name;

    cout<<"Enter Loan Amount : ";
    cin>>loan_amt;

    cout<<"Enter Interest Rate : ";
    cin>>interest;

    cout<<"Enter Loan Tenure (months) : ";
    cin>>loan_tenure;
}



void emi_sys::emi_calc()
{
    float r,emi;

    r=interest/(12*100);

    emi=(loan_amt*r*pow(1+r,loan_tenure))/
        (pow(1+r,loan_tenure)-1);

    cout<<"Calculated EMI : "<<emi<<endl;
}



int emi_sys::display(int x)
{
    if(id==x)
    {
        cout<<"\nCustomer ID : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Loan Amount : "<<loan_amt<<endl;
        cout<<"Interest : "<<interest<<endl;
        cout<<"Tenure : "<<loan_tenure<<endl;

        emi_calc();

        return 1;
    }

    return 0;
}



int main()
{
    emi_sys E[20];

    int ch,last=0,i,cid;

M:

    cout<<"\n1.Add Loan Record";
    cout<<"\n2.Add Test Record";
    cout<<"\n3.Calculate EMI";
    cout<<"\n4.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

        case 1:

            if(last==20)
            {
                cout<<"Record storage full\n";
                goto M;
            }

            E[last].get_data();

            last++;

            goto M;



        case 2:

            if(last==20)
            {
                cout<<"Record storage full\n";
                goto M;
            }

            // parameterized constructor
            E[last]=emi_sys(100+last,"TestUser",500000,8,24);

            cout<<"Test loan record added\n";

            last++;

            goto M;



        case 3:

            cout<<"Enter Customer ID : ";
            cin>>cid;

            for(i=0;i<last;i++)
            {
                if(E[i].display(cid)==1)
                    break;
            }

            if(i==last)
                cout<<"Record not found\n";

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

