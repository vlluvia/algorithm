#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

string decimal2other(int num, int radix) {
    string res;
    do {
        long long temp = num % radix;
        if (temp >= 0 && temp <= 9) res += temp + '0';
        else res += temp - 10 + 'A';
        num /= radix;
    } while (num != 0);
    reverse(res.begin(), res.end());
    return res;
}

void pat1027() {
    int a, b, c;
    cin >> a >> b >> c;
    string a1 = decimal2other(a, 13);
    string a2 = decimal2other(b, 13);
    string a3 = decimal2other(c, 13);

    cout << "#";
    if (a1.size() == 1) {
        cout << "0" << a1;
    }else{
        cout << a1;
    }
    if (a2.size() == 1) {
        cout << "0" << a2;
    }else{
        cout << a2;
    }
    if (a3.size() == 1) {
        cout << "0" << a3;
    }else{
        cout << a3;
    }
}


//int main() {
//    pat1027();
//    return 0;
//}