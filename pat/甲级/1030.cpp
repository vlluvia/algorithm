#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

const int MAXV = 510;

int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
vector<int> tempPath, path;

void dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && G[u][j] != INF) {
                if (d[u] + G[u][j] < d[j]) {
                    d[j] = d[u] + G[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                } else if (d[u] + G[u][j] == d[j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    if (v == st) {
        tempPath.push_back(v);
        int tempCost = 0;
        for (int i = tempPath.size() - 1; i > 0; --i) {
            int id = tempPath[i], idNext = tempPath[i - 1];
            tempCost += cost[id][idNext];
        }
        if (tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

void pat1030() {
    cin >> n >> m >> st >> ed;
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(cost[0], cost[0] + MAXV * MAXV, INF);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        cin >> G[u][v] >> cost[u][v];
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    dijkstra(st);
    dfs(ed);
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << d[ed] << " " << minCost;
}


//int main() {
//    pat1030();
//    return 0;
//}