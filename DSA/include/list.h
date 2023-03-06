/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * April 9, 2022
 ******************************************************************************************/
#pragma once

using Rank = size_t; //秩
using int32 = int;

// ==================== ListNode ====================
template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode <T>*; //列表节点位置，list内存空间不连续，按位置访问
template <typename T>
struct ListNode //列表节点模板类（以双向链表形式实现）
{
    //成员
    T data; ListNodePosi<T> pred; ListNodePosi<T> succ; //数值、前驱、后继
    // 构造函数
    ListNode() {} // 针对 header 和 trailer 的构造
    ListNode(T e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL) : data (e), pred (p), succ (s) {} //默认构造函数
    // 操作接口
    ListNodePosi<T> insertAsPred (T const & e); // 紧靠当前节点之前插入节点
    ListNodePosi<T> insertAsSucc (T const & e); // 紧靠当前节点之后插入节点
}; 

template <typename T>                         //将e紧靠当前节点之前插入于当前节点所属列表（设有哨兵头节点header）
ListNodePosi<T> ListNode<T>::insertAsPred(T const &e)
{
    ListNodePosi<T> x = new ListNode(e, pred, this); //创建新节点
    pred->succ = x;
    pred = x; //设置正向链接
    return x; //返回新节点的位置
}

template <typename T> //将e紧随当前节点之后插入于当前节点所属列表（设有哨兵尾节点trailer）
ListNodePosi<T> ListNode<T>::insertAsSucc(T const &e)
{
    ListNodePosi<T> x = new ListNode(e, this, succ); //创建新节点
    succ->pred = x;
    succ = x; //设置逆向链接
    return x; //返回新节点的位置
}

// ==================== List ====================
template <typename T> class List //列表模板
{
    public:
        int _size; ListNodePosi<T> header; ListNodePosi<T> trailer; //规模、头哨兵、尾哨兵
    protected:
        void init(); //列表创建时的初始化
        void copyNodes(ListNodePosi<T>, int); //复制列表中自位置p起的n项
    public:
        // 构造函数
        List() { init(); } //默认
        List(List<T> const &L);                //整体复制列表L
        List(ListNodePosi<T> p, int n);        //复制列表中自位置p起的n项
        // 析构函数
        ~List(){};                               //释放（包含头、尾哨兵在内的）所有节点
        //只读访问接口
        Rank size() const { return _size; }       //规模
        bool empty() const { return _size <= 0; } //判空
        ListNodePosi<T> first() const { return header->succ; } //首节点位置
        ListNodePosi<T> last() const { return trailer->pred; } //末节点位置
        // 可写访问接口
        // 插入
        ListNodePosi<T> insertAsFirst(T const &e); //将e当作首节点插入
        ListNodePosi<T> insertAsLast(T const &e);  //将e当作末节点插入
        ListNodePosi<T> insert(ListNodePosi<T> p, T const &e); //将e当作p的后继插入
        ListNodePosi<T> insert(T const &e, ListNodePosi<T> p); //将e当作p的前驱插入
        // 查找
        ListNodePosi<T> find(T const &e) const //无序列表查找
        {
            return find(e, _size, trailer);
        }
        ListNodePosi<T> find(T const &e, int n, ListNodePosi<T> p) const; //无序区间查找

        //删除
        T remove(ListNodePosi<T> p);               //删除合法位置p处的节点,返回被删除节点
};

template <typename T>
void List<T>::init()
{                              //列表初始化，在创建列表对象时统一调用
    header = new ListNode<T>;  //创建头哨兵节点
    trailer = new ListNode<T>; //创建尾哨兵节点
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0; //记录规模
}

template <typename T> //列表内部方法：复制列表中自位置p起的n项
void List<T>::copyNodes(ListNodePosi<T> p, int n)
{           // p合法，且至少有n-1个真后继节点
    init(); //创建头、尾哨兵节点并做初始化
    while (n--)
    {
        insertAsLast(p->data);
        p = p->succ;
    } //将起自p的n项依次作为末节点插入
}

// 构造函数
template <typename T> //复制列表中自位置p起的n项（assert: p为合法位置，且至少有n-1个后继节点）
List<T>::List(ListNodePosi<T> p, int n)
{
    copyNodes(p, n);
}

template <typename T> //整体复制列表L
List<T>::List(List<T> const &L)
{
    copyNodes(L.first(), L._size);
}

template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(T const &e)
{
    _size++;
    return header->insertAsSucc(e);
} // e当作首节点插入

template <typename T>
ListNodePosi<T> List<T>::insertAsLast(T const &e)
{
    _size++;
    return trailer->insertAsPred(e);
} // e当作末节点插入

template <typename T>
ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const &e)
{
    _size++;
    return p->insertAsSucc(e);
} // e当作p的后继插入

template <typename T>
ListNodePosi<T> List<T>::insert(T const &e, ListNodePosi<T> p)
{
    _size++;
    return p->insertAsPred(e);
} // e当作p的前驱插入

template <typename T> //在无序列表内节点p（可能是trailer）的n个（真）前驱中，找到等于e的最后者
ListNodePosi<T> List<T>::find(T const &e, int n, ListNodePosi<T> p) const
{
    while (0 < n--) //（0 <= n <= rank(p) < _size）对于p的最近的n个前驱，从右向左
        if (e == (p = p->pred)->data)
            return p; //逐个比对，直至命中或范围越界
    return NULL;      // p越出左边界意味着区间内不含e，查找失败
} //失败时，返回NULL

template <typename T>
T List<T>::remove(ListNodePosi<T> p)
{                  //删除合法节点p，返回其数值
    T e = p->data; //备份待删除节点的数值（假定T类型可直接赋值）
    p->pred->succ = p->succ;
    p->succ->pred = p->pred; //后继、前驱
    delete p;
    _size--;  //释放节点，更新规模
    return e; //返回备份的数值
}
