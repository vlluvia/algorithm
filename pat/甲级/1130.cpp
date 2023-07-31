#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

struct node {
    string data;
    int lchild, rchild;
};

int n, beg;
node data[30];
int vis[30] = {0};

void dfs(int root, int depth) {

    if (!(depth == 0 || (data[root].lchild == -1 && data[root].rchild == -1)))//零层及叶节点不加括号
        printf("(");
    if (data[root].lchild != -1)
        dfs(data[root].lchild,depth+1);
    cout << data[root].data;
    if (data[root].rchild != -1)
        dfs(data[root].rchild,depth+1);
    if (!(depth == 0 || (data[root].lchild == -1 && data[root].rchild == -1)))//零层及叶节点不加括号
        printf(")");
}

void pat1130() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string d;
        int a, b;
        cin >> d >> a >> b;
        if (a != -1) vis[a]++;
        if (b != -1) vis[b]++;
        node t = {d, a, b};
        data[i] = t;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            beg = i;
            break;
        }
    }
    dfs(beg,0);
}

int main() {
    pat1130();
    return 0;
}