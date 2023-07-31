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
    int maxa = -1111;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxa;
    }

    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        maxa = max(maxa, root->val+l+r);
        return max(l, r) + root->val;
    }
};