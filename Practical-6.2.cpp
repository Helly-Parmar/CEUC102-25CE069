#include<iostream>
using namespace std;



class Person
{
protected:
    string name;
    int age;

public:

    Person()
    {
        name="Default";
        age=18;
    }

    Person(string n,int a)
    {
        name=n;
        age=a;
    }


    void show_person()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }

};




class Employee : public Person
{
protected:
    int emp_id;

public:

    Employee() : Person()
    {
        emp_id=0;
    }

    Employee(string n,int a,int id)
        : Person(n,a)
    {
        emp_id=id;
    }


    void show_employee()
    {
        show_person();

        cout<<"Employee ID : "<<emp_id<<endl;
    }


    int getID()
    {
        return emp_id;
    }

};




class Manager : public Employee
{
private:
    string department;

public:

    Manager() : Employee()
    {
        department="General";
    }


    Manager(string n,int a,int id,string d)
      : Employee(n,a,id)
    {
        department=d;
    }



    void get_data()
    {
        cout<<"Enter Name : ";
        cin>>name;

        cout<<"Enter Age : ";
        cin>>age;

        cout<<"Enter Employee ID : ";
        cin>>emp_id;

        cout<<"Enter Department : ";
        cin>>department;
    }



    void display()
    {
        show_employee();

        cout<<"Department : "<<department<<endl;
    }

};




int main()
{
    Manager M[20];

    int ch,last=0,i,id;


MENU:

    cout<<"\n1.Add Manager";
    cout<<"\n2.Search by Employee ID";
    cout<<"\n3.Display All Managers";
    cout<<"\n4.Add Test Manager (Constructor Chain)";
    cout<<"\n5.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;



    switch(ch)
    {

        case 1:

            if(last==20)
            {
                cout<<"Storage Full\n";
                goto MENU;
            }

            M[last].get_data();

            cout<<"Manager "<<last+1<<" added\n";

            last++;

            goto MENU;




        case 2:

            cout<<"Enter Employee ID : ";
            cin>>id;


            for(i=0;i<last;i++)
            {
                if(M[i].getID()==id)
                {
                    cout<<"\nRecord Found\n";

                    M[i].display();

                    break;
                }
            }


            if(i==last)
            {
                cout<<"Record Not Found\n";
            }

            goto MENU;




        case 3:

            if(last==0)
            {
                cout<<"No Records\n";
                goto MENU;
            }


            for(i=0;i<last;i++)
            {
                cout<<"\nManager "<<i+1<<endl;

                M[i].display();
            }

            goto MENU;




        case 4:

            if(last==20)
            {
                cout<<"Storage Full\n";
                goto MENU;
            }


            M[last]=Manager("Ravi",35,101,"HR");

            cout<<"Test Manager Added\n";

            last++;

            goto MENU;




        case 5:
            break;




        default:

            cout<<"Invalid Choice\n";

            goto MENU;
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
