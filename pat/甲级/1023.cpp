#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

string num;
int num_n[10];
int num_n2[10];

string dou(string num);

void pat1023() {
    memset(num_n, 0, sizeof(num_n));
    memset(num_n2, 0, sizeof(num_n2));
    cin >> num;
    for (int i = 0; i < num.size(); ++i) {
        int t;
        stringstream ss;
        ss<<num[i];
        ss>>t;
        num_n[t]++;
    }
    string num2 = dou(num);
    for (int i = 0; i < num2.size(); ++i) {
        int t;
        stringstream ss;
        ss<<num2[i];
        ss>>t;
        num_n2[t]++;
    }
    bool flag = true;
    for (int i = 0; i < 10; ++i) {
        if (num_n[i] != num_n2[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << num2 << endl;
}

string dou(string num) {
    string res;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; --i) {
        int t;
        stringstream ss;
        ss << num[i];
        ss >> t;
        t = t * 2 + carry;
        carry = t / 10;
        t = t % 10;
        res += to_string(t);
    }
    if (carry != 0) {
        res += to_string(carry);
    }
    reverse(res.begin(), res.end());
    return res;
}


//int main() {
//    pat1023();
//    return 0;
//}