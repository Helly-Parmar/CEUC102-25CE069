#include<iostream>
using namespace std;


template<class T>
void display(T a[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
}



template<class T>
T maximum(T a[],int n)
{
    T max=a[0];

    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    return max;
}



template<class T>
void reverse_arr(T a[],int n)
{
    T temp;

    for(int i=0;i<n/2;i++)
    {
        temp=a[i];

        a[i]=a[n-1-i];

        a[n-1-i]=temp;
    }
}



template<class T>
void leaders(T a[],int n)
{
    T leader=a[n-1];

    cout<<"Leader Elements : ";

    cout<<leader<<" ";

    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>leader)
        {
            leader=a[i];

            cout<<leader<<" ";
        }
    }

    cout<<endl;
}



int main()
{
    int n1,n2,n3;


    cout<<"Enter size of integer array : ";
    cin>>n1;

    int a[50];

    cout<<"Enter integer elements :\n";

    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
    }


    cout<<"\nInteger Array : ";
    display(a,n1);

    cout<<"Maximum = "
        <<maximum(a,n1)<<endl;

    reverse_arr(a,n1);

    cout<<"Reversed Array : ";

    display(a,n1);

    leaders(a,n1);



    cout<<"\nEnter size of float array : ";
    cin>>n2;

    float b[50];

    cout<<"Enter float elements :\n";

    for(int i=0;i<n2;i++)
    {
        cin>>b[i];
    }


    cout<<"\nFloat Array : ";

    display(b,n2);

    cout<<"Maximum = "
        <<maximum(b,n2)<<endl;

    reverse_arr(b,n2);

    cout<<"Reversed Array : ";

    display(b,n2);

    leaders(b,n2);



    cout<<"\nEnter size of character array : ";
    cin>>n3;

    char c[50];

    cout<<"Enter character elements :\n";

    for(int i=0;i<n3;i++)
    {
        cin>>c[i];
    }


    cout<<"\nCharacter Array : ";

    display(c,n3);

    cout<<"Maximum = "
        <<maximum(c,n3)<<endl;

    reverse_arr(c,n3);

    cout<<"Reversed Array : ";

    display(c,n3);

    leaders(c,n3);


    return 0;
}


// Name : Helly Parmar
//ID : 25CE069
