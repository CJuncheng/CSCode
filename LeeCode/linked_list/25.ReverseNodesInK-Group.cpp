#include "linked_list.h"

using namespace std;

inline 
ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* cur = head;
    /*
    for(int i = 0; i < k; ++i){
        ListNode* tmp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = tmp;
    }
    */
    while(cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = tmp;
    }
    return prev;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* prev = dummyHead;
    ListNode* end  = dummyHead;
    while(end->next!=nullptr) {
        for(int i = 0; i < k && end!=nullptr; ++i) end = end->next;
        if(end == nullptr) break;
        ListNode* start = prev->next;
        ListNode* tmp = end->next;
        end->next=nullptr; //断开链表
        prev->next = reverse(start);
        start->next = tmp;

        prev = start;
        end = start;
    }
    return dummyHead->next;
}


int main (int argc, char* argv[])
{
   vector<int> ivec = {1, 2, 3, 4, 5};
    ListNode* head = creatLinledList(ivec);
    ListNode* ret = reverseKGroup(head, 2);
    printLinkedList(ret);

    return 0;
}