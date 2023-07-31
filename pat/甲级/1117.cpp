#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;


void pat1117() {
    int n;
    int data[100005];
    int sum = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    sort(data, data + n);
    int i;
    int res = 1;
    for (i = n-1; i >=0 ;--i) {
        if (data[i] <= res)
            break;
        res++;
    }
    cout << (res-1);
}

int main() {
    pat1117();
    return 0;
}