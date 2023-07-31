#include<bits/stdc++.h>

using namespace std;

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
        if (num < 0 || ant < 0)     //需要判断这个，也许进制太大了呢
            return -1;
    }
    return num;
}

void pat1010() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) {
        swap(n1, n2);
    }
    unsigned long long a = toDecimal(n1, radix);
    unsigned long long r = a;
    long long mid = 0;
    long long l = 2;
    for (char i : n2) {       //算出最低的进制数
        l = max(l, toNum(i) + 1);
    }
    while (r >= l) {
        mid = (l + r) >> 1;
        unsigned long long b = toDecimal(n2, mid);
        if (b >= a)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (toDecimal(n2, l) == a) {
        cout << l;
    } else {
        cout << "Impossible";
    }
}


//int main() {
//    pat1010();
//    return 0;
//}