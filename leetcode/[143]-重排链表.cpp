/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode *> stemp;
        ListNode* cur = head;
        int sum = 0;
        while(head != NULL){
            stemp.push(head);
            head = head->next;
            sum++;
        }

        for(int i=0;i< sum /2;i++){
            ListNode * temp = stemp.top();
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next->next;
            stemp.pop();
        }
        if(cur != NULL) cur->next = NULL;

    }
};