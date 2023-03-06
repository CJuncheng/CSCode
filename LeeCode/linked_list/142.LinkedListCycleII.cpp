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

/** 方法1 快慢双指针 fast, slow
 *  slow走 1 步， fast走 2 步，如果有环，则一定相遇
 *  设 x: 头节点到入环第一个节点长度； y: 入环第一个节点到相遇节点的长度； z: 相遇节点到入环第一个节点的长度
 *  n: fast指针在环中转的圈数
 *  (x+y)*2 = x+y+n*(y+z) --> x+y = n*(y+z) --> x = n*(y+z) - y = (n-1)*(y+z) + z
 *  从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。
 */ 
ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) { //快慢指针相遇
            ListNode* node1 = head;
            ListNode* node2 = fast;
            while(node1!=node2) {
                node1 = node1->next;
                node2 = node2->next;
            }
            return node1;
        }
    }
    return nullptr;
}