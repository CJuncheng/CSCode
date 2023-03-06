#include "linked_list.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
class Solution { // O(n*nlogn)
private:
    ListNode* twoWayMerge(ListNode* list1, ListNode* list2) { //list1, list2各自有序
        ListNode dummyHead(0);
        ListNode* cur = &dummyHead;
        while(list1 && list2){
            ListNode* &tmpNode = list1->val < list2->val ? list1 : list2;
            cur = cur->next = tmpNode;
            tmpNode = tmpNode->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummyHead.next; 
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        const int len = lists.size();
        ListNode* cur = lists[0];
        for(int i = 1; i < len; ++i)
            cur = twoWayMerge(cur, lists[i]);
        return cur;
    }
};
*/
class Solution { // 优先级队列
private:
    struct CmpMore{
        bool operator()(const ListNode* lhs, const ListNode* rhs){
            return lhs->val > rhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode dummyHead(0);
        ListNode* cur = &dummyHead;
        priority_queue<ListNode*, vector<ListNode*>,CmpMore> priQue;
        for(auto& list : lists)
            if(list) priQue.push(list);
        while(!priQue.empty()){
            ListNode* tmpNode = priQue.top();
            priQue.pop();
            if(tmpNode->next) priQue.push(tmpNode->next);
            cur = cur->next = tmpNode;
        }
        return dummyHead.next;        
    }
};