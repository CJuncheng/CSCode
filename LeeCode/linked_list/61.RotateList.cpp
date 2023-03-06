#include "linked_list.h"

using namespace std;

inline void rotatOnceTime(ListNode* &head)
{
    ListNode* cur = head;
    while(cur) {
        if(cur->next->next == nullptr){
            ListNode* tmp = cur->next;
            cur->next = nullptr;
            
            tmp->next = head;
            head = tmp;
            break;
        }
        cur = cur->next;
    }
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr || k==0) return head;
    size_t len = 0;
    ListNode* cur = head;
    while(cur) {
        ++len;
        cur = cur->next;
    }
    size_t count = k%len;
    while(count--){
        rotatOnceTime(head);
    }
    return head;
}

int main (int argc, char* argv[])
{
   vector<int> ivec = {0,1,2};
    ListNode* head = creatLinledList(ivec);
    ListNode* ret = rotateRight(head, 4);
    printLinkedList(ret);

    return 0;
}