//
// Created by Administrator on 2019/8/16.
//

// 1. 素数集           题目 1059
#include <math.h>

const int maxn = 100010;
int prime[maxn], pNum = 0;

bool is_prime(int n) {  //判断是否为素数
    if (n == 1) return false;
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void Find_Prime() {     //获取1到maxn的素数集合
    for (int i = 1; i < maxn; ++i) {
        if (is_prime(i)) {
            prime[pNum++] = i;
        }
    }
}


// 2.最大公约数
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}



// 3.大数相加
string add(string n1, string n2) {
    int carry = 0;
    string res;
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    for (int i = 0; i < n1.size() || i < n2.size(); ++i) {
        int t, l;
        stringstream ss1, ss2;
        ss1 << n1[i];
        ss2 << n2[i];
        ss1 >> t;
        ss2 >> l;
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


// 4.任意进制转十进制
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


// 5. 时间比大小
int compare(const char *time1, const char *time2) {
    int hour1, min1, sec1;
    int hour2, min2, sec2;
    sscanf(time1, "%d:%d:%d", &hour1, &min1, &sec1);
    sscanf(time2, "%d:%d:%d", &hour2, &min2, &sec2);
    int tm1, tm2;
    tm1 = hour1 * 3600 + min1 * 60 + sec1;
    tm2 = hour2 * 3600 + min2 * 60 + sec2;
    if (tm1 != tm2) return (tm1 > tm2) ? 1 : 0;
    return 2;
}

// 6.十进制转其他进制
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


// 7.最长不下降序列
vod t(){
    int k, num;
    vector<int> v, vec;
    cin >> k;
    for (int j = 0; j < k; ++j) {
        cin >> num;
        v.push_back(num);
    }

    for (int l = 0; l < k; ++l) {
        if (l == 0) vec.push_back(v[0]);
        else {
            if (v[l] > vec[vec.size() - 1]) vec.push_back(v[l]);
            else *upper_bound(vec.begin(), vec.end(), v[l]) = v[l];
        }
    }
    cout << vec.size() << endl;
}


