#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n;
int data[100005];

void pat1113() {
    cin >> n;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];

    }
    sort(data, data + n);
    for (int i = 0; i < n; ++i) {
        if (i < n / 2) {
            sum1 += data[i];
        } else {
            sum2 += data[i];
        }
    }
    if (n % 2 == 0) {
        cout << "0" << " " << abs(sum2 - sum1) << endl;
    } else {
        cout << "1" << " " << abs(sum2 - sum1) << endl;
    }
}

int main() {
    pat1113();
    return 0;
}