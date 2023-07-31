#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;


void pat1101() {
    int n,k=0;
    int max=0;
    int data[100005];
    int temp[100005];
    int res[100005];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        temp[i] = data[i];
    }
    sort(data, data + n);
    for (int i = 0; i < n; ++i) {
        if (data[i] ==temp[i] && temp[i]>max){
            res[k++] = temp[i];
        }
        if(temp[i]>max){
            max = temp[i];
        }
    }
    cout<<k<<endl;
    for (int i = 0; i < k; ++i) {
        printf("%d", res[i]);
        if(i != k-1){
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    pat1101();
    return 0;
}