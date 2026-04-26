#include<iostream>
using namespace std;

class Inventory
{
private:
    int item_id;
    string item_name;
    int quantity;
    float price;

public:

    // default constructor
    Inventory()
    {
        item_id=0;
        item_name="Default";
        quantity=0;
        price=0;
    }

    // parameterized constructor
    Inventory(int id,string name,int q,float p)
    {
        item_id=id;
        item_name=name;
        quantity=q;
        price=p;
    }

    void add_item();
    int restock_item(int);
    int sell_item(int);
    int display_item(int);
};


void Inventory::add_item()
{
    cout<<"Enter Item ID : ";
    cin>>item_id;

    cout<<"Enter Item Name : ";
    cin>>item_name;

    cout<<"Enter Quantity : ";
    cin>>quantity;

    cout<<"Enter Price : ";
    cin>>price;
}


int Inventory::restock_item(int x)
{
    int add_qty;

    if(item_id==x)
    {
        cout<<"Enter quantity to add : ";
        cin>>add_qty;

        if(add_qty<=0)
        {
            cout<<"Invalid quantity\n";
            return 1;
        }

        quantity=quantity+add_qty;

        cout<<"Stock updated successfully\n";
        return 1;
    }

    return 0;
}


int Inventory::sell_item(int x)
{
    int sell_qty;

    if(item_id==x)
    {
        cout<<"Enter quantity to sell : ";
        cin>>sell_qty;

        if(sell_qty<=0)
        {
            cout<<"Invalid quantity\n";
            return 1;
        }

        if(sell_qty>quantity)
        {
            cout<<"ERROR: Not enough stock\n";
            return 1;
        }

        quantity=quantity-sell_qty;

        cout<<"Sale successful\n";
        return 1;
    }

    return 0;
}


int Inventory::display_item(int x)
{
    if(item_id==x)
    {
        cout<<"\nItem ID : "<<item_id<<endl;
        cout<<"Item Name : "<<item_name<<endl;
        cout<<"Quantity : "<<quantity<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Stock Value : "<<quantity*price<<endl;

        return 1;
    }

    return 0;
}


int main()
{
    Inventory I[25];

    int ch,last=0,i,id;

M:

    cout<<"\n1.Add Item";
    cout<<"\n2.Add Test Item";
    cout<<"\n3.Restock Item";
    cout<<"\n4.Sell Item";
    cout<<"\n5.Display Item";
    cout<<"\n6.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

        case 1:

            if(last==25)
            {
                cout<<"Inventory full\n";
                goto M;
            }

            I[last].add_item();

            cout<<"Item "<<last+1<<" added successfully\n";

            last++;

            goto M;



        case 2:

            if(last==25)
            {
                cout<<"Inventory full\n";
                goto M;
            }

            // parameterized constructor use
            I[last]=Inventory(100+last,"TestItem",50,100);

            cout<<"Test item added successfully\n";

            last++;

            goto M;



        case 3:

            cout<<"Enter Item ID : ";
            cin>>id;

            for(i=0;i<last;i++)
            {
                if(I[i].restock_item(id)==1)
                    break;
            }

            if(i==last)
                cout<<"Item not found\n";

            goto M;



        case 4:

            cout<<"Enter Item ID : ";
            cin>>id;

            for(i=0;i<last;i++)
            {
                if(I[i].sell_item(id)==1)
                    break;
            }

            if(i==last)
                cout<<"Item not found\n";

            goto M;



        case 5:

            cout<<"Enter Item ID : ";
            cin>>id;

            for(i=0;i<last;i++)
            {
                if(I[i].display_item(id)==1)
                    break;
            }

            if(i==last)
                cout<<"Item not found\n";

            goto M;



        case 6:
            break;


        default:
            cout<<"Invalid Choice\n";
            goto M;
    }

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069
