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

    TreeNode* create(int i1, int i2, int p1, int p2, vector<int>& inorder, vector<int>& postorder){
        if(i1 > i2 || p1 > p2) return NULL;
        TreeNode* root = new TreeNode;
        root->val = postorder[p2];
        int k;
        for(k = i1; k<= i2; k++){
            if(inorder[k] == root->val){
                break;
            }
        }

        root->left = create(i1, k-1, p1, p1 + k - i1 -1, inorder, postorder);
        root->right = create(k +1, i2, p2 +k -i2, p2-1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);
    }
};