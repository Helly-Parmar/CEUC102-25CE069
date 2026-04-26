#include<iostream>
using namespace std;


class Account
{
protected:
    int acc_no;
    float balance;

    float trans[50];
    int top;

public:

    Account()
    {
        acc_no = 0;
        balance = 0;
        top = -1;
    }

    Account(int a, float b)
    {
        acc_no = a;
        balance = b;
        top = -1;
    }


    void deposit(float amt)
    {
        if(amt <= 0)
        {
            cout<<"Invalid Amount\n";
            return;
        }

        balance = balance + amt;

        if(top < 49)
        {
            trans[++top] = amt;
        }

        cout<<"Amount Deposited\n";
    }


    void withdraw(float amt)
    {
        if(amt <= 0)
        {
            cout<<"Invalid Amount\n";
            return;
        }

        if(balance >= amt)
        {
            balance = balance - amt;

            if(top < 49)
            {
                trans[++top] = -amt;
            }

            cout<<"Withdraw Successful\n";
        }
        else
        {
            cout<<"Not Enough Balance\n";
        }
    }


    void undo()
    {
        if(top == -1)
        {
            cout<<"No Transaction Found\n";
            return;
        }

        balance = balance - trans[top];
        top--;

        cout<<"Last Transaction Undone\n";
    }


    void showHistory()
    {
        if(top == -1)
        {
            cout<<"No Transactions Yet\n";
            return;
        }

        cout<<"Transaction History:\n";

        for(int i=0; i<=top; i++)
        {
            cout<<trans[i]<<endl;
        }
    }


    void display()
    {
        cout<<"Account No : "<<acc_no<<endl;
        cout<<"Balance : "<<balance<<endl;
    }


    ~Account()
    {
        cout<<"Account Closed\n";
    }
};




class Savings : public Account
{
private:
    float rate;

public:

    Savings()
    {
        rate = 4;
    }


    void getData()
    {
        cout<<"Enter Account No : ";
        cin>>acc_no;

        cout<<"Enter Balance : ";
        cin>>balance;

        cout<<"Enter Interest Rate : ";
        cin>>rate;
    }


    void addInterest()
    {
        float interest = (balance * rate) / 100;

        balance = balance + interest;

        cout<<"Interest Added\n";
    }


    void display()
    {
        Account::display();
        cout<<"Interest Rate : "<<rate<<"%"<<endl;
    }


    ~Savings()
    {
        cout<<"Savings Account Closed\n";
    }
};




class Current : public Account
{
private:
    float overdraft;

public:

    Current()
    {
        overdraft = 5000;
    }


    void getData()
    {
        cout<<"Enter Account No : ";
        cin>>acc_no;

        cout<<"Enter Balance : ";
        cin>>balance;

        cout<<"Enter Overdraft Limit : ";
        cin>>overdraft;
    }


    void withdraw(float amt)
    {
        if(amt <= 0)
        {
            cout<<"Invalid Amount\n";
            return;
        }

        if(balance + overdraft >= amt)
        {
            balance = balance - amt;

            if(top < 49)
            {
                trans[++top] = -amt;
            }

            cout<<"Withdraw Successful\n";
        }
        else
        {
            cout<<"Overdraft Limit Crossed\n";
        }
    }


    void display()
    {
        Account::display();
        cout<<"Overdraft Limit : "<<overdraft<<endl;
    }


    ~Current()
    {
        cout<<"Current Account Closed\n";
    }
};




int main()
{
    Savings s;
    Current c;

    int ch;
    float amt;

    do
    {
        cout<<"\n1.Create Savings";
        cout<<"\n2.Create Current";
        cout<<"\n3.Deposit Savings";
        cout<<"\n4.Withdraw Savings";
        cout<<"\n5.Withdraw Current";
        cout<<"\n6.Add Interest (Savings)";
        cout<<"\n7.Undo (Savings)";
        cout<<"\n8.Show History (Savings)";
        cout<<"\n9.Display Accounts";
        cout<<"\n10.Exit";

        cout<<"\nEnter Choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            s.getData();
            break;

        case 2:
            c.getData();
            break;

        case 3:
            cout<<"Enter Amount : ";
            cin>>amt;
            s.deposit(amt);
            break;

        case 4:
            cout<<"Enter Amount : ";
            cin>>amt;
            s.withdraw(amt);
            break;

        case 5:
            cout<<"Enter Amount : ";
            cin>>amt;
            c.withdraw(amt);
            break;

        case 6:
            s.addInterest();
            break;

        case 7:
            s.undo();
            break;

        case 8:
            s.showHistory();
            break;

        case 9:
            cout<<"\nSavings Account\n";
            s.display();

            cout<<"\nCurrent Account\n";
            c.display();
            break;

        case 10:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid Choice\n";
        }

    }while(ch != 10);

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
