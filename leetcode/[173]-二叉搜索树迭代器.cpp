/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> data;
    int i=0;

    void dfs(TreeNode* root){
        if(root ==NULL){
            return;
        }
        data.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    BSTIterator(TreeNode* root) {
        dfs(root);
        sort(data.begin(), data.end());
    }

    /** @return the next smallest number */
    int next() {
        return data[i++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return data.size() != i ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */