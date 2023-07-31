#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;


void pat1019() {
    long long n, b;
    cin >> n >> b;
    int s[100000];
    int i = 0;
    do {
        s[i] = n % b;
        n /= b;
        ++i;
    } while (n != 0);

    int sum = 0;
    for (int j = 0; j < i / 2; ++j) {
        if (s[j] == s[i - j - 1]) {
            sum++;
        }
    }
    if (sum == i / 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << s[i-1];
    for (int l = i-2; l >=0; --l) {
        cout << " " << s[l];
    }
}


//int main() {
//    pat1019();
//    return 0;
//}