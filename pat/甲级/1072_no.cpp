#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n, m, k, ds;
bool visit[1020] = {false};
int dist[1020];
int data[1020][1020];
map<string, int> temp;

void dijkstra(int s) {
    fill(dist, dist + n + m, INF);
    dist[s] = 0;
    for (int i = 0; i < n + m; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < n + m; ++j) {
            if (!visit[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            return;
        visit[u] = true;
        for (int j = 0; j < n + m; ++j) {
            if (!visit[j] && data[u][j] != INF && data[u][j] + dist[u] < dist[j]) {
                dist[j] = data[u][j] + dist[u];
            }
        }
    }
}

void pat1072() {
    fill(data[0], data[0] + 1020 * 1020, INF);
    int index = 0;
    cin >> n >> m >> k >> ds;
    for (int i = 0; i < k; ++i) {
        string p1, p2;
        int dst;
        cin >> p1 >> p2 >> dst;
        int x, y;
        if (temp.find(p1) != temp.end()) {
            x = temp[p1];
        } else {
            temp[p1] = index;
            x = index++;
        }
        if (temp.find(p2) != temp.end()) {
            y = temp[p2];
        } else {
            temp[p2] = index;
            y = index++;
        }
        data[x][y] = dst;
        data[y][x] = dst;
    }
    string s;
    int min_num = -1, min_total = INF;
    for (int i = 1; i <= m; ++i) {
        string str = "G" + to_string(i);
        dijkstra(temp[str]);
        float min = INF;
        int all = 0;
        bool flag = false;
        for (int j = 1; j <= n; ++j) {
            int t = dist[temp[to_string(j)]];
            if (t <= ds) {
                all += t;
                if (t < min) {
                    min = t;
                }
            } else {
                flag = true;
                break;
            }
        }
        if (!flag) {
            if (min_num < min) {
                s = str;
                min_num = min;
                min_total = all;
            } else if (min_num == min && min_total > all) {
                s = str;
                min_total = all;
            }
        }
    }
    if (min_num == -1) {
        cout << "No Solution" << endl;
    } else {
        cout << s << endl;
        printf("%.1f %.1f", min_num * 1.0, min_total * 1.0 / n);
    }

}


//int main() {
//    pat1072();
//    return 0;
//}