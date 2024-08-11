#include <iostream>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr){}
  ListNode(int val_): val(val_), next(nullptr){}
  ListNode(int val_, ListNode* next_): val(0), next(next_){}
};

ListNode* twoWayMerge(ListNode* l1, ListNode* l2){
  ListNode dummyHead(0);
  ListNode* curr = &dummyHead;
  while(l1&&l2){
    ListNode* &tmp = l1->val < l2->val ? l1 : l2;
    curr->next = tmp;
    curr = curr->next;
  }
  curr->next = l1 ? l1 : l2;
  return dummyHead.next;
}


int main()
{
  /* 请在此处书写代码
     please write your code here
  */
  ListNode* l10 = new ListNode(1);
  ListNode* l11 = new ListNode(2);
  ListNode* l12 = new ListNode(4);
  l10->next = l11;  l11->next = l12; 
  ListNode* l20 = new ListNode(1);
  ListNode* l21 = new ListNode(3);
  ListNode* l22 = new ListNode(4);
  l20->next = l21;  l21->next = l22; 

  ListNode* ret = twoWayMerge(l10, l20);
  while(ret){
    cout << ret->val << " ";
    ret = ret->next;
  }
  cout << endl;
  
  
  
    
  return 0;
}