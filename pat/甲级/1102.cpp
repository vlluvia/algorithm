#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    int data, l, r;
};
int n;
node data[12];
int beg = 0;
int temp[13] = {0};
int num = 0;

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << data[t].data;
        num++;
        if (num < n) cout << " ";
        if (data[t].r != -1) q.push(data[t].r);
        if (data[t].l != -1) q.push(data[t].l);
    }

}
int res[12];
int k=0;
void dfs(int root) {
    if (root == -1) return;
    dfs(data[root].r);
    res[k++] = root;
    dfs(data[root].l);
}

void pat1102() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        node n;
        char l, r;
        cin >> l >> r;
        if (l != '-') {
            n.l = l - '0';
            temp[n.l] = 1;
        } else
            n.l = -1;
        if (r != '-') {
            n.r = r - '0';
            temp[n.r] = 1;
        } else
            n.r = -1;
        n.data = i;
        data[i] = n;
    }

    for (int i = 0; i < n; ++i) {
        if (temp[i] == 0) {
            beg = i;
            break;
        }
    }

    bfs(beg);
    cout<<endl;
    dfs(beg);
    for (int i = 0; i < k; ++i) {
        cout<<res[i];
        if(i!=k-1)
            cout<<" ";
    }
}

int main() {
    pat1102();
    return 0;
}