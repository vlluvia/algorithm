#include <bits/stdc++.h>

using namespace std;


int main() {
    int p,ind = 1;
    int temp[3];
    char enigma[3][28];
    while(cin>>p && p!=0){
        for(int i=0;i< 3;i++){
            string str;
            cin>>str;
            for(int j=0;j<str.size();j++){
                enigma[i][str[j] - 'A'] = j + 'A' - str[j];
            }
        }

        if(ind > 1) cout<<endl;
        printf("Enigma %d:\n",ind);
        ind++;

        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            for(int j=0; j< str.size(); j++){
                temp[0] = j % p;
                temp[1] = (j / p) % p;
                temp[2] = (j / (p * p)) % p;
                int t = str[j] - 'A';
                for(int k=2;k>=0;k--)
                {
                    t+=enigma[k][(t+p-temp[k])%p];
                    t=(t+p)%p;
                }
                printf("%c",t+'a');
            }
            printf("\n");
        }
    }
    return 0;
}