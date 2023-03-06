struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* temp = nullptr, *cur = head, *prev = nullptr;
    while(cur) {
        temp = cur -> next;
        cur->next = prev;
            
        prev = cur;
        cur = temp;
        }
    return prev;   
}

// 递归

ListNode* reverseList(ListNode* head) {
    return reverse(nullptr, head);
}

ListNode* reverse(ListNode *prev, ListNode *cur) {
    if(cur == nullptr) return prev;
    ListNode *temp = cur->next;
    cur->next = prev;
    return reverse(cur, temp);
}