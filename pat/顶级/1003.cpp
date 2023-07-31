#include <bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct edge {
    int to, cap, reverse_from;
};

vector<edge> data[1005];
bool vis[1005];

void add_edge(int from, int to, int cap) {
    data[from].push_back({to, cap, int(data[to].size())});
    data[to].push_back({from, 0, int(data[from].size() - 1)});
}

int dfs(int b, int e, int f) {
    if (b == e) return f;
    vis[b] = true;
    for (auto &item: data[b]) {
        if (!vis[item.to] && item.cap > 0) {
            int d = dfs(item.to, e, min(f, item.cap));
            if (d > 0) {
                item.cap -= d;
                data[item.to][item.reverse_from].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int b, int e) {
    int flow = 0;
    while (true) {
        fill(vis, vis + 1005, 0);
        int d = dfs(b, e, INF);
        if (d == 0) return flow;
        flow += d;
    }
}

int main() {
    int n, count = 2;
    map<string, int> mp;
    string begin_str, end_str;
    cin >> begin_str >> end_str >> n;
    mp[begin_str] = 1;
    mp[end_str] = 2;
    for (int i = 0; i < n; ++i) {
        int cap, from, to;
        cin >> begin_str >> end_str >> cap;
        if (mp[begin_str]) from = mp[begin_str];
        else mp[begin_str] = from = ++count;

        if (mp[end_str]) to = mp[end_str];
        else mp[end_str] = to = ++count;

        add_edge(from, to, cap);
    }

    cout << max_flow(1, 2);
    return 0;
}


