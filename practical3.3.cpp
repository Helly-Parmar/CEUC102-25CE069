#include<iostream>
using namespace std;

class acc_tracking
{
private:

    int acc_num;
    string name;
    float balance;

    static int total_accounts;

public:

    void create_acc();

    int transfer_money
    (int sender,int receiver,float amt,
     acc_tracking A[],int n);

    void display();

    int search(int x);

    static void show_total();

};

int acc_tracking::total_accounts=0;


void acc_tracking::create_acc()
{
    cout<<"Enter account number : ";
    cin>>acc_num;

    cout<<"Enter name : ";
    cin>>name;

    cout<<"Enter current balance : ";
    cin>>balance;

    total_accounts++;
}


int acc_tracking::search(int x)
{
    if(acc_num==x)
    {
        return 1;
    }

    return 0;
}


int acc_tracking::transfer_money
(int sender,int receiver,float amt,
 acc_tracking A[],int n)
{
    int s=-1,r=-1,i;

    for(i=0;i<n;i++)
    {
        if(A[i].acc_num==sender)
        {
            s=i;
        }

        if(A[i].acc_num==receiver)
        {
            r=i;
        }
    }

    if(s==-1 || r==-1)
    {
        cout<<"Account not found\n";
        return 0;
    }

    if(amt<=0)
    {
        cout<<"Invalid amount\n";
        return 0;
    }

    if(A[s].balance<amt)
    {
        cout<<"Insufficient balance\n";
        return 0;
    }

    A[s].balance=
    A[s].balance-amt;

    A[r].balance=
    A[r].balance+amt;

    cout<<"Transfer successful\n";

    return 1;
}



void acc_tracking::display()
{
    cout<<"\nAccount Number : "
        <<acc_num;

    cout<<"\nName : "
        <<name;

    cout<<"\nBalance : "
        <<balance<<endl;
}



void acc_tracking::show_total()
{
    cout<<"\nTotal Accounts : "
        <<total_accounts<<endl;
}



int main()
{
    int n,i,ch;
    int s,r;
    float amt;

    cout<<"Enter number of accounts : ";
    cin>>n;

    acc_tracking *A=
    new acc_tracking[n];


    for(i=0;i<n;i++)
    {
        cout<<"\nAccount "<<i+1<<endl;

        A[i].create_acc();
    }


M:

    cout<<"\n1.Transfer Money";
    cout<<"\n2.Display Accounts";
    cout<<"\n3.Show Total Accounts";
    cout<<"\n4.Exit";
    cout<<"\nEnter choice : ";

    cin>>ch;

    switch(ch)
    {

    case 1:

        cout<<"Sender Account : ";
        cin>>s;

        cout<<"Receiver Account : ";
        cin>>r;

        cout<<"Amount : ";
        cin>>amt;

        A[0].transfer_money
        (s,r,amt,A,n);

        goto M;


    case 2:

        for(i=0;i<n;i++)
        {
            A[i].display();
        }

        goto M;


    case 3:

        acc_tracking::show_total();

        goto M;


    case 4:

        break;


    default:

        cout<<"Invalid Choice\n";

        goto M;

    }


    delete[] A;

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069

