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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen = 0, blen = 0;
        ListNode *a = headA, *b = headB;
        while(a !=NULL){
            alen++;
            a = a->next;
        }
        while(b !=NULL){
            blen++;
            b = b->next;
        }
        a = headA;
        b = headB;
        if(alen > blen){
            int x = alen - blen;
            while(x--){
                a = a->next;
            }
        }else{
            int x = blen - alen;
            while(x--){
                b = b->next;
            }
        }

        while(a != b){
            a = a->next;
            b = b->next;
        }
        return a;

    }
};