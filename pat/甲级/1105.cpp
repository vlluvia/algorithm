#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

bool cmp(const int &a, const int &b) {
    return a > b;
}

void pat1105() {
    int N, m, n;
    int data[10005];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> data[i];
    }
    int a = sqrt(N);
    for (int i = a; i >= 1; --i) {
        if (N % i == 0) {
            n = i;
            m = N / i;
            break;
        }
    }
    sort(data, data + N, cmp);
    int ans[m][n];
    memset(ans, 0, sizeof(ans));

    int up = 0, down = m - 1, left = 0, right = n - 1, cnt = 0;
    while(true) {
        for(int j = left; j <= right; j ++) ans[up][j] = data[cnt ++];
        if(++ up > down) break;
        for(int i = up; i <= down; i ++) ans[i][right] = data[cnt ++];
        if(-- right < left) break;
        for(int j = right; j >= left; j --) ans[down][j] = data[cnt ++];
        if(-- down < up) break;
        for(int i = down; i >= up; i --) ans[i][left] = data[cnt ++];
        if(++ left > right) break;
    }

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            printf("%d", ans[i][j]);
            printf("%s", j != n - 1 ? " " : "\n");
        }
    }
}

int main() {
    pat1105();
    return 0;
}