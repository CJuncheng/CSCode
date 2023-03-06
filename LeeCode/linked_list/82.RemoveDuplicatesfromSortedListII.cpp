#include "linked_list.h"

using namespace std;



ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* prev = dummyHead;
    ListNode* cur = head;
    while(cur!=nullptr){
        bool duplicated = false;
        while(cur!=nullptr &&cur->next!=nullptr && cur->val == cur->next->val){
            duplicated = true;
            //ListNode* tmp = cur;
            cur = cur->next;
            //delete tmp;
        }
        if(duplicated) {
            //ListNode* tmp = cur;
            cur = cur->next;
            //delete tmp;
            continue;
        }
        prev->next = cur;
        prev = prev->next;
        //if(cur == nullptr) break;
        cur = cur->next;
    }
     prev->next = cur;
    return dummyHead->next;

}

int main (int argc, char* argv[])
{
    vector<int> ivec = {1,1};
    ListNode* head = creatLinledList(ivec);
    ListNode* ret = deleteDuplicates(head);
    printLinkedList(ret);

    return 0;
}