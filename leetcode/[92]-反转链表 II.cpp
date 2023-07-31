/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummp = new ListNode(0);
        dummp->next = head;
        ListNode* pre = dummp;
        for(int i=1;i < m; i++){
            pre = pre->next;
        }

        head = pre->next;
        for(int i=m; i<n;i++){
            ListNode* nex = head->next;
            head->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummp->next;
    }
};