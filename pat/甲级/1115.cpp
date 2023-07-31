#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

struct node {
    int data;
    node *left, *right;
};
int n;
node *root = NULL;

node *create(node *root, int data) {
    if (root == NULL) {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
    } else if (root->data >= data) {
        root->left = create(root->left, data);
    } else {
        root->right = create(root->right, data);
    }
    return root;
}
vector<int> num(1000);
int maxdepth = -1;
void dfs(node *root,int depth){
    if(root == NULL) {
        maxdepth = max(depth, maxdepth);
        return ;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

void pat1115() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        root = create(root, t);
    }
    dfs(root,0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth-2], num[maxdepth-1] + num[maxdepth-2]);
}

int main() {
    pat1115();
    return 0;
}