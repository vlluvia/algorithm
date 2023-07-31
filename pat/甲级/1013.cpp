#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

int n, m, k;
int data[1005][1005];
int concern[1005];
int visit[1005];
int res[1005];

void dfs(int x) {
    visit[x] = 1;
    for (int i = 1; i <= n; ++i) {
        if (visit[i] == 0 && data[x][i] == 1)
            dfs(i);
    }
}

void pat1013() {
    memset(data, INF, sizeof(data));
    memset(visit, 0, sizeof(visit));
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        data[a][b] = 1;
        data[b][a] = 1;
    }
    for (int j = 0; j < k; ++j) {
        cin >> concern[j];
    }

    for (int i = 0; i < k; ++i) {
        int sum=0;
        visit[concern[i]] = 1;
        for (int l = 1; l <= n; ++l) {
            if (visit[l] == 0) {
                dfs(l);
                sum++;
            }
        }
        cout << sum-1<<endl;
        memset(visit, INF, sizeof(visit));
    }
}


//int main() {
//    pat1013();
//    return 0;
//}