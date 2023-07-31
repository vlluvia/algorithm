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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0){
            return head;
        }
        ListNode* cursor = head;
        ListNode* tailor = NULL;
        int n = 1;
        while(cursor->next != NULL){
            cursor = cursor->next;
            n++;
        }

        int length = n - k % n;
        tailor = cursor;
        cursor->next = head;
        cursor = head;
        for(int i=0;i < length; i++){
            cursor = cursor->next;
            tailor = tailor->next;
        }
        tailor->next = NULL;
        return cursor;
    }
};