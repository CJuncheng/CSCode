
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) { //快慢双指针法
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* fast = dummyHead;
    ListNode* slow = dummyHead;
    while (n-- && fast != nullptr) {
        fast = fast->next;
    }
    fast = fast->next;
    while(fast!=nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}