#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;


void pat1093() {
    string str;
    cin >> str;
    int left[100010];
    memset(left, 0, sizeof(left));
    for (int i = 0; i < str.size(); ++i) {
        if (i > 0) {
            left[i] = left[i - 1];
        }
        if (str[i] == 'P') {
            left[i]++;
        }
    }
    int res = 0, right_res = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == 'T') {
            right_res++;
        } else if (str[i] == 'A') {
            res = (res + left[i] * right_res) % 1000000007;
        }
    }
    cout << res << endl;
}

//int main() {
//    pat1093();
//    return 0;
//}