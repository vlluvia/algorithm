#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, k;
map<string, int> hashtable;
int happiness[205];
int data[205][205];
int visit[205];
int dist[205];
vector<int> pre[205];
vector<int> path, tempPath;
int ave_happiness = -1;
int all_sum = 0;
int min_sum = 0;


void dijkstra(int begin);

void dfs(int v);

void pat1087() {
    memset(visit, 0, sizeof(visit));
    fill(data[0], data[0] + 205 * 205, INF);
    string begin;
    int index = 0;
    cin >> n >> k >> begin;
    hashtable[begin] = index;
    happiness[index++] = 0;
    for (int i = 1; i < n; ++i) {
        string city;
        int h;
        cin >> city >> h;
        hashtable[city] = i;
        happiness[i] = h;
    }
    for (int i = 0; i < k; ++i) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        data[hashtable[a]][hashtable[b]] = c;
        data[hashtable[b]][hashtable[a]] = c;
    }

    dijkstra(0);

    dfs(hashtable["ROM"]);
    printf("%d %d %d %d\n", path.size(), dist[hashtable["ROM"]], all_sum, ave_happiness);
    for (int i = path.size() - 1; i >= 0; --i) {
        for (auto &it: hashtable) {
            if (it.second == path[i]) {
                printf("%s", it.first.c_str());
            }
        }
        if (i != 0)
            printf("->");
        else
            printf("\n");
    }
}

void dijkstra(int begin) {
    fill(dist, dist + 205, INF);
    dist[begin] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < n; ++j) {
            if (visit[j] == 0 && min > dist[j]) {
                u = j;
                min = dist[j];
            }
        }
        if (u == -1) return;
        visit[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (visit[v] == 0 && data[u][v] != INF) {
                if (data[u][v] + dist[u] < dist[v]) {
                    dist[v] = data[u][v] + dist[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (data[u][v] + dist[u] == dist[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    if (v == 0) {
        tempPath.push_back(v);
        int sum = 0;
        for (int i = tempPath.size() - 1; i >= 0; --i) {
            sum += happiness[tempPath[i]];
        }
        int x = sum / (tempPath.size() - 1);
        if (x > ave_happiness) {
            path = tempPath;
            ave_happiness = x;
            all_sum = sum;
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

//int main() {
//    pat1087();
//    return 0;
//}