#include "linked_list.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //if(list1 == nullptr) return list2;
    //if(list2 == nullptr) return list1;
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    while(list1 && list2){ // 148. 有更高效的实现
        if(list1->val > list2->val) {
            cur->next = list2; 
            list2 = list2->next;
        } else {
            cur->next = list1; 
            list1 = list1->next;
        }
        cur = cur->next;
    }
    cur->next = !list1 ? list2 : list1;
    return dummyHead->next; 
}