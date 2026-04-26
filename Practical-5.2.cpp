#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream fin;

    string line;

    int char_count=0;
    int word_count=0;
    int line_count=0;


    fin.open("input-5.2.txt");


    if(!fin)
    {
        cout<<"Error: File could not open\n";
        return 0;
    }



    while(getline(fin,line))
    {
        line_count++;

        int inWord=0;


        for(int i=0;i<line.length();i++)
        {
            char_count++;


            if(line[i]!=' ' && line[i]!='\t')
            {
                if(inWord==0)
                {
                    word_count++;

                    inWord=1;
                }
            }

            else
            {
                inWord=0;
            }
        }
    }


    fin.close();


    cout<<"\nTotal Characters : "<<char_count<<endl;

    cout<<"Total Words : "<<word_count<<endl;

    cout<<"Total Lines : "<<line_count<<endl;


    return 0;
}


// Name : Helly Parmar
// ID : 25CE069
