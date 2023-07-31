#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;


struct node {
    int data, height;
    node *lchild, *rchild;
};

int n;

node *newNode(int data) {
    node *Node = new node;
    Node->data = data;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node *root) {
    if (root == NULL) return 0;
    return root->height;
}

int getBalanceFactor(node *root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node *root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild))+1;
}

void search(node *root, int x) {
    if (root == NULL) {
        cout << "search failed\n" << endl;
        return;
    }
    if (x == root->data) {
        cout << root->data << endl;
    } else if (x < root->data) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

void L(node *&root) {
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node *&root) {
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node *&root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data < root->data) {
        insert(root->lchild, data);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                R(root);
            } else if (getBalanceFactor(root->lchild) == -1) {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, data);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {
                L(root);
            } else if (getBalanceFactor(root->rchild) == 1) {
                R(root->rchild);
                L(root);
            }
        }
    }
}

void pat1066() {
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        insert(root, num);
    }
    cout << root->data << endl;
}


//int main() {
//    pat1066();
//    return 0;
//}