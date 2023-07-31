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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0), *next, *pre = dummy, *cur = head;
        dummy->next = head;
        int n=0;
        while(head!=NULL){
            n++;
            head = head->next;
        }
        head = dummy->next;
        for(int i=0;i<n/k; i++){
            for(int j = 0; j < k-1;j++){
                next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = cur;
            cur = pre->next;
        }

        return dummy->next;
    }
};