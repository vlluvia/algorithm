#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, p;
long long data[100005];

void pat1085() {

    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &data[i]);
    }
    sort(data, data + n);
    long long max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + max; j < n; ++j) {
            if (data[i] * p < data[j]) {
                break;
            }
            if (max < j - i + 1) {
                max = j - i + 1;
            }
        }
    }
    cout << max << endl;
}


int main() {
    pat1085();
    return 0;
}