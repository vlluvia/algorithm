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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> temp;
        while(head !=NULL){
            temp.push_back(head->val);
            head = head->next;
        }

        sort(temp.begin(), temp.end());
        ListNode* res = new ListNode(0);
        ListNode* res_temp = res;
        for(auto item: temp){
            ListNode* t = new ListNode(item);
            res_temp->next = t;
            res_temp = res_temp->next;
        }
        return res->next;
    }
};