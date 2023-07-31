#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

const int maxn = 100005;
int prime[maxn], pNum = 0;

bool is_prime(int n) {
    if (n == 1) return false;
    int sqr = sqrt(n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void pat1078() {
    int msize, n;
    int flag[maxn];
    memset(flag, 0, sizeof(maxn));
    cin >> msize >> n;
    if (!is_prime(msize)) {
        for (int i = msize + 1; i < maxn; ++i) {
            if (is_prime(i)) {
                msize = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        int temp = -1;
        bool f = false;
        for (int j = 0; j <= msize; ++j) {
            temp = (num + j * j) % msize;
            if (flag[temp] == 0) {
                flag[temp] = 1;
                f = true;
                break;
            }
        }
        if (f) {
            printf("%d", temp);
        } else {
            printf("-");
        }

        if (i != n - 1) {
            printf(" ");
        }
    }

}


//int main() {
//    pat1078();
//    return 0;
//}