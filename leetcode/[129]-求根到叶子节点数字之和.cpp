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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int tsum){
        if(root == NULL){
            return ;
        }
        if(tsum == 0){
            tsum = root->val;
        }else{
            tsum = tsum * 10 + root->val;
        }
        if(root->left ==NULL && root->right == NULL){
            sum+=tsum;
            return;
        }
        dfs(root->left, tsum);
        dfs(root->right, tsum);
    }
};