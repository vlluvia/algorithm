#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

struct tree {
    int data;
    tree *right, *left;
};

int n;
int postorder[35], inorder[35], visit[35];
tree *res;

tree *create(int i1, int i2, int p1, int p2) {
    if (i1 > i2 || p1 > p2)return NULL;
    tree *root = new tree();
    root->data = postorder[p2];
    int k;
    for (int i = i1; i <= i2; i++) {
        if (inorder[i] == root->data) {
            k = i;
            break;
        }
    }
    root->left = create(i1, k - 1, p1, p1 + k - 1 - i1);
    root->right = create(k + 1, i2, p2 - 1 - (i2 - k - 1), p2 - 1);
    return root;
}

void bfs(tree *root, int depth) {
    vector<tree *> v;
    v.push_back(root);
    while (!v.empty()) {
        if (depth % 2 == 0) {
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i]->data;
                if (i != v.size() - 1) {
                    cout << " ";
                }
            }
        } else {
            for (int i = v.size() - 1; i >= 0; --i) {
                cout << v[i]->data;
                if (i != 0) {
                    cout << " ";
                }
            }
        }
        depth++;
        vector<tree *> temp;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]->left != nullptr) {
                temp.push_back(v[i]->left);
            }
            if (v[i]->right != nullptr) {
                temp.push_back(v[i]->right);
            }
        }
        v = temp;
        if (!temp.empty()) {
            cout << " ";
        }
    }
}

void pat1127() {
    memset(visit, 0, sizeof(visit));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    res = create(0, n - 1, 0, n - 1);
    bfs(res, 1);
}

int main() {
    pat1127();
    return 0;
}