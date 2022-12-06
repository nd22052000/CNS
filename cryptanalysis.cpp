
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string> dict;
    dict.insert("i");
    dict.insert("am");
    dict.insert("in");
    dict.insert("cns");
    dict.insert("lab");
    dict.insert("for");
    dict.insert("LA");
    string s, org;
    cout << "Enter Cipher text" << endl;
    cin>>s;
    string x;
    int k = 0;
    cout << "\nCipher text is: " << s << endl << endl;
    org = s;
    for (int k = 0; k < 26; k++)
    {
        cout << "Keep Key as: " << k << endl;
        s = org;
        string word = "";
        int flg = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
            if (dict.find(word) == dict.end())
            {
            flg = 1;
            break;
            }
            word = "";
            continue;
            }
            int val = s[i] - 'a';
            val = (val - k + 26) % 26;
            char ch = 'a' + val;
            word += ch;
            s[i] = ch;
        }
        if (dict.find(word) == dict.end())
        {
            flg = 1;
        }
        if (flg == 0)
        cout << s << endl << endl;
    }

}
