#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

const int maxn = 50;
struct node {
    int data;
    node *lchild;
    node *rchild;
};

void post_dfs(node *root);

int pre[maxn], in[maxn], post[maxn];
int n;

node *create(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }

    node *root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == pre[preL])
            break;

    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void pat1086() {
    cin >> n;
    stack<int> temp;
    int pre_index = 0, in_index = 0;
    for (int i = 0; i < 2 * n; ++i) {
        string str;
        cin >> str;
        if (str == "Push") {
            int num;
            cin >> num;
            temp.push(num);
            pre[pre_index++] = num;
        } else {
            in[in_index++] = temp.top();
            temp.pop();
        }
    }
    node *root = create(0, n - 1, 0, n - 1);
    post_dfs(root);
    for (int i = 0; i < n; ++i) {
        cout << post[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
}

int post_index = 0;

void post_dfs(node *root) {
    if (root == NULL) return;
    post_dfs(root->lchild);
    post_dfs(root->rchild);
    post[post_index++] = root->data;

}


int main() {
    pat1086();
    return 0;
}