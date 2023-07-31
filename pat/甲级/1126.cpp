#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n, m;
int data[505][505];
int c[505] = {0};
bool vis[505] = {false};

void dfs(int num) {
    vis[num] = true;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && data[num][i] != INF) {
            dfs(i);
        }
    }
}

void pat1126() {
    fill(data[0], data[0] + 505 * 505, INF);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        data[a][b] = data[b][a] = 1;
        c[a]++;
        c[b]++;
    }
    int countOdd = 0;
    int blocks = 0;
    for (int i = 1; i <= n; ++i) {
        cout << c[i];

        if (i != n) {
            cout << " ";
        }

        if (c[i] % 2 == 1) {
            countOdd++;
        }
        if (!vis[i]) {
            dfs(i);
            blocks++;
        }
    }
    if (blocks == 1 && countOdd == 0) {
        printf("\nEulerian\n");
    } else if (blocks == 1 && countOdd == 2) {
        printf("\nSemi-Eulerian\n");
    } else {
        printf("\nNon-Eulerian\n");
    }
}

int main() {
    pat1126();
    return 0;
}