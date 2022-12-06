#include<bits/stdc++.h>
using namespace std;

int main()
{
    string plainText,key,cipherText;

    cout<<"\n Enter plain text : ";
    getline(cin,plainText);

    cout<<"\n Enter key : ";
    getline(cin,key);

    // Removing spaces and converting to small from plaintext
    string temp = "";
    for(int i=0;i<plainText.size();i++)
    {
        if(plainText[i]!=' ')
        temp += plainText[i];
    }
    plainText = temp;

    for(int i=0;i<plainText.size();i++)
    {
        if(plainText[i]>=65 && plainText[i]<=90)
        plainText[i] += 32;
    }

    // Removing spaces and converting to small from key
    string temp2 = "";
    for(int i=0;i<key.size();i++)
    {
        if(key[i]!=' ')
        temp2 += key[i];
    }
    key = temp2;

    for(int i=0;i<key.size();i++)
    {
        if(key[i]>=65 && key[i]<=90)
        key[i] += 32;
    }

    // Encryption
    for(int i=0;i<plainText.size();i++)
    {
        int val = plainText[i]-'a' + key[i%(key.size())]-'a';
        cipherText += 'a' + (val%26);
    }

    cout<<"\n Cipher Text : "<<cipherText<<endl;


    // Decryption
    string decrypted = "";
    for(int i=0;i<cipherText.size();i++)
    {
        int val = cipherText[i]-'a' - (key[i%(key.size())]-'a') + 26;
        decrypted += 'a' + (val%26);
    }

    cout<<"\n After decryption : "<<decrypted<<endl;
    return 0;
}