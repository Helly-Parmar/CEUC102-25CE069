#include<iostream>
#include<string>
using namespace std;


// Recursive function for super digit
int super_digit(long long n)
{
    if(n<10)
    {
        return n;
    }

    long long sum=0;

    while(n>0)
    {
        sum=sum+(n%10);
        n=n/10;
    }

    return super_digit(sum);
}



// Function to sum digits of original string
long long digit_sum(string n)
{
    long long sum=0;

    int i;

    for(i=0;i<n.length();i++)
    {
        sum=sum+(n[i]-'0');
    }

    return sum;
}



int main()
{
    string n;

    long long k;
    long long initial_sum;

    cout<<"Enter Number (as string) : ";
    cin>>n;

    cout<<"Enter repetition value k : ";
    cin>>k;


    // Mathematical optimization
    initial_sum=digit_sum(n)*k;

    cout<<"Initial Combined Sum : "<<initial_sum<<endl;

    cout<<"Super Digit : "<<super_digit(initial_sum)<<endl;


    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
