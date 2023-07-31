#include <bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct node {
    int p, l, d;
};
vector<node> data;
long long cost[10005][1005];

bool cmp(node a, node b) {
    return a.d < b.d;
}

int main() {
    fill(cost[0], cost[0] + 1005 * 1005, 0);
    int n, p, l, d;
    cin >> n;
    data.push_back({0, 0, 0});
    for (int i = 0; i < n; ++i) {
        cin >> p >> l >> d;
        data.push_back({p, l, d});
    }
    sort(data.begin(), data.end(), cmp);
    long long maxa = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < data[i].d; ++j) {
            if (j + data[i].l <= data[i].d) {
                for (int k = 0; k < i ; ++k) {
                    cost[i][j + data[i].l] = max(cost[i][j + data[i].l], cost[k][j] + data[i].p);
                    maxa = max(maxa, cost[i][j + data[i].l]);
                }
            }
        }
    }
    cout<<maxa<<endl;
    return 0;
}
