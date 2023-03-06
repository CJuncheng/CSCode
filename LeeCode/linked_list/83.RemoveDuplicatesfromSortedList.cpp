#include "linked_list.h"

using namespace std;


ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;
    for(ListNode* prev = head, *cur = head->next; cur; cur = prev->next) {
        if(prev->val == cur->val){
            prev->next = cur->next;
            delete cur;
        } else {
            prev = cur;
        }
    }
    return head;
}

int main (int argc, char* argv[])
{
   vector<int> ivec = {1,1,2};
    ListNode* head = creatLinledList(ivec);
    ListNode* ret = deleteDuplicates(head);
    printLinkedList(ret);

    return 0;
}