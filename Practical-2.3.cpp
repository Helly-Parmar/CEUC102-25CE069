#include<iostream>
using namespace std;

class SavingsAccount
{
private:
    long int acc_id;
    string name;
    float balance;

public:

    // default constructor (zero balance account)
    SavingsAccount()
    {
        acc_id=0;
        name="Default";
        balance=0;
    }

    // parameterized constructor (custom initial balance)
    SavingsAccount(long int id,string n,float b)
    {
        acc_id=id;
        name=n;
        balance=b;
    }

    void create_account();
    void deposit(long int);
    void withdraw(long int);
    int display(long int);
};

void SavingsAccount::create_account()
{
    cout<<"Enter Account ID : ";
    cin>>acc_id;

    cout<<"Enter Customer Name : ";
    cin>>name;

    cout<<"Enter Initial Balance : ";
    cin>>balance;

    if(balance<0)
        balance=0;
}

void SavingsAccount::deposit(long int x)
{
    float amt;

    if(acc_id==x)
    {
        cout<<"Enter Deposit Amount : ";
        cin>>amt;

        if(amt<=0)
        {
            cout<<"Invalid amount\n";
            return;
        }

        balance=balance+amt;

        cout<<"Deposit Successful\n";
    }
}

void SavingsAccount::withdraw(long int x)
{
    float amt;

    if(acc_id==x)
    {
        cout<<"Enter Withdrawal Amount : ";
        cin>>amt;

        if(amt<=0)
        {
            cout<<"Invalid amount\n";
            return;
        }

        if(amt>balance)
        {
            cout<<"ERROR: Insufficient Balance\n";
            return;
        }

        balance=balance-amt;

        cout<<"Withdrawal Successful\n";
    }
}

int SavingsAccount::display(long int x)
{
    if(acc_id==x)
    {
        cout<<"\nAccount ID : "<<acc_id<<endl;
        cout<<"Customer Name : "<<name<<endl;
        cout<<"Current Balance : "<<balance<<endl;

        return 1;
    }

    return 0;
}

int main()
{
    SavingsAccount A[25];

    int ch,last=0,i;
    long int id;

M:

    cout<<"\n1.Create Account";
    cout<<"\n2.Add Test Account";
    cout<<"\n3.Deposit";
    cout<<"\n4.Withdraw";
    cout<<"\n5.Display Account";
    cout<<"\n6.Exit";

    cout<<"\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {

    case 1:

        if(last==25)
        {
            cout<<"Account storage full\n";
            goto M;
        }

        A[last].create_account();

        cout<<"Account "<<last+1<<" created successfully\n";

        last++;

        goto M;



    case 2:

        if(last==25)
        {
            cout<<"Account storage full\n";
            goto M;
        }

        // parameterized constructor use
        A[last]=SavingsAccount(1001+last,"TestUser",5000);

        cout<<"Test account added successfully\n";

        last++;

        goto M;



    case 3:

        cout<<"Enter Account ID : ";
        cin>>id;

        for(i=0;i<last;i++)
        {
            if(A[i].display(id)==1)
            {
                A[i].deposit(id);
                break;
            }
        }

        if(i==last)
            cout<<"Account not found\n";

        goto M;



    case 4:

        cout<<"Enter Account ID : ";
        cin>>id;

        for(i=0;i<last;i++)
        {
            if(A[i].display(id)==1)
            {
                A[i].withdraw(id);
                break;
            }
        }

        if(i==last)
            cout<<"Account not found\n";

        goto M;



    case 5:

        cout<<"Enter Account ID : ";
        cin>>id;

        for(i=0;i<last;i++)
        {
            if(A[i].display(id)==1)
                break;
        }

        if(i==last)
            cout<<"Account not found\n";

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
