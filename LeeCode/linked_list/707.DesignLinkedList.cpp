#include "linked_list.h"

class MyLinkedList {
public:
    struct LinkListedNode{
        int val;
        LinkListedNode* next;
        LinkListedNode(int val): val(val), next(nullptr){}
    };
private:
    int len;
    LinkListedNode* dummyNode;
public:
    MyLinkedList() {
        len = 0;
        dummyNode = new LinkListedNode(0);
    }
    
    int get(int index) {
        if(index > len -1 || index < 0) return -1;
        LinkListedNode* cur = dummyNode->next;
        while(index--) cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        if (val<0 || val > 1000) return;
        ++len;
        LinkListedNode* temp = new LinkListedNode(val);
        temp->next = dummyNode->next;
        dummyNode->next = temp;
    }
    
    void addAtTail(int val) {
        if (val<0 || val > 1000) return;
        ++len;
        LinkListedNode* temp = new LinkListedNode(val);

        LinkListedNode* cur = dummyNode;
        while(cur->next) cur = cur->next;
        cur->next = temp;
    }
    
    void addAtIndex(int index, int val) {
        if(index > len || index < 0) return;
        ++len;
        LinkListedNode* newNode = new LinkListedNode(val);
        LinkListedNode* cur = dummyNode;
        while(index--) cur = cur->next;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if(index > len -1 || index < 0) return;
        --len;
        LinkListedNode* newNode = new LinkListedNode(0);
        LinkListedNode* cur = dummyNode;
        while(index--) cur = cur->next;
        LinkListedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
    }
};


