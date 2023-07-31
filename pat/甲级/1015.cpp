#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

long long n, d;

long long toNum(char c)        //转化为阿拉伯数字
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'a' + 10;
}

long long toDecimal(string str, long long radix)       //转到十进制
{
    long long num = 0;
    long long ant = 1;
    for (int i = str.size() - 1; i >= 0; i--, ant *= radix) {
        num += ant * toNum(str[i]);
        if (num < 0 || ant < 0)
            return -1;
    }
    return num;
}

string decimalTother(long long n, int radix) {
    string ans;
    do {
        long long t = n % radix;
        if (t >= 0 && t <= 9) ans += t + '0';
        else ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}

long long ntod(long long num, int radix) {
    string s = decimalTother(num, radix);
    reverse(s.begin(), s.end());
    return toDecimal(s, radix);
}

bool prime(long long num) {
    int i;
    for (i = 2; i < num; i++)
        if (num % i == 0)break;
    return i == num;
}

void pat1015() {
    cin >> n;
    while (n > 0) {
        cin >> d;
        long long nd;
        nd = ntod(n, d);
        if (prime(n) &&  prime(nd)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cin >> n;
    }
}


//int main() {
//    pat1015();
//    return 0;
//}