#include<iostream>
using namespace std;

class Payroll
{
private:
    string name;
    float basic_salary;
    float bonus;

public:

    // default bonus constructor
    Payroll()
    {
        name="Default";
        basic_salary=20000;
        bonus=2000;
    }

    // parameterized constructor
    Payroll(string n,float bs,float b)
    {
        name=n;
        basic_salary=bs;
        bonus=b;
    }

    void get_data();

    inline float total_salary()
    {
        return basic_salary+bonus;
    }

    void display();
};



void Payroll::get_data()
{
    cout<<"Enter Employee Name : ";
    cin>>name;

    cout<<"Enter Basic Salary : ";
    cin>>basic_salary;

    cout<<"Enter Bonus : ";
    cin>>bonus;
}



void Payroll::display()
{
    cout<<"\nEmployee Name : "<<name<<endl;
    cout<<"Basic Salary : "<<basic_salary<<endl;
    cout<<"Bonus : "<<bonus<<endl;
    cout<<"Total Salary : "<<total_salary()<<endl;
}



int main()
{
    Payroll *P;      // dynamic allocation

    int ch,last=0,n,i;

    cout<<"Enter number of employee records : ";
    cin>>n;

    P=new Payroll[n];

M:

    cout<<"\n1.Add Employee";
    cout<<"\n2.Add Test Employee (Default Bonus)";
    cout<<"\n3.Display All Employees";
    cout<<"\n4.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

        case 1:

            if(last==n)
            {
                cout<<"Employee storage full\n";
                goto M;
            }

            P[last].get_data();

            cout<<"Employee "<<last+1<<" added successfully\n";

            last++;

            goto M;



        case 2:

            if(last==n)
            {
                cout<<"Employee storage full\n";
                goto M;
            }

            // customized employee using constructor
            P[last]=Payroll("TestEmp",30000,5000);

            cout<<"Test employee added\n";

            last++;

            goto M;



        case 3:

            if(last==0)
            {
                cout<<"No employee records found\n";
                goto M;
            }

            for(i=0;i<last;i++)
            {
                cout<<"\nEmployee "<<i+1;
                P[i].display();
            }

            goto M;



        case 4:

            delete[] P;
            break;



        default:

            cout<<"Invalid Choice\n";
            goto M;
    }

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069

