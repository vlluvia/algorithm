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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        ListNode *res = new ListNode(0);
        ListNode *t   = res;
        while(l1 != NULL || l2 != NULL){
            int sum1 = l1?l1->val:0;
            int sum2 = l2?l2->val:0;
            t->next = new ListNode((sum1 + sum2 + temp) % 10);
            temp   = (sum1 + sum2 + temp) / 10;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            t = t->next;
        }
        if(temp != 0){
            t->next = new ListNode(temp);
        }
        return res->next;
    }
};