#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

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

struct factor {
    int x, cnt;
};

void pat1059() {
    Find_Prime();
    int n, num = 0;
    factor fac[10];
    cin >> n;
    if (n == 1) cout << "1=1";
    else {
        cout << n << "=";
        int sqr = (int) sqrt(n);
        for (int i = 0; i < pNum && prime[i] <= sqr; ++i) {
            if (n % prime[i] == 0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0) {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) break;
        }
        if (n != 1) {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }

        for (int i = 0; i < num; ++i) {
            if (i > 0) printf("*");
            cout << fac[i].x;
            if (fac[i].cnt > 1) {
                cout << "^" << fac[i].cnt;
            }
        }
    }

}


//int main() {
//    pat1059();
//    return 0;
//}