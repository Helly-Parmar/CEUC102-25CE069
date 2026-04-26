#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int n,i;
    long long sum=0;

    cout<<"Enter size of array : ";
    cin>>n;

    int a[n];

    cout<<"Enter "<<n<<" elements :\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    auto before = high_resolution_clock::now();

    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }

    auto after = high_resolution_clock::now();

    auto duration=
    duration_cast<microseconds>(after-before);

    cout<<"Iterative Sum = "<<sum<<endl;
    cout<<"Execution Time = "
        <<duration.count()
        <<" microseconds";

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069

