#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

long long arrsum(int a[],int n)
{
    if(n==0)
    {
        return 0;
    }

    return a[n-1]+arrsum(a,n-1);
}

int main()
{
    int n,i;
    long long sum;

    cout<<"Enter size of array : ";
    cin>>n;

    int a[n];

    cout<<"Enter "<<n<<" elements :\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    auto before=
    high_resolution_clock::now();

    sum=arrsum(a,n);

    auto after=
    high_resolution_clock::now();

    auto duration=
    duration_cast<microseconds>
    (after-before);

    cout<<"Recursive Sum = "
        <<sum<<endl;

    cout<<"Execution Time = "
        <<duration.count()
        <<" microseconds";

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069

