
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr) {
        const int a = l1==nullptr ? 0 : l1->val;
        const int b = l2==nullptr ? 0 : l2->val;
        const int value = (a+b+carry);
        carry = value/10;
        cur->next = new ListNode(value%10);
        cur = cur->next;
        if(l1!=nullptr) l1 = l1->next;
        if(l2!=nullptr) l2 = l2->next;
    }
    if (carry > 0) cur->next = new ListNode(carry);
    return dummyHead->next;
}