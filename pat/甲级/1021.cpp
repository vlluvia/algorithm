#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

const int maxn = 1e4;
int n;
struct Node {
    int value;
    int next;
} edge[maxn * 2 + 5];
int father[maxn + 5];
int head[maxn + 5];
int vis[maxn + 5];
int num[maxn + 5];
int tag[maxn + 5];
int tot, cnt;

void add(int x, int y) {
    edge[tot].value = y;
    edge[tot].next = head[x];
    head[x] = tot++;
}

int find(int x) {
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}

void dfs(int root, int deep) {
    vis[root] = 1;
    int tag = 0;
    for (int i = head[root]; i != -1; i = edge[i].next) {
        int y = edge[i].value;
        if (!vis[y]) {
            tag = 1;
            dfs(y, deep + 1);
        }
    }
    if (!tag)
        num[cnt] = max(num[cnt], deep);
}

void pat1021() {
    scanf("%d", &n);
    int x, y;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
        father[i] = i;
    tot = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
            father[fy] = fx;
        add(x, y);
        add(y, x);
    }

    memset(tag, 0, sizeof(tag));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        find(i);
        tag[father[i]] = 1;
//        cout << "i:" << i << ";father[i]:" << father[i] << endl;
    }
    for (int i = 1; i <= n; i++)
        if (tag[i])
            res++;
    cout << "\nhead: ";
    for (int i = 0; i < tot; ++i) {
        cout << head[i] << " ";
    }
    cout << "\nedge: ";
    for (int i = 0; i < tot; ++i) {
        cout << "(" << edge[i].value << "," << edge[i].next << ") ";
    }
    if (res > 1)
        printf("Error: %d components\n", res);
    else {
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            cnt = i;
            dfs(i, 0);
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++)
            ans = max(ans, num[i]);
        for (int i = 1; i <= cnt; i++)
            if (num[i] == ans)
                printf("%d\n", i);
    }
}


//int main() {
//    pat1021();
//    return 0;
//}