#include "linked_list.h"
using namespace std;

ListNode* twoWayMerge(ListNode* list1, ListNode* list2) { //list1, list2各自有序
    ListNode dummyHead(0);
    ListNode* cur = &dummyHead;
    while(list1 && list2){
        ListNode* &tmpNode = list1->val < list2->val ? list1 : list2;
        cur = cur->next = tmpNode;
        tmpNode = tmpNode->next;
    }
    cur->next = list1 ? list1 : list2;
    return dummyHead.next; 
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;
    fast = slow->next, slow->next = nullptr; // 切链
    return twoWayMerge(sortList(head), sortList(fast));
}