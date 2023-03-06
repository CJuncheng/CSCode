#include "linked_list.h"

using namespace std;

inline 
ListNode* reverse(ListNode* head){  //反转链表，经典
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while(cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = tmp;
    }
    return prev;
}

void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return;
    ListNode* slow = head, *fast = head;
    while(fast&&fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow;        //获取中间节点
    slow = reverse(slow->next);  //反转后的后半段
    mid->next = nullptr;  //前半段添加尾部空节点
    ListNode* cur = head;
    while(slow){
        ListNode* tmp = cur->next;
        cur->next = slow;
        slow = slow->next;
        cur->next->next = tmp;
        cur = tmp;
    }
}

int main (int argc, char* argv[])
{
   vector<int> ivec = {1,2,3,4,5};
    ListNode* head = creatLinledList(ivec);
    reorderList(head);
    printLinkedList(head);

    return 0;
}