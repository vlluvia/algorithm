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
    bool flag = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        dfs(root, 0, sum);
        return flag;
    }

    void dfs(TreeNode* root, int mint, int sum){
        if(flag) return;
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(mint + root->val == sum){
                flag = true;
            }
            return;
        }
        dfs(root->left, mint + root->val, sum);
        dfs(root->right, mint + root->val, sum);
    }
};