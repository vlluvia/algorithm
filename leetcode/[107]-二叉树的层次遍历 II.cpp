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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            vector<int> mid;
            int size = q.size();
            for(int i=0;i<size; i++){
                TreeNode* temp = q.front();
                mid.push_back(temp->val);
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            res.push_back(mid);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};