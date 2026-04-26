#include<iostream>
using namespace std;



class Fuel
{
protected:
    string fuel_type;

public:

    Fuel()
    {
        fuel_type="Petrol";
    }

    Fuel(string f)
    {
        fuel_type=f;
    }

};



class Brand
{
protected:
    string brand_name;

public:

    Brand()
    {
        brand_name="Default";
    }

    Brand(string b)
    {
        brand_name=b;
    }

};



class Car : public Fuel , public Brand
{
private:
    int car_id;

public:

    Car() : Fuel(), Brand()
    {
        car_id=0;
    }


    Car(int id,string f,string b)
      : Fuel(f), Brand(b)
    {
        car_id=id;
    }



    void get_data()
    {
        cout<<"Enter Car ID : ";
        cin>>car_id;

        cout<<"Enter Fuel Type : ";
        cin>>fuel_type;

        cout<<"Enter Brand Name : ";
        cin>>brand_name;
    }



    void display()
    {
        cout<<"Car ID : "<<car_id<<endl;

        cout<<"Fuel Type : "<<fuel_type<<endl;

        cout<<"Brand Name : "<<brand_name<<endl;
    }

};



int main()
{
    Car C[20];

    int ch;

    int last=0;

    int i;


    // Queue variables
    int front=0;
    int rear=-1;



MENU:

    cout<<"\n1.Add Car (Static Method)";
    cout<<"\n2.Add Car To Service Queue";
    cout<<"\n3.Process Next Car From Queue";
    cout<<"\n4.Display All Cars";
    cout<<"\n5.Add Test Car";
    cout<<"\n6.Exit";

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

            C[last].get_data();

            cout<<"Car Added\n";

            last++;

            goto MENU;




        case 2:

            if(rear==19)
            {
                cout<<"Queue Full\n";
                goto MENU;
            }

            rear++;

            C[rear].get_data();

            cout<<"Car Added To Queue\n";

            if(last<=rear)
                last=rear+1;

            goto MENU;




        case 3:

            if(front>rear)
            {
                cout<<"Queue Empty\n";
                goto MENU;
            }


            cout<<"\nProcessing Car:\n";

            C[front].display();

            front++;

            goto MENU;




        case 4:

            if(last==0)
            {
                cout<<"No Cars Stored\n";
                goto MENU;
            }


            for(i=0;i<last;i++)
            {
                cout<<"\nCar "<<i+1<<endl;

                C[i].display();
            }

            goto MENU;




        case 5:

            if(last==20)
            {
                cout<<"Storage Full\n";
                goto MENU;
            }


            C[last]=Car(101,"Electric","Tesla");

            cout<<"Test Car Added\n";

            last++;

            goto MENU;




        case 6:
            break;




        default:

            cout<<"Invalid Choice\n";

            goto MENU;
    }



    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
