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
    bool isBalanced(TreeNode* root) {
        return process(root) != -1;
    }
    // -1为不平衡
    int process(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = process(root->left);
        if(left == -1)
            return -1;
        int right = process(root->right);
        if(right == -1)
            return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};