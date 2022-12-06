#include<bits/stdc++.h>
using namespace std;

int main()
{
    string plainText;
    int key;

    cout<<"\n Enter plain text : ";
    getline(cin,plainText);

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

    int n = plainText.size();

    cout<<"\n Enter key : ";
    cin>>key;

    vector<vector<char>> matrix(key);

    int row = 0;
    int flg = 1;
    for(int i=0;i<plainText.size();i++)
    {
        matrix[row].push_back(plainText[i]);
        row += flg;
        if(row == 0)
        flg = 1;

        if(row==key-1)
        flg = -1;
    }

    string cipherText;
    for(int i=0;i<key;i++)
	{
		for (int j=0;j<matrix[i].size();j++)
		cipherText += matrix[i][j];
	}

	cout<<"\n Cipher text is : " << cipherText;

    // Decryption

    vector<vector<int>> matd(key);
	row = 0;
	flg = 1;
	for (int i = 1; i <= n; i++)
	{
		matd[row].push_back(i);
		row += flg;
		if (row == (key-1))
		flg = -1;
		if (row == 0)
		flg = 1;
	}

	vector<int> dd;
	for (int i=0;i<key;i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		dd.push_back(matd[i][j]);
	}

	cout << endl;

	map<int, char> m;
	for (int i = 0; i < n; i++)
		m[dd[i]] = cipherText[i];

	string plain = "";
	for (int i=1;i<=n;i++)
		plain += m[i];

	cout << "\n Plain text after decription is : " << plain<<endl;
    
    return 0;
}
