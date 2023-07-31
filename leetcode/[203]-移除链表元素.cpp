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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* header = new ListNode(-1);
        ListNode* second = header;

        while(head !=NULL){
            while(head && head->val == val){
                head = head->next;
            }
            if(head == NULL) break;
            second->next = head;
            second = second->next;
            head = head->next;
        }
        second->next = NULL;
        return header->next;
    }
};