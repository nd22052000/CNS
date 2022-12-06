// Implementation of Ceasor Cypher
#include <iostream>
using namespace std;

/*string encrypt(string plainText, int pos)
{

   int n = plainText.size();
   for (int i = 0; i < n; i++)
   {
      if (plainText[i] == 32)
         continue;
      if (plainText[i] > 96 && plainText[i] <= 122)
         plainText[i] -= 32;
      plainText[i] = (plainText[i] - 'A' + pos) % 26 + 'A';
   }
   cout << "\nCipher Text :" << plainText << endl;
   return plainText;
}

void decrypt(string cypherText, int pos)
{
   int n = cypherText.size();
   for (int i = 0; i < n; i++)
   {
      if (cypherText[i] == 32)
         continue;
      cypherText[i] = (cypherText[i] - 'A' - pos + 26) % 26 + 'A';
   }
   cout << "\nPlain Text :" << cypherText << endl;
}

int main()
{
   int pos;
   // freopen("input.txt", "r", stdin);
   // freopen("caesarcipher.txt", "w", stdout);

   string plain_text;
   cout << "Enter plain text" << endl;
   fflush(stdin);
   cin >> plain_text;

   // cout<<"Plain text:"<<plain_text<<endl;
   cin >> pos;

   string cypher_text = encrypt(plain_text, pos);
   cout << "Encrypted Message is " << cypher_text << endl;
   decrypt(cypher_text, pos);
}
*/

string encrypt(string str,int key)
{
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        if(str[i]==32)
            continue;
        if(str[i]>=97 && str[i]<=122)
            str[i]-=32;
        str[i]=(str[i]-'A'+key)%26+'A';

    }
    return str;
}
void decrypt(string cipher,int key)
{
    for(int i=0;i<cipher.size();i++)
    {
        if(cipher[i]==32)
            continue;
        if(cipher[i]>=97 && cipher[i]<=122)
            cipher[i]-=32;
        cipher[i]=(cipher[i]-'A'-key+26)%26 +'A';
    }
    cout<<"Decrypted plain text is "<<cipher<<endl;
}
int main()
{

    int pos;
    string text;
    cout<<"Enter plain text"<<endl;
    cin>>text;
    cout<<"Enter key"<<endl;
    cin>>pos;
    string cipher=encrypt(text,pos);
    cout<<"Cipher text is "<<cipher<<endl;
    decrypt(cipher,pos);
}
