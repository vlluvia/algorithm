#include<bits/stdc++.h>

#define INF 1<<30
using namespace std;

int maxMan = 0;
int n, m, c1, c2, fromCity, toCity, fare;
int data[505][505] = {INF};
int man[505], dst[505],num[505];
int vis[505] = {false};
vector<int> patha[505];
vector<int> tempPath, resPath;

void dijkstra() {
    fill(dst, dst + 505, INF);
    fill(vis, vis + 505, 0);
    fill(num, num + 505, 0);
    dst[c1] = 0;
    num[c1] = 1;

    for (int i = 0; i < n; ++i) {
        int k = -1, mina = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dst[j] < mina) {
                mina = dst[j];
                k = j;
            }
        }
        if (k == -1) {
            return;
        }
        vis[k] = 1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && data[k][j] != INF) {
                if (data[k][j] + dst[k] < dst[j]) {
                    dst[j] = data[k][j] + dst[k];
                    patha[j].clear();
                    patha[j].push_back(k);
                    num[j] = num[k];
                } else if (data[k][j] + dst[k] == dst[j]) {
                    patha[j].push_back(k);
                    num[j] += num[k];
                }
            }
        }
    }
}

void dfs(int idx) {
    if (idx == c1) {
        tempPath.push_back(idx);
        int tempMan = 0;
        for (int i = 0; i < tempPath.size(); ++i) {
            tempMan += man[tempPath[i]];
        }
        if (tempMan > maxMan) {
            maxMan = tempMan;
            resPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(idx);
    for (int i = 0; i < patha[idx].size(); ++i) {
        dfs(patha[idx][i]);
    }
    tempPath.pop_back();
}

void pat1003() {
    fill(data[0], data[0] + 505*505, INF);
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i) {
        cin >> man[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> fromCity >> toCity >> fare;
        data[fromCity][toCity] = fare;
        data[toCity][fromCity] = fare;
    }
    dijkstra();
    dfs(c2);

    printf("%d %d", num[c2], maxMan);
}

int main() {
    pat1003();
    return 0;
}
