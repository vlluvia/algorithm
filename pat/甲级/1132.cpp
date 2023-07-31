#include<bits/stdc++.h>
#include<string>

#define INF 1<<29
using namespace std;

void pat1132() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        int num;
        stringstream ss;
        cin >> str;
        ss << str;
        ss >> num;
        int temp = 1;
        for (int j = 0; j < str.size() / 2; j++) {
            temp *= 10;
        }
        int A = num / temp;
        int B = num % temp;
        if (A != 0 && B != 0 && num % (A * B) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
}

int main() {
    pat1132();
    return 0;
}