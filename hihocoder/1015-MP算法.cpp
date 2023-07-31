#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void prefix(string pattern, int pre[], int n) {
    int j = 0;
    int i = 1;
    while (i <= n) {
        if (pattern[i] == pattern[j]) {
            pre[++i] = ++j;
        } else {
            if (j > 1) {
                j = pre[j];
            } else {
                pre[++i] = j;
            }
        }
    }
}

int kmp(string a, string b){
    int pre[100];
    int n = b.size();
    int i = 0,j =0;
    pre[0] = -1;
    pre[1] = 0;

    prefix(b, pre, n);
    int sum = 0;
    while(i < a.size()){
        if( j == n-1 && a[i] == b[j]){
            sum++;
            j = pre[j];
        }

        if(a[i] == b[j]){
            i++;j++;
        }else{
            j = pre[j];
            if(j == -1){
                i++;j++;
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str1, str2;
        cin>>str1>>str2;
        cout<<kmp(str2,str1)<<endl;
    }
    return 0;
}
