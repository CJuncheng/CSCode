// 实现一个链表，删除链表倒数第 N 节点, 返回头节点

#include <vector>
#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val_): val(val_), next(nullptr) {}
};

ListNode* removeNthNodeFromEnd(ListNode* head, int n){
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* currNode = dummyHead;

    int nNode = 0;
    while(head){
        ++nNode;
        head = head->next;
    }
    int idx = nNode - n;
    while(idx--) currNode = currNode->next;
    
    ListNode* tmp = currNode->next;
    currNode->next = tmp->next;
    delete tmp;

    return dummyHead->next;
}

int main(int argc, char* argv[]){
    ListNode* head = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    head->next = node1; 
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int n = 2;
    ListNode* headRet = removeNthNodeFromEnd(head, n);
    while(headRet){
        cout << headRet->val << endl;
        headRet = headRet->next;
    }
    return 0;
}