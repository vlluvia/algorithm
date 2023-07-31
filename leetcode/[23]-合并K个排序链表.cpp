ListNode* mergeKLists(vector<ListNode*>& lists) {
    list<ListNode> l;
    ListNode* head = new ListNode(0);
    ListNode* backup = head;
    for(auto i=lists.begin();i!=lists.end();++i){
        ListNode* ihead = *i;
        while(ihead){
            l.push_back(ListNode(ihead->val));
            ihead = ihead->next;
        }
    }
    l.sort([](const ListNode& a,const ListNode& b){
        return a.val <= b.val;
    });
    for(auto i=l.begin();i!=l.end();++i){
        head->next = new ListNode(i->val);
        head = head->next;
    }

    return backup->next;
}