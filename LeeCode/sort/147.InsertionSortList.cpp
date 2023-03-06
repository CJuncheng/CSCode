#include "linked_list.h"

using namespace std;
ListNode* insertionSortList(ListNode* head) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    while(head && head->next) {
        if(head->val < head->next->val) {
            head = head->next; continue;
        }
        ListNode* pre = dummyHead;
        while(pre->next->val < head->next->val) pre = pre->next; // 将 head->next 插入到 pre后面
        ListNode* tmp = head->next;
        head->next = head->next->next;
        tmp->next = pre->next;
        pre->next = tmp;
    }
    return dummyHead->next;
}

int main (int argc, char* argv[])
{
   vector<int> ivec = {4,2,1,3};
    ListNode* head = creatLinledList(ivec);
    ListNode* ret = insertionSortList(head);
    printLinkedList(ret);

    return 0;
}