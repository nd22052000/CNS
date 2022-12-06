// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string key;
//     string cipherText;
//     string plainText;
//     char matrix[5][5];
//     int freqArr[26] = {0};
//     vector<pair<int,int>> location(26,{-1,-1});

//     cout<<"\n Enter key : ";
//     getline(cin,key);

//     cout<<"\n Enter plain text : ";
//     getline(cin,plainText);

//     // Removing spaces from key
//     string temp = "";
//     for(int i=0;i<key.size();i++)
//     {
//         if(key[i]!=' ')
//         temp += key[i];
//     }
//     key = temp;

//     for(int i=0;i<key.size();i++)
//     {
//         if(key[i]>=65 && key[i]<=90)
//         key[i] += 32;
//     }

//     // Removing spaces from plain text and converting in small character
//     string temp2 = "";
//     for(int i=0;i<plainText.size();i++)
//     {
//         if(plainText[i]!=' ')
//         temp2 += plainText[i];
//     }
//     plainText = temp2;

//     for(int i=0;i<plainText.size();i++)
//     {
//         if(plainText[i]>=65 && plainText[i]<=90)
//         plainText[i] += 32;
//     }
//     cipherText = plainText;

//     int row = 0,col = 0;

//     for(int i=0;i<key.size();i++)
//     {
//         row = row % 5;
//         col = col % 5;

//         if(freqArr[key[i]-'a']==0)
//         {
//             if((key[i]=='j' || key[i]=='i') && (freqArr[8] || freqArr[9]))
//             continue;

//             matrix[row][col] = key[i];
//             col++;
//             freqArr[key[i]-'a'] = 1;
//         }

//         if(col==5)
//         {
//             col = 0;
//             row++;
//         }
//     }

//     for(int i=0;i<26;i++)
//     {
//         if(freqArr[i]==0)
//         {
//             if((i==8 && freqArr[9]==1) || (i==9 && freqArr[8]==1)){
//             continue;
//             }
//             matrix[row][col] = 'a'+i;
//             col++;
//             freqArr[i] = 1;
//         }
//     }

//     cout<<endl;
//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             cout<<matrix[i][j]<<" ";
//             location[matrix[i][j]-'a'] = {i,j};
//         }
//         cout<<endl;
//     }

//     char dummyChar = matrix[5][5];

//     cout<<"Plain Text : "<<plainText<<endl;
//     cout<<"Key : "<<key<<endl;

//     for(int i=0;i<plainText.size();)
//     {
//         // cout<<i<<endl;
//         if(i+1<plainText.size())
//         {
//             if(plainText[i]==plainText[i+1])
//             {
//                 // Taking last char of matrix as dummy
//                 cipherText[i] = matrix[location[plainText[i]].first][4];
//                 i = i + 1;
//             }
//             else
//             {
//                 // check if both have same row
//                 if(location[plainText[i]-'a'].first == location[plainText[i+1]-'a'].first)
//                 {
//                     cipherText[i] = matrix[location[plainText[i]-'a'].first][(location[plainText[i]-'a'].second+1)%5];
//                     cipherText[i+1] = matrix[location[plainText[i+1]-'a'].first][(location[plainText[i+1]-'a'].second+1)%5];
//                 }

//                 // check if both have same column
//                 else if(location[plainText[i]-'a'].second == location[plainText[i+1]-'a'].second)
//                 {
//                     cipherText[i] = matrix[(location[plainText[i]-'a'].first+1)%5][location[plainText[i]-'a'].second];
//                     cipherText[i+1] = matrix[(location[plainText[i+1]-'a'].first+1)%5][location[plainText[i+1]-'a'].second];
//                 }

//                 // Interchange columns
//                 else
//                 {
//                     cipherText[i] = matrix[location[plainText[i]-'a'].first][location[plainText[i+1]-'a'].second];
//                     cipherText[i+1] = matrix[location[plainText[i+1]-'a'].first][location[plainText[i]-'a'].second];
//                 }
//                 i = i + 2;
//             }
//         }
//         else
//         {
//             // Taking last char of matrix as dummy
//             cout<<"Yaha"<<endl;
//             cipherText[i] = matrix[location[key[i]].first][4];
//             i = i + 1;
//         }
//     }
//     cout<<"\n Cipher Text : "<<cipherText<<endl;

//     return 0;
// }   


//playfair

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "\n Enter plain text : ";
    getline(cin, s);

    string x;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            x += s[i];
    s = x;

    string k;
    cout << "\n Enter key : ";
    cin >> k;

    char mat[5][5];
    int row = 0, col = 0;
    map<char, int> m;
    for (int i = 0; i < k.size(); i++)
    {
        if (m.find(k[i]) != m.end() || k[i] == 'j')
            continue;
        mat[row][col] = k[i];
        m[k[i]] = 1;
        col++;
        if (col == 5)
        {
            col = 0;
            row++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        char ch = 'a' + i;

        if (ch == 'j')
            continue;

        if (m.find(ch) != m.end())
            continue;
        m[ch] = 1;
        mat[row][col] = ch;
        col++;
        if (col == 5)
        {
            col = 0;
            row++;
        }
    }

    map<char, pair<int, int>> loc;
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << " ";
            loc[mat[i][j]] = {i, j};
        }
        cout << endl;
    }

    x = "";

    string pos = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (i == (s.length() - 1))
        {
            x += s[i];
            x += 'x';
            pos += '*';
            pos += '#';
        }
        else
        {
            x += s[i];
            pos += '*';
            if (s[i] == s[i + 1])
            {

                x += 'x';
                pos += '#';
            }
            else
            {
                x += s[i + 1];
                i++;
                pos += '*';
            }
        }
    }

    s = x;

    cout << "\n Plain text : " << s << endl;
    cout << "\n Key : " << k << endl;
    for (int i = 0; i < s.length(); i += 2)
    {
        char ft = s[i];
        int ftR = loc[ft].first;
        int ftC = loc[ft].second;

        char sd = s[i + 1];
        int sdR = loc[sd].first;
        int sdC = loc[sd].second;

        if (ftR == sdR)
        {
            s[i] = (mat[ftR][(ftC + 1) % 5]);
            s[i + 1] = (mat[ftR][(sdC + 1) % 5]);
            continue;
        }

        if (ftC == sdC)
        {
            s[i] = (mat[(ftR + 1) % 5][ftC]);
            s[i + 1] = (mat[(sdR + 1) % 5][sdC]);
            continue;
        }

        s[i] = mat[ftR][sdC];
        s[i + 1] = mat[sdR][ftC];

    }
    string cip = s;
    transform(cip.begin(), cip.end(), cip.begin(), ::toupper);
    cout << "\n Cipher text is: " << cip;

    for (int i = 0; i < s.length(); i += 2)
    {
        char ft = s[i];
        int ftR = loc[ft].first;
        int ftC = loc[ft].second;

        char sd = s[i + 1];
        int sdR = loc[sd].first;
        int sdC = loc[sd].second;

        if (ftR == sdR)
        {
            s[i] = (mat[ftR][(ftC - 1 + 5) % 5]);
            s[i + 1] = (mat[ftR][(sdC - 1 + 5) % 5]);
            continue;
        }

        if (ftC == sdC)
        {
            s[i] = (mat[(ftR - 1 + 5) % 5][ftC]);
            s[i + 1] = (mat[(sdR - 1 + 5) % 5][sdC]);
            continue;
        }

        s[i] = mat[ftR][sdC];
        s[i + 1] = mat[sdR][ftC];

    }

    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (pos[i] == '*')
            ans += s[i];
    }
    s = ans;
    cout << "\n\n Plain text after decription is : " <<s<<endl;


    return 0;
}