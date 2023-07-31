#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

string n;
int k;

string add(string n1, string n2);

void pat1024() {
    cin >> n >> k;
    string n1 = n;
    int sum = 1;
    for (int i = 0; i < k; ++i) {
        string n2 = n1;
        reverse(n2.begin(), n2.end());
        string res = add(n1, n2);
        if (n1 == n2) {
            break;
        } else {
            ++sum;
            n1 = res;
        }
    }

    cout << n1 << endl;
    cout << sum - 1 << endl;
}

string add(string n1, string n2) {
    int carry = 0;
    string res;
    for (int i = 0; i < n1.size() || i < n2.size(); ++i) {
        int t = 0, l = 0;
        if (i < n1.size())
            t = n1[i] - '0';
        if (i < n2.size())
            l = n2[i] - '0';

        int temp = t + l + carry;
        res += to_string(temp % 10);
        carry = temp / 10;
    }
    if (carry != 0) {
        res += to_string(carry);
    }
    reverse(res.begin(), res.end());
    return res;
}


//int main() {
//    pat1024();
//    return 0;
//}