#include <bits/stdc++.h>
#define MAXN 1048577
#define INF 1<<29
using namespace std;
string s;
int num, n, m, rk[MAXN], sa[MAXN], b[MAXN], tp[MAXN], height[MAXN];

void Qsort() {//基数排序
    for (int i = 0; i <= m; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) b[rk[i]]++;
    for (int i = 1; i <= m; i++) b[i] += b[i - 1];
    for (int i = n; i >= 1; i--) sa[b[rk[tp[i]]]--] = tp[i];
}

void get_height() {//求排名为i的后缀与排名为i−1的后缀的最长公共前缀
    int j, k = 0;
    for (int i = 1; i <= n; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}

void suffix_sort() {//后缀排序
    m = 150;
    for (int i = 1; i <= n; i++) {
        rk[i] = s[i] + 1;
        tp[i] = i;
    }
    Qsort();
    for (int k = 1, p = 0; p < n; m = p, k *= 2) {
        //k:当前倍增的长度，k=len表示已经求出了长度为len的后缀的排名，现在要更新长度为2*len的后缀的排名
        //p表示不同的后缀的个数，很显然原字符串的后缀都是不同的，因此p=n时可以退出循环
        p = 0;//p表示一个计数器
        for (int i = 1; i <= k; i++) tp[++p] = n - k + i;
        for (int i = 1; i <= n; i++) if (sa[i] > k) tp[++p] = sa[i] - k; //这两句是后缀数组的核心部分
        Qsort();//此时我们已经更新出了第二关键字，利用上一轮的rk更新本轮的sa
        swap(tp, rk);//这里原本tp已经没有用了
        rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rk[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + k] == tp[sa[i] + k]) ? p : ++p;
        }
        //因为sa[i]已经排好序了，所以可以按排名枚举，生成下一次的第一关键字
        //这里当两个后缀上一轮排名相同时本轮也相同
    }
}

int main() {
    cin >> num;
    getchar();
    getline(cin, s);
    n = s.length();
    s = '0' + s;
    suffix_sort();//后缀排序
    get_height();//求排名为i的后缀与排名为i−1的后缀的最长公共前缀
    int p = sa[1], pm = sa[1], cnt = 1, mcnt = 1;
    for (int i = 2; i <= n; i++) {
        if (height[i] >= num) cnt++;
        else {
            if (cnt > mcnt || (cnt == mcnt && s[p] < s[pm])) {
                mcnt = cnt;
                pm = p;
            }
            cnt = 1;
            p = sa[i];
        }
    }
    if (cnt > mcnt || (cnt == mcnt && s[p] < s[pm])) {
        mcnt = cnt;
        pm = p;
    }
    cout << s.substr(pm, num) << " " << mcnt;
    return 0;
}