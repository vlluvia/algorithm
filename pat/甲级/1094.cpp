#include <bits/stdc++.h>
using namespace std;

int N, M;
int vis[110], num[110];
vector<int> v[110];
int depth = -1;

void dfs(int root, int step) {
    if(v[root].size() == 0) {
        depth = max(depth, step);
    }

    vis[root] = 1;
    num[step] ++;
    for(int i = 0; i < v[root].size(); i ++) {
        if(vis[v[root][i]] == 0) {
            dfs(v[root][i], step + 1);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < M; i ++) {
        int id, K, x;
        scanf("%d%d", &id, &K);
        for(int k = 0; k < K; k ++) {
            scanf("%d", &x);
            v[id].push_back(x);
        }
    }

    dfs(1, 1);
    int temp, ans = INT_MIN;
    for(int i = 0; i <= depth; i ++) {
        if(num[i] > ans) {
            ans = num[i];
            temp = i;
        }
    }
    /*for(int i = 1; i <= depth; i ++)
        printf("%d ", num[i]);*/
    printf("%d %d\n", ans, temp);
    //printf("%d\n", depth);
    return 0;
}