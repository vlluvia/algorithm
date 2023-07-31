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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder: [root, [left], [right]]
        // inorder:  [[left], root, [right]]
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, int lo1, int hi1, vector<int>& inorder, int lo2, int hi2) {
        if (lo1 > hi1 || lo2 > hi2) return nullptr;
        int root = preorder[lo1];
        int mid = lo2;
        // 在 inorder 中查找 root 位置
        for (int i = lo2; i <= hi2; ++i) {
            if (inorder[i] == root) {
                mid = i;
                break;
            }
        }

        auto s = new TreeNode(root);
        // 下面的数组表示分割长度
        // inorder: [mid-lo2, mid, hi2-mid]
        // preorder:[root, mid-lo2, hi2-mid]
        s->left = buildTree(preorder, lo1+1, lo1+mid-lo2, inorder, lo2, mid-1);
        s->right = buildTree(preorder, lo1+mid-lo2+1, hi1, inorder, mid+1, hi2);
        return s;
    }
};