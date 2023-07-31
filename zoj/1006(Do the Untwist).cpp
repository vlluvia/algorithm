#include <bits/stdc++.h>

using namespace std;

int ca, cb, n;

int main() {  int ciphercode[1000],plaincode[1000];
    string ciphertext;
    char plaintext[1000];
    int k;
    while(cin>>k)
    {
        if(k==0)
        {
            break;
        }
        cin>>ciphertext;
        for(int i=0;i<ciphertext.size();i++)
        {
            if(ciphertext[i]=='.')
            {
                ciphercode[i]=27;
            }
            else if(ciphertext[i]=='_')
            {
                ciphercode[i]=0;
            }
            else
            {
                ciphercode[i]=ciphertext[i]-'a'+1;
            }
        }
        for(int i=0;i<ciphertext.size();i++)
        {
            plaincode[(i*k)%ciphertext.size()] = ((ciphercode[i]+i)%28);
        }
        for(int i=0;i<ciphertext.size();i++)
        {
            if(plaincode[i]==27)
            {
                plaintext[i]='.';
            }
            else if(plaincode[i]==0)
            {
                plaintext[i]='_';
            }
            else
            {
                plaintext[i] = plaincode[i]+'a'-1;
            }

        }
        for(int i=0;i<ciphertext.size();i++)
        {
            cout<<plaintext[i];
        }
        cout<<endl;

    }
    return 0;
}
