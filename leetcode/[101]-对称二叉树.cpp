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
        bool isSymmetric(TreeNode* root) {
            return dfs(root, root);
        }

        bool dfs(TreeNode* l, TreeNode* r){
            if(l==NULL && r == NULL){
                return true;
            }

            if(l==NULL || r == NULL){
                return false;
            }

            if(l->val == r->val){
                return dfs(l->left, r->right) && dfs(r->right, l->left);
            }
            return false;
        }
};