#include "linked_list.h"
using namespace std;

/* https://leetcode.cn/problems/merge-k-sorted-lists/solution/4-chong-fang-fa-xiang-jie-bi-xu-miao-dong-by-sweet/
 *
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    const int len = lists.size();
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    while(true) {
        ListNode* minNode = nullptr;
        int minNodeIndex = -1;
        for(int i = 0; i < len; ++i) {
            if(lists[i] == nullptr) continue;
            if(minNode == nullptr || lists[i]->val < minNode->val) {
                minNode = lists[i];
                minNodeIndex = i;
            }
        }
        if(minNodeIndex==-1) break;
        cur->next = minNode;
        cur = cur->next;
        lists[minNodeIndex] =  lists[minNodeIndex]->next;
    }
    return dummyHead->next;

}

// 方法2
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //if(list1 == nullptr) return list2;
    //if(list2 == nullptr) return list1;
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    while(list1 && list2){
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
ListNode* mergeKLists(vector<ListNode*>& lists) {
    const int len = lists.size();
    if(!len) return nullptr;
    ListNode* cur = lists[0];
    for(int i = 1; i < len; ++i)
        cur = mergeTwoLists(cur, lists[i]); //递归
    return cur;
}