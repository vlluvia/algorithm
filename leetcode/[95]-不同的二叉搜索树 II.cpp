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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return  vector<TreeNode*>();
        }
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int left, int right){
        vector<TreeNode*> res;
        if(left > right){
            res.push_back(NULL);
            return res;
        }

        for(int i=left; i <= right; i++){
            vector<TreeNode*> leftNode = dfs(left, i-1);
            vector<TreeNode*> rightNode = dfs(i+1, right);

            for(int j =0; j< leftNode.size(); j++){
                for(int k =0; k< rightNode.size(); k++){
                    TreeNode *t = new TreeNode(i);
                    t->left = leftNode[j];
                    t->right = rightNode[k];
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};