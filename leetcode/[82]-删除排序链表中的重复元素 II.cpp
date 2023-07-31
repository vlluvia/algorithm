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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* first = dummy;
        ListNode* second = dummy->next;
        while(second != NULL){
            if(second->next!=NULL && second->val == second->next->val){
                while(second->next!=NULL && second->val == second->next->val){
                    second = second->next;
                }
                first->next = second->next;
                second = second->next;
            }else{
                second = second->next;
                first = first->next;
            }
        }
        return dummy->next;
    }
};