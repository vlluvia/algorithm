#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1050() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.size(); ++i) {
        bool flag = true;
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << a[i];
        }
    }
}

//int main() {
//    pat1050();
//    return 0;
//}