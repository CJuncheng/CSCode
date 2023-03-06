#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template<typename T>
inline ListNode* creatLinledList(const T& val){
    //ListNode* head;// = new ListNode(0);
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    const size_t len = val.size();
    for(size_t i = 0; i < len; ++i){
        cur->next = new ListNode(val[i]);
        cur = cur->next;
    }
    return dummyHead->next;
}

inline void printLinkedList(ListNode* node)
{
    std::cout << "Print linked list: " << std::endl;
    while(node!=nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
