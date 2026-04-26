#include<iostream>
using namespace std;

int main()
{
    int n,m;
    int i,j,k=0;

    cout<<"Enter size of first array : ";
    cin>>n;
    cout<<"Enter size of second array : ";
    cin>>m;

    int *p = new int[n];
    int *q = new int[m];

    cout<<"Enter first sorted array : ";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }


    cout<<"Enter second sorted array : ";
    for(int i=0;i<m;i++)
    {
        cin>>q[i];
    }

    int *result = new int[n+m];

    i=0,j=0,k=0;

    while(i<n && j<m)
    {
        if(p[i]<q[j])
        {
            result[k++]=p[i++];
        }
        else{
            result[k++]=q[j++];
        }
    }

    while(i<n)
    {
        result[k++]=p[i++];
    }

    while(j<m)
    {
        result[k++]=q[j++];
    }

    cout<<"Result : ";
    for(int x=0; x<n+m; x++)
    {
        cout<<result[x]<<" , ";

    }

    delete []p;
    delete []q;
    delete []result;

    return 0;
}

// Name : Helly Parmar
// ID : 25CE069
