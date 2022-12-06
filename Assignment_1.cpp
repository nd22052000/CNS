#include<bits/stdc++.h>
using namespace std;

void encrypt()
{
    string input,output;
    int key = 0;

    cout<<"\n Enter plain text : ";
    cin.clear();
    cin.sync();
    getline(cin,input);

    // Removing all spaces and converting to small letters
    for(int i=0;i<input.size();i++)
    {
        if(input[i]!=' ')
        output += input[i];

        if(input[i]>=65 && input[i]<=90)
        output[i] += 32;
    }

    cout<<"\n Enter key : ";
    cin>>key;

    for (int i=0;i<output.size();i++)
    {
        int val = output[i] - 'a';
        val = (val + key) % 26;
        char ch = 'a' + val;
        output[i] = ch;
    }
    cout<< "\n Cipher Text is : "<<output<<endl;
}

void decrypt()
{
    string input,output;
    int key;
    cout<<"\n Enter cipher text : ";
    cin.clear();
    cin.sync();

    getline(cin,input);

    // Removing all spaces and converting to small letters
    for(int i=0;i<input.size();i++)
    {
        if(input[i]!=' ')
        output += input[i];

        if(input[i]>=65 && input[i]<=90)
        output[i] += 32;
    }

    cout<<"\n Enter key : ";
    cin>>key;

    for (int i=0;i<output.size();i++)
    {
        int val = output[i] - 'a';
        val = (val - key + 26) % 26;
        char ch = 'a' + val;
        output[i] = ch;
    }

    cout<< "\n Plain Text is : "<<output<<endl;
}

int main()
{
    int choice = 1;
    cout<<"\n**** Caeser Cipher ****\n";
    cout<<"\n 1. Encrypt\n 2. Decrypt\n\n Enter choice : ";
    cin>>choice;

    if(choice == 1)
    encrypt();
    else if(choice == 2)
    decrypt();
    else
    cout<<"\n Invalid option !";
    return 0;
}