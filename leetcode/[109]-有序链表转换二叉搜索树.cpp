/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        return buildTree(v, 0, v.size());
    }
    TreeNode * buildTree(vector<int> & v, int begin, int end){
        if(begin == end) return nullptr;
        int middle = (begin+end)/2;
        TreeNode * root = new TreeNode(v[middle]);
        root->left = buildTree(v, begin, middle);
        root->right = buildTree(v, middle+1, end);
        return root;
    }

};