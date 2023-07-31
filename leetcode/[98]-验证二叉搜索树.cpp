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
    vector<int> data;
    bool isValidBST(TreeNode* root) {

        dfs(root);
        for(int i=1;i<data.size();i++){
            if(data[i-1] >= data[i]){
                return false;
            }
        }
        return true;
    }
    void dfs(TreeNode* root){
        if(root == NULL){
            return ;
        }
        dfs(root->left);
        data.push_back(root->val);
        dfs(root->right);
    }
};