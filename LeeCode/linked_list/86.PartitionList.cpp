struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    /*
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    ListNode* tmpHead = head;
    while (tmpHead!=nullptr) {
        if (tmpHead->val < x) {
            cur->next = new ListNode(tmpHead->val);
            cur = cur->next;
        }
        tmpHead = tmpHead->next;
    }
    tmpHead = head;
    while (tmpHead!=nullptr) {
        if (tmpHead->val >= x) {
            cur->next = new ListNode(tmpHead->val);
            cur = cur->next;
        }
        tmpHead = tmpHead->next;
    }
    return dummyHead->next;
    */

    // 优化程序
    ListNode* dummyHead1 = new ListNode(0);
    ListNode* dummyHead2 = new ListNode(0);
    ListNode* cur_dummy1 =  dummyHead1;
    ListNode* cur_dummy2 =  dummyHead2;
    for(ListNode* cur = head; cur != nullptr; cur = cur->next) {
        if(cur->val < x) {
            cur_dummy1->next = cur;
            cur_dummy1 = cur;
        } else {
            cur_dummy2->next = cur;
            cur_dummy2 = cur;
        }
    }
    cur_dummy1->next = dummyHead2->next;
    cur_dummy2->next = nullptr;

    return dummyHead1->next;
}