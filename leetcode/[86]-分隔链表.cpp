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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_dummp = new ListNode(0);
        ListNode* before = before_dummp;
        ListNode* after_dummp = new ListNode(0);
        ListNode* after = after_dummp;

        while(head !=NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = after_dummp->next;
        return before_dummp->next;
    }
};