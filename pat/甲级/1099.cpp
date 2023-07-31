#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    int data, left, right;
};
int n;
node tree[105];
int data[105];
int num = 0;

void preorder(int root) {
    if (root == -1) return;
    preorder(tree[root].left);
    tree[root].data = data[num++];
    preorder(tree[root].right);
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    num = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << tree[t].data;
        num++;
        if (num < n) cout << " ";
        if (tree[t].left != -1) q.push(tree[t].left);
        if (tree[t].right != -1) q.push(tree[t].right);
    }
}

void pat1099() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        tree[i].left = l;
        tree[i].right = r;
    }
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    sort(data, data + n);
    preorder(0);
    bfs(0);

}

int main() {
    pat1099();
    return 0;
}