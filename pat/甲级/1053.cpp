#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct node {
    int weight;
    vector<int> child;
} nodes[100010];

bool cmp(int a, int b) {
    return nodes[a].weight > nodes[b].weight;
}

int n, m, S;
int path[110];

void dfs(int index, int numNode, int sum) {
    if (sum > S) return;
    if (sum == S) {
        if (nodes[index].child.size() != 0) return;
        for (int i = 0; i < numNode; ++i) {
            printf("%d", nodes[path[i]].weight);
            if (i < numNode - 1)printf(" ");
            else printf("\n");
        }
        return;
    }
    for (int i = 0; i < nodes[index].child.size(); ++i) {
        int child = nodes[index].child[i];
        path[numNode] = child;
        dfs(child, numNode + 1, sum + nodes[child].weight);
    }
}

void pat1053() {
    cin >> n >> m >> S;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].weight;
    }
    int id, k, child;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            cin >> child;
            nodes[id].child.push_back(child);
        }
        sort(nodes[id].child.begin(), nodes[id].child.end(),cmp);
    }
    path[0] = 0;
    dfs(0, 1, nodes[0].weight);
}


//int main() {
//    pat1053();
//    return 0;
//}