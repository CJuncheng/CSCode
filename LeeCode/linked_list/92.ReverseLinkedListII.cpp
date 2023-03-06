#include "linked_list.h"

using namespace std;

ListNode* reverseBetween(ListNode* head, int left_val, int right_val) {
    if (left_val==right_val) return head;
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    for(int i = 1; i < left_val; ++i)
        cur = cur->next;
    ListNode* left_left = cur;
    ListNode* left = cur->next;
    ListNode* prev = nullptr;
    cur = left;
    for(int i = left_val; i < right_val+1; ++i){
        ListNode* tmp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = tmp;
    }
    ListNode* right = prev;
    ListNode* right_right = cur;  
    left_left->next = right;
    left->next = right_right;
    return dummyHead->next;



/*
    ListNode* left = new ListNode(0);
    ListNode* right= new ListNode(0);
    ListNode* right_right= new ListNode(0);

    while(cur->next!=nullptr) {
        if(cur->next->val == left_val){
            
            left_left = cur;
            left = cur->next;
            ListNode* prev = nullptr;
            cur = left;
            while(cur){  // 进入需要翻转的区间 [left, right]
                cout << cur->val << endl;
                ListNode* tmp = cur->next;
                cur->next = prev;

                prev = cur;
                cur = tmp;
                if(prev->val == right_val){ 
                    right = prev;
                    right_right = cur;  
                    break;
                }
            }
        }
        cur = cur->next;
    }
    left_left->next = right;
    left->next = right_right;
    */
    
}

int main (int argc, char* argv[])
{
   vector<int> ivec = {3,4};
    ListNode* head = creatLinledList(ivec);
    ListNode* ret = reverseBetween(head, 1, 2);
    printLinkedList(ret);

    return 0;
}