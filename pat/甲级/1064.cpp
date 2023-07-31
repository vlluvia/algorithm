#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, k = 0;
int pre[1005], mid[1005];

void dfs(int i);

void pat1064() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        pre[i] = num;
    }
    sort(pre, pre + n);
    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << mid[i];
        if (i != n ) {
            cout << " ";
        }
    }
}

void dfs(int i) {
    if (i > n) return;
    int l = 2 * i;
    int r = 2 * i + 1;
    dfs(l);
    mid[i] = pre[k++];
    dfs(r);
}

//int main() {
//    pat1064();
//    return 0;
//}