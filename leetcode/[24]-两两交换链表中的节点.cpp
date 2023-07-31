ListNode* swapPairs(ListNode* head) {
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *p1 = res;
    while(p1->next!=NULL&&p1->next->next!=NULL){
        ListNode *p2 = p1->next;
        p1->next = p2->next;
        p2->next = p2->next->next;
        p1->next->next=p2;
        p1=p2;
    }
    return res->next;
}