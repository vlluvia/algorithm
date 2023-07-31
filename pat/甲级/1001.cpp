#include<bits/stdc++.h>

#define INF 1<<30
using namespace std;

void pat1001() {
    long a, b;
    cin >> a >> b;
    long c = a + b;
    if (c > -1000 && c < 1000) {
        cout << c << endl;
    } else if (c > -1000000 && c < 1000000) {
        printf("%d,%03d", c / 1000, abs(c % 1000));
    } else {
        printf("%d,%03d,%03d", c / 1000000, abs(c % 1000000 / 1000), abs(c % 1000));
    }
}

int main() {
    pat1001();
    return 0;
}
