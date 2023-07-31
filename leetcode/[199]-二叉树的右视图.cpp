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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        res.push_back(root->val);
        while(!que.empty()){
            int siez = que.size();
            for(int i=0;i<siez;i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            if(!que.empty()){
                res.push_back((que.back())->val);
            }
        }
        return res;
    }
};