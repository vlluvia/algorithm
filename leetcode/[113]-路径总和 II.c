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
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> res;
            vector<int> temp;
            dfs(root, temp, res, 0, sum);
            return res;
        }
        void dfs(TreeNode* root, vector<int> &temp,vector<vector<int>> &res, int mint, int sum){
            //if(mint > sum) return;
            if(root == NULL){
                return;
            }

            if(root->left == NULL && root->right == NULL){
                if(mint + root->val == sum){
                    temp.push_back(root->val);
                    res.push_back(temp);
                    temp.pop_back();
                }
                return;
            }
            temp.push_back(root->val);
            dfs(root->left,  temp, res, mint + root->val, sum);
            dfs(root->right,  temp, res, mint + root->val, sum);
            temp.pop_back();
        }
};