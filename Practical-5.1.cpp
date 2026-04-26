#include<iostream>
using namespace std;

int main()
{
    string paragraph;

    cout<<"Enter Paragraph : ";
    getline(cin,paragraph);


    // Convert uppercase to lowercase
    for(int i=0;i<paragraph.length();i++)
    {
        if(paragraph[i]>='A' && paragraph[i]<='Z')
        {
            paragraph[i]=paragraph[i]+32;
        }
    }


    string words[100];
    int freq[100]={0};

    int count=0;

    string word="";


    // Split into words manually
    for(int i=0;i<=paragraph.length();i++)
    {
        if(i!=paragraph.length() && paragraph[i]!=' ')
        {
            word=word+paragraph[i];
        }
        else
        {
            if(word!="")
            {
                words[count]=word;
                count++;

                word="";
            }
        }
    }



    // Frequency count
    for(int i=0;i<count;i++)
    {
        if(freq[i]==0)
        {
            freq[i]=1;

            for(int j=i+1;j<count;j++)
            {
                if(words[i]==words[j])
                {
                    freq[i]++;

                    freq[j]=-1;
                }
            }
        }
    }



    cout<<"\nWord Frequency:\n";

    for(int i=0;i<count;i++)
    {
        if(freq[i]!=-1)
        {
            cout<<words[i]<<" : "<<freq[i]<<endl;
        }
    }

    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
