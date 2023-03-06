

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode* cur = dummyNode;
    while(cur->next != nullptr && cur->next->next != nullptr) {
        ListNode* tmp = cur->next;
        ListNode* tmp2 = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = tmp;
        cur->next->next->next = tmp2;

        cur = cur->next->next;
    }
    return dummyNode->next;
}

//递归方法,对于递归的理解仍然不够
// https://lyl0724.github.io/2020/01/25/1/
/*
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head.next == nullptr){
            return head;
        }
        ListNode next = head.next;
        head.next = swapPairs(next.next);
        next.next = head;
        return next;
}
*/