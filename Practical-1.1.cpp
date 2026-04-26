#include <iostream>
#include <string>
using namespace std;

class accManagement {
public:
    void create_wallet();
    int load_money(long int);
    int transfer_money(long int, long int, long long);
    int display_detail(long int);
    long int getID();   // added

private:
    long int id;
    string username;
    long long balance;
};

void accManagement::create_wallet() {
    cout << "Enter Wallet ID : ";
    cin >> id;

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Current Balance : ";
    cin >> balance;
}

long int accManagement::getID() {
    return id;
}

int accManagement::load_money(long int x) {
    long long amt;

    if(id==x) {
        cout<<"Enter amount to add : ";
        cin>>amt;

        if(amt<=0) {
            cout<<"Invalid amount\n";
            return 0;
        }

        balance+=amt;
        return 1;
    }

    return 0;
}

int accManagement::transfer_money(long int from_id,long int to_id,long long amt) {

    // Sender
    if(id==from_id) {

        if(balance>=amt) {
            balance-=amt;
            return 1;
        }

        else {
            cout<<"ERROR: Insufficient balance\n";
            return -1;
        }
    }

    // Receiver
    if(id==to_id) {
        balance+=amt;
        return 2;
    }

    return 0;
}

int accManagement::display_detail(long int x) {

    if(id==x) {
        cout<<"Balance : "<<balance<<endl;
        return 1;
    }

    return 0;
}

int main() {

    accManagement A[25];

    int ch,last=0,i;

    long int wi,wit;
    long long trans_amt;

M:

    cout<<"\n1:Create Wallet | 2:Load Money | 3:Transfer Money | 4:Display Wallet | 5:Exit --> ";
    cin>>ch;

    switch(ch) {

    case 1:

        // Wallet limit check
        if(last==25) {
            cout<<"ERROR: Maximum wallet limit reached\n";
            goto M;
        }

        A[last].create_wallet();
        last++;

        goto M;



    case 2:

        cout<<"Enter Wallet ID : ";
        cin>>wi;

        for(i=0;i<last;i++) {

            if(A[i].load_money(wi)==1)
                break;
        }

        if(i==last)
            cout<<"ERROR: Wallet does not exist\n";

        goto M;



    case 3:
    {
        cout<<"Enter Sender Wallet ID : ";
        cin>>wi;

        cout<<"Enter Receiver Wallet ID : ";
        cin>>wit;

        if(wi==wit) {
            cout<<"Cannot transfer to same wallet\n";
            goto M;
        }

        cout<<"Enter amount to transfer : ";
        cin>>trans_amt;

        int senderIndex=-1;
        int receiverIndex=-1;

        // FIRST find both wallets
        for(i=0;i<last;i++) {

            if(A[i].getID()==wi)
                senderIndex=i;

            if(A[i].getID()==wit)
                receiverIndex=i;
        }

        // If either missing, stop BEFORE deduction
        if(senderIndex==-1 || receiverIndex==-1) {
            cout<<"ERROR: Invalid Wallet ID(s)\n";
            goto M;
        }

        // Deduct from sender
        if(A[senderIndex].transfer_money(wi,wit,trans_amt)==-1)
            goto M;

        // Add to receiver
        A[receiverIndex].transfer_money(wi,wit,trans_amt);

        cout<<"Transfer Successful\n";

        goto M;
    }



    case 4:

        cout<<"Enter Wallet ID : ";
        cin>>wi;

        for(i=0;i<last;i++) {

            if(A[i].display_detail(wi)==1)
                break;
        }

        if(i==last)
            cout<<"ERROR: Wallet does not exist\n";

        goto M;



    case 5:
        break;



    default:
        cout<<"ERROR: Invalid Choice\n";
        goto M;
    }

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069
