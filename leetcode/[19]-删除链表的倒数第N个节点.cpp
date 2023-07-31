ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head | !head -> next) return NULL;
    ListNode* temp1 = head,*temp2 = head;
    for(int i = 0;i < n; i++){
        if(temp1->next){
            temp1 = temp1->next;
        }else{
            return head->next;
        }
    }
    while(temp1->next){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2->next = temp2->next->next;

    return head;
}