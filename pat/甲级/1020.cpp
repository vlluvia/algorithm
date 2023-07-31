#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *lchild,*rchild;
};

int n,ind=0;
int postorder[35], inorder[35],preorder[35];
node * res;

node* create(int i1,int i2, int p1, int p2){
    if(i1>i2 || p1>p2) return NULL;
    node *root = new node;
    root->data = postorder[p2];
    int k;
    for(k = i1; k < i2;k++)
        if(root->data == inorder[k])
            break;

    root->lchild = create(i1, k-1, p1, p1+k-i1-1);
    root->rchild = create(k+1, i2, p2+k-i2, p2-1);
    return root;
}

void bfs(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *root = q.front();
        q.pop();
        preorder[ind++] = root->data;

        if(root->lchild !=NULL)
            q.push(root->lchild);
        if(root->rchild !=NULL)
            q.push(root->rchild);

    }

}

int main(){

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>postorder[i];
    for(int i=0;i<n;i++)
        cin>>inorder[i];

    res = create(0, n-1, 0, n-1);
    bfs(res);
    for(int i=0;i<n;i++){
        cout<<preorder[i];
        if(i!=n-1){
            printf(" ");
        }
    }

    return 0;
}
