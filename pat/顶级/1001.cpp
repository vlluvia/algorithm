#include <bits/stdc++.h>

#define INF 1<<29
using namespace std;


struct node {
    int c1, c2, cost, status;
};

int n, m;
vector<int> father;
vector<node> data;

bool cmp(node a, node b) {
    return a.status == b.status ? a.cost < b.cost : a.status > b.status;
}
// ** 并查集更快
int findFather(int num) {
    return num == father[num] ? num : father[num] = findFather(father[num]);
}

int main() {
    int c1, c2, cost, status, maxa = 0, fa, fb, count;
    cin >> n >> m;
    vector<int> costs(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> c1 >> c2 >> cost >> status;
        data.push_back({c1, c2, cost, status});
    }
    sort(data.begin(), data.end(), cmp);
    father.resize(n + 1);
    // 将当前节点位置删除，是否会生成多个集合
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            father[j] = j;
        }
        count = n - 1;
        for (auto &no:data) {
            if (no.c1 != i && no.c2 != i) {
                fa = findFather(no.c1);
                fb = findFather(no.c2);
                if (fa != fb) {
                    father[fa] = fb;
                    count--;
                    costs[i] += !no.status * no.cost;
                }
            }
        }
        // 删除后含有多个集合，表明攻占此城市代价很大
        if (count > 1)
            costs[i] = INF;
        maxa = max(costs[i], maxa);
    }

    if (maxa == 0) {
        cout << 0 << endl;
    } else {
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (costs[i] == maxa) {
                cout << (flag ? " " : "") << i;
                flag = 1;
            }
        }
    }
    return 0;
}
