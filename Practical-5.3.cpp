#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    int ch;

    string name;
    string search_name;

    int qty;

    float price;


M:

    cout<<"\n1.Add Item";
    cout<<"\n2.View All Items";
    cout<<"\n3.Search Item";
    cout<<"\n4.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;



    switch(ch)
    {

    case 1:
    {
        ofstream fout;

        fout.open("inventory-5.3.txt",ios::app); // uses append mode (ios::app), which means:
                                                // If inventory.txt does not exist → C++ creates it automatically
                                                //If it exists → new records get added at the end

        if(!fout)
        {
            cout<<"File Error\n";
            goto M;
        }

        cout<<"Enter Item Name : ";
        cin>>name;

        cout<<"Enter Quantity : ";
        cin>>qty;

        cout<<"Enter Price : ";
        cin>>price;


        fout<<name<<" "
            <<qty<<" "
            <<price<<"\n";

        fout.close();

        cout<<"Item Added Successfully\n";

        goto M;
    }



    case 2:
    {
        ifstream fin;

        fin.open("inventory-5.3.txt");

        if(!fin)
        {
            cout<<"File Error\n";
            goto M;
        }

        cout<<"\nInventory Records\n";

        while(fin>>name>>qty>>price)
        {
            cout<<"\nItem Name : "<<name;
            cout<<"\nQuantity : "<<qty;
            cout<<"\nPrice : "<<price<<endl;
        }

        fin.close();

        goto M;
    }



    case 3:
    {
        ifstream fin;

        fin.open("inventory-5.3.txt");

        if(!fin)
        {
            cout<<"File Error\n";
            goto M;
        }

        cout<<"Enter Item Name to Search : ";
        cin>>search_name;

        int found=0;


        while(fin>>name>>qty>>price)
        {
            if(name==search_name)
            {
                cout<<"\nItem Found\n";

                cout<<"Item Name : "<<name<<endl;

                cout<<"Quantity : "<<qty<<endl;

                cout<<"Price : "<<price<<endl;

                found=1;

                break;
            }
        }


        if(found==0)
        {
            cout<<"Item Not Found\n";
        }

        fin.close();

        goto M;
    }



    case 4:
        break;



    default:

        cout<<"Invalid Choice\n";

        goto M;
    }


    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
