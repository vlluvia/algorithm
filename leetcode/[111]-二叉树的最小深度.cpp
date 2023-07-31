/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int mina=10000;
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root, 0);
        return mina;
    }

    void dfs(TreeNode* root, int mint){
        if(mint == mina) return;
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(mint + 1 < mina){
                mina = mint +1 ;
            }
            return;
        }
        dfs(root->left, mint +1);
        dfs(root->right, mint +1);
    }
};