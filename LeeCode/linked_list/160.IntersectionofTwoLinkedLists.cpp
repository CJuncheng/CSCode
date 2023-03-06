
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/** 方法1
 *  先求长度，设定较长一方
 *  找到使得两个链表尾部对齐的node
 *  从node开始遍历知道有相等的节点
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    size_t lenA = 0, lenB = 0;
    while(curA!=nullptr) {
        ++lenA;
        curA = curA->next;
    }
    while(curB!=nullptr) {
        ++lenB;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    
    //设A的链表最长
    if(lenA<lenB) {
        swap(lenA, lenB);
        swap(curA, curB);
    }
    size_t gap = lenA -lenB;
    while(gap--) curA =curA->next;
    while(curA != nullptr){
        if(curA == curB) return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return nullptr;
}

/** 方法2
 * 链表A长 a, B长 b, 公共长c
 *  curA 先遍历完链表 headA ，再开始遍历链表 headB ，当走到 node 时，共走步数为：a + (b - c)
 *  curB 先遍历完链表 headB ，再开始遍历链表 headA ，当走到 node 时，共走步数为：b + (a - c)
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr||headB==nullptr) return nullptr;
    ListNode* curA = headA;
    ListNode* curB = headB;
    while(curA!=curB){
        curA = curA == nullptr ? headB : curA->next;
        curB = curB == nullptr ? headA : curB->next;
    }
    return curA;
}