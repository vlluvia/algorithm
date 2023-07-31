#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

string add(string a, string b) {
    int carry = 0;
    string c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size() || i < b.size(); ++i) {
        int n1 = a[i] - '0';
        int n2 = b[i] - '0';
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        c += to_string(sum % 10);
    }
    if (carry != 0)
        c += to_string(carry);
    reverse(c.begin(),c.end());
    return c;
}

void pat1136() {
    string str1, str2;
    cin >> str2;
    for (int i = 0; i < 10; ++i) {
        str1 = str2;
        reverse(str2.begin(), str2.end());
//        cout<<str1<<" "<<str2<<endl;
        if (str1 == str2) {
            printf("%s is a palindromic number.\n", str1.c_str());
            return;
        } else {
            string t = add(str1, str2);
            printf("%s + %s = %s\n", str1.c_str(), str2.c_str(), t.c_str());
            str2 = t;
        }
    }
    cout << "Not found in 10 iterations." << endl;
}

int main() {
    pat1136();
    return 0;
}