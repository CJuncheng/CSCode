
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/** 方法1 (迭代) O(n)
 *  (1) 在每个节点的后面加上它的复制，并将原链表和复制链表连在一起。
 *  (2) 从前往后遍历每一个原链表节点，对于有 random 指针的节点 p，
 *      我们让它的 p->next->random = p->random->next，这样我们就完成了对原链表 random 指针的复刻。
 *  (3) 最后我们把原链表和复制链表拆分出来，并将原链表复原。
 *  Reference: https://leetcode.cn/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-c2nvs/
 */ 
Node* copyRandomList(Node* head) {
    for( Node* p = head; p!=nullptr; p = p->next->next){
        Node* q = new Node(p->val);
        q->next = p->next;
        p->next = q;
    }
    for( Node* p = head; p!=nullptr; p = p->next->next)
        if(p->random!=nullptr)
            p->next->random = p->random->next;

    Node* dummy = new Node(0);
    Node* cur = dummy;
    for(Node* p = head; p!=nullptr; p = p->next){
        //Node* tmp = p->next;
        cur = cur->next = p->next;
        p->next = p->next->next;
    }
    return dummy->next;
}