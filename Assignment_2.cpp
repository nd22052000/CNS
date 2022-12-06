#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    vector<string> dictionary{"harshal","kodgire","walchand","college","friend"};
    vector<string> vs;
    int key = 0;
    cout<<"\n**** Crypt Analysis ****\n";
    cout<<"\n Enter cipher text : ";
    getline(cin,input);

    string output;

    for(int i=0;i<input.size();i++)
    {
        if(input[i]!=' ')
        output += input[i];

        if(input[i]>=65 && input[i]<=90)
        output[i] += 32;
    }

    // cout<<"\n Enter key to decrypt : ";
    // cin>>key;

    for(int j=0;j<25;j++)
    {
        key = j;
        for (int i=0;i<output.size();i++)
        {
            int val = output[i] - 'a';
            val = (val - key + 26) % 26;
            char ch = 'a' + val;
            output[i] = ch;
        }
        vs.push_back(output);
    }

    int i = 0;
    int flg = 0;
    for(i=0;i<vs.size();i++)
    {
        for(int j=0;j<dictionary.size();j++)
        {
            if(dictionary[j].compare(vs[i])==0)
            {
                cout<<"\n Word found in dictionary !"<<endl;
                cout<< "\n Plain Text is : "<<dictionary[j]<<endl;
                flg = 1;
                break;
            }
        }

        if(flg)
        break;
    }    
    
    if(!flg)
    {
        cout<<"\n Word not found in dictionary !";
        cout<<"\n All possible plain texts are : "<<endl;
        for(int i=0;i<vs.size();i++)
        cout<<vs[i]<<endl;
    }
    return 0;
}