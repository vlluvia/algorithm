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
        dummy->next = head;
        ListNode* a1 = dummy, *a2 = dummy->next;
        while(a2 !=NULL){
            if(a2->next!=NULL && a2->val == a2->next->val){
                while(a2->next!=NULL && a2->val == a2->next->val){
                    a2 = a2->next;
                }
                //cout<<(a1->val)<<" "<<(a2->val)<<endl;
                a1->next->next = a2->next;
                a1 = a1->next;
                a2 = a2->next;
            }else {
                //cout<<"---> "<<(a1->val)<<" "<<(a2->val)<<endl;
                a1 = a1->next;
                a2 = a2->next;
            }
        }
        return dummy->next;
    }
};