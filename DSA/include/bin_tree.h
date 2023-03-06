/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * April 20, 2022
 ******************************************************************************************/
#pragma once

#include <cstdlib>
#include "queue.h" //引入队列

/******************************************************************************************
 * BinNode状态与性质的判断
 ******************************************************************************************/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))     //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))
#define IsChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))

/******************************************************************************************
 * 与BinNode具有特定关系的节点及指针
 ******************************************************************************************/
#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc) /*兄弟*/
#define uncle(x) (sibling((x)->parent))                                 /*叔叔*/
#define FromParentTo(x)                                                 /*来自父亲的引用*/ \
    (IsRoot(x) ? BinTree<T>::_root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

#if defined(DSA_REDBLACK)
#define stature(p) ((p) ? (p)->height : 0) //红黑树节点的黑高度（NULL视作外部节点，对应于0）
#else
#define stature(p) ((p) ? (p)->height : -1) //其余BST中节点的高度（NUll视作空树，对应于-1）
#endif

typedef enum {RB_RED, RB_BLACK} RBColor; //节点颜色

/******************************************************************************************
 * BinNode模板类
 ******************************************************************************************/
template <typename T> struct BinNode;
template <typename T> using BinNodePosi = BinNode<T>*; 
template <typename T> 
struct BinNode
{
    //成员（为简化描述起见统一开放，读者可根据需要进一步封装）
    BinNodePosi<T> parent;          //父亲
    BinNodePosi<T>  lc, rc;         //孩子
    T data; size_t height;         // 高度
    size_t size(void); //子树规模
    int npl;                              // Null Path Length（左式堆，也可直接用height代替）
    RBColor color;                        //颜色（红黑树）
    //构造函数
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi<T> p = NULL, BinNodePosi<T> lc = NULL, BinNodePosi<T> rc = NULL, 
            int h = 0, int l = 1, RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
    //操作接口
    BinNodePosi<T> insertAsLC(T const &); //作为左孩子插入节点
    BinNodePosi<T> insertAsRC(T const &); //作为右孩子插入节点
    BinNodePosi<T> succ(void); // (中序遍历意义下)当前节点的直接后继
    template <typename VST> void travLevel( VST &); //子树层次遍历
    template <typename VST> void travPre( VST &); //子树先序遍历
    template <typename VST> void travIn(VST &); //子树中序遍历
    template <typename VST> void travPost( VST &); //子树后序遍历
    // 比较器、判等器（各列其一，其余自行补充）
    bool operator<(BinNode const &bn) { return data < bn.data; }   //小于
    bool operator==(BinNode const &bn) { return data == bn.data; } //等于
    /*DSA*/
    //BinNodePosi<T> zig();                                  //顺时针旋转
    //BinNodePosi<T> zag();                                  //逆时针旋转
    //BinNodePosi<T> balance();                              //完全平衡化
    //BinNodePosi<T> imitate(const BinNodePosi<T>);
};

template <typename T>
BinNodePosi<T> BinNode<T>::insertAsLC(T const &e)
{
    return lc = new BinNode(e, this);
} //将e作为当前节点的左孩子插入二叉树

template <typename T>
BinNodePosi<T> BinNode<T>::insertAsRC(T const &e)
{
    return rc = new BinNode(e, this);
} //将e作为当前节点的右孩子插入二叉树

template <typename T>
size_t BinNode<T>::size()
{              //统计当前节点后代总数，即以其为根的子树规模
    int s = 1; //计入本身
    if (lc)
        s += lc->size(); //递归计入左子树规模
    if (rc)
        s += rc->size(); //递归计入右子树规模
    return s;
}

template <typename T> 
BinNodePosi<T> BinNode<T>::succ() { //定位节点v的直接后继
   BinNodePosi<T> s = this; //记录后继的临时变量
   if ( rc ) { //若有右孩子，则直接后继必在右子树中，右子树沿左下方深入
      s = rc; //右子树中
      while ( HasLChild ( *s ) ) 
        s = s->lc; //最靠左（最小）的节点
   } else { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
      while ( IsRChild ( *s ) ) 
        s = s->parent; //逆向地沿右向分支，不断朝左上方移动
      s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
   }
   return s;
}


template <typename T> template <typename VST> //元素类型、操作器
void BinNode <T>::travLevel(VST &visit)
{                            //二叉树层次遍历算法
    Queue<BinNodePosi<T>> Q; //辅助队列
    Q.enqueue(this);         //根节点入队
    while (!Q.empty())
    { //在队列再次变空之前，反复迭代
        BinNodePosi<T> x = Q.dequeue();
        visit(x->data); //取出队首节点并访问之
        if (HasLChild(*x))
            Q.enqueue(x->lc); //左孩子入队
        if (HasRChild(*x))
            Q.enqueue(x->rc); //右孩子入队
    }
}

// ====================== 子树先序遍历 ======================
template <typename T, typename VST> //元素类型、操作器
void travPre_R(BinNodePosi<T> x, VST &visit)
{ //二叉树先序遍历算法（递归版）
    if (!x) return;  //对退化情况处理
    visit(x->data); //取出根
    travPre_R(x->lc, visit); //以左孩子为根递归遍历
    travPre_R(x->rc, visit);
} // T(n) = O(1) +T(a) + T(n-a-1) = O(n) 

template <typename T, typename VST> //元素类型、操作器
void travPre_I1(BinNodePosi<T> x, VST &visit)
{                            //二叉树先序遍历算法（迭代版#1）
    Stack<BinNodePosi<T>> S; //辅助栈
    if (x)
        S.push(x); //根节点入栈
    while (!S.empty())
    { //在栈变空之前反复循环
        x = S.pop();
        visit(x->data); //弹出并访问当前节点，其非空孩子的入栈次序为先右后左
        if (HasRChild(*x))
            S.push(x->rc); //右孩子先入后出
        if (HasLChild(*x))
            S.push(x->lc); //左孩子后入先出
    }
} //体会以上两句的次序

//从当前节点出发，沿左分支不断深入，直至没有左分支的节点；沿途节点遇到后立即访问
template <typename T, typename VST> //元素类型、操作器
static void visitAlongVine(BinNodePosi<T> x, VST &visit, Stack<BinNodePosi<T>> &S)
{
    while (x)
    {
        visit(x->data); //访问当前节点
        S.push(x->rc);  //右孩子入栈暂存（可优化：通过判断，避免空的右孩子入栈）
        x = x->lc;      //沿左分支深入一层
    }
}
template <typename T, typename VST> //元素类型、操作器
void travPre_I2(BinNodePosi<T> x, VST &visit)
{                            //二叉树先序遍历算法（迭代版#2）
    Stack<BinNodePosi<T>> S; //辅助栈
    while (true)
    {
        visitAlongVine(x, visit, S); //从当前节点出发，逐批访问
        if (S.empty())
            break;   //直到栈空
        x = S.pop(); //弹出下一批的起点
    }
}
template <typename T> template <typename VST> //元素类型、操作器
void BinNode<T>::travPre ( VST& visit ) { //二叉树先序遍历算法统一入口
   switch ( rand() % 3 ) { //此处暂随机选择以做测试，共三种选择
      case 1: travPre_I1 ( this, visit ); break; //迭代版#1
      case 2: travPre_I2 ( this, visit ); break; //迭代版#2
      default: travPre_R ( this, visit ); break; //递归版
   }
}

// ====================== 子树中序遍历 ======================
template <typename T, typename VST> //元素类型、操作器
void travIn_R(BinNodePosi<T> x, VST &visit)
{ //二叉树中序遍历算法（递归版）
    if (!x)
        return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}

template <typename T> //从当前节点出发，沿左分支不断深入，直至没有左分支的节点
static void goAlongVine(BinNodePosi<T> x, Stack<BinNodePosi<T>> &S)
{
    while (x)
    {
        S.push(x);
        x = x->lc;
    } //当前节点入栈后随即向左侧分支深入，迭代直到无左孩子
}
template <typename T, typename VST> //元素类型、操作器
void travIn_I1(BinNodePosi<T> x, VST &visit)
{                            //二叉树中序遍历算法（迭代版#1）
    Stack<BinNodePosi<T>> S; //辅助栈
    while (true)
    {
        goAlongVine(x, S); //从当前节点出发，逐批入栈
        if (S.empty())
            break; //直至所有节点处理完毕
        x = S.pop(); //x的左子树或为空，或已遍历（等效于空），故可以
        visit(x->data); //弹出栈顶节点并访问之
        x = x->rc;      //转向右子树(可能为空)
    }
}

template <typename T, typename VST> //元素类型、操作器
void travIn_I2(BinNodePosi<T> x, VST &visit)
{                            //二叉树中序遍历算法（迭代版#2）
    Stack<BinNodePosi<T>> S; //辅助栈
    while (true)
        if (x)
        {
            S.push(x); //根节点进栈
            x = x->lc; //深入遍历左子树
        }
        else if (!S.empty())
        {
            x = S.pop();    //尚未访问的最低祖先节点退栈
            visit(x->data); //访问该祖先节点
            x = x->rc;      //遍历祖先的右子树
        }
        else
            break; //遍历完成
}

template <typename T, typename VST> //元素类型、操作器
void travIn_I3(BinNodePosi<T> x, VST &visit)
{                           //二叉树中序遍历算法（迭代版#3，无需辅助栈）
    bool backtrack = false; //前一步是否刚从左子树回溯——省去栈，仅O(1)辅助空间
    while (true)
        if (!backtrack && HasLChild(*x)) //若有左子树且不是刚刚回溯，则
            x = x->lc;                   //深入遍历左子树
        else
        {                   //否则——无左子树或刚刚回溯（相当于无左子树）
            visit(x->data); //访问该节点
            if (HasRChild(*x))
            {                      //若其右子树非空，则
                x = x->rc;         //深入右子树继续遍历
                backtrack = false; //并关闭回溯标志
            }
            else
            { //若右子树空，则
                if (!(x = x->succ()))
                    break;        //回溯（含抵达末节点时的退出返回）
                backtrack = true; //并设置回溯标志
            }
        }
}

template <typename T, typename VST> //元素类型、操作器
void travIn_I4(BinNodePosi<T> x, VST &visit)
{ //二叉树中序遍历（迭代版#4，无需栈或标志位）
    while (true)
        if (HasLChild(*x)) //若有左子树，则
            x = x->lc;     //深入遍历左子树
        else
        {                          //否则
            visit(x->data);        //访问当前节点，并
            while (!HasRChild(*x)) //不断地在无右分支处
                if (!(x = x->succ()))
                    return; //回溯至直接后继（在没有后继的末节点处，直接退出）
                else
                    visit(x->data); //访问新的当前节点
            x = x->rc;              //（直至有右分支处）转向非空的右子树
        }
}

template <typename T>
template <typename VST> //元素类型、操作器
void BinNode<T>::travIn(VST &visit)
{ //二叉树中序遍历算法统一入口
    switch (rand() % 5)
    { //此处暂随机选择以做测试，共五种选择
    case 1:
        travIn_I1(this, visit);
        break; //迭代版#1
    case 2:
        travIn_I2(this, visit);
        break; //迭代版#2
    case 3:
        travIn_I3(this, visit);
        break; //迭代版#3
    case 4:
        travIn_I4(this, visit);
        break; //迭代版#4
    default:
        travIn_R(this, visit);
        break; //递归版
    }
}

// ====================== 子树后序遍历 ======================
template <typename T, typename VST> //元素类型、操作器
void travPost_R(BinNodePosi<T> x, VST &visit)
{ //二叉树后序遍历算法（递归版）
    if (!x)
        return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}

template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
static void gotoLeftmostLeaf(Stack<BinNodePosi<T>> &S)
{                                      //沿途所遇节点依次入栈
    while (BinNodePosi<T> x = S.top()) //自顶而下，反复检查当前节点（即栈顶）
        if (HasLChild(*x))
        { //尽可能向左
            if (HasRChild(*x))
                S.push(x->rc); //若有右孩子，优先入栈
            S.push(x->lc);     //然后才转至左孩子
        }
        else               //实不得已
            S.push(x->rc); //才向右
    S.pop();               //返回之前，弹出栈顶的空节点
}
template <typename T, typename VST>
void travPost_I(BinNodePosi<T> x, VST &visit)
{                            //二叉树的后序遍历（迭代版）
    Stack<BinNodePosi<T>> S; //辅助栈
    if (x)
        S.push(x); //根节点入栈
    while (!S.empty())
    {                             // x始终为当前节点
        if (S.top() != x->parent) ////若栈顶非x之父（而为右兄）
            gotoLeftmostLeaf(S);  //则在其右兄子树中找到HLVFL（相当于递归深入）
        x = S.pop();
        visit(x->data); //弹出栈顶（即前一节点之后继），并访问之
    }
}

template <typename T>
template <typename VST> //元素类型、操作器
void BinNode<T>::travPost(VST &visit)
{ //二叉树后序遍历算法统一入口
    switch (rand() % 2)
    { //此处暂随机选择以做测试，共两种选择
    case 1:
        travPost_I(this, visit);
        break; //迭代版
    default:
        travPost_R(this, visit);
        break; //递归版
    }
}

/******************************************************************************************
 * BinTree模板类
 ******************************************************************************************/
template <typename T>
class BinTree
{ //二叉树模板类
    protected:
        int _size;
        BinNodePosi<T> _root;                       //规模、根节点
        virtual int updateHeight(BinNodePosi<T> x); //更新节点x的高度
        void updateHeightAbove(BinNodePosi<T> x);   //更新节点x及其祖先的高度
    public:
        BinTree() : _size(0), _root(NULL) {} //构造函数
        ~BinTree()
        {
            if (0 < _size)
                remove(_root);
        }                                                     //析构函数
        int size() const { return _size; }                    //规模
        bool empty() const { return !_root; }                 //判空
        BinNodePosi<T> root() const { return _root; }         //树根
        BinNodePosi<T> insert(T const &);                     //插入根节点
        BinNodePosi<T> insert(T const &, BinNodePosi<T>);     //插入左孩子
        BinNodePosi<T> insert(BinNodePosi<T>, T const &);     //插入右孩子
        BinNodePosi<T> attach(BinTree<T> *&, BinNodePosi<T>); //接入左子树
        BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T> *&); //接入右子树
        int remove(BinNodePosi<T>);                           //子树删除
        BinTree<T> *secede(BinNodePosi<T>);                   //子树分离
        template <typename VST>                               //操作器
        void travLevel(VST &visit){ if (_root) _root->travLevel(visit); }   //层次遍历
        template <typename VST>                               //操作器
        void travPre(VST &visit){ if (_root) _root->travPre(visit);}       //先序遍历
        template <typename VST>                               //操作器
        void travIn(VST &visit){ if (_root) _root->travIn(visit);}         //中序遍历
        template <typename VST>                               //操作器
        void travPost(VST &visit){ if (_root) _root->travPost(visit);}     //后序遍历
        bool operator<(BinTree<T> const &t)                   //比较器（其余自行补充）
        {
            return _root && t._root && lt(_root, t._root);
        }
        bool operator==(BinTree<T> const &t) //判等器
        {
            return _root && t._root && (_root == t._root);
        }
}; // BinTree

// ====================== 高度更新 ======================
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi<T> x) //更新节点x高度
{
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
} //具体规则，因树而异

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi<T> x) //更新高度
{
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
} //从x出发，覆盖历代祖先。可优化

// ====================== 插入 ======================
template <typename T>
BinNodePosi<T> BinTree<T>::insert(T const &e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
} //将e当作根节点插入空的二叉树
template <typename T>
BinNodePosi<T> BinTree<T>::insert(T const &e, BinNodePosi<T> x)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
} // e插入为x的左孩子
template <typename T>
BinNodePosi<T> BinTree<T>::insert(BinNodePosi<T> x, T const &e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
} // e插入为x的右孩子

// ====================== 接入 ======================
template <typename T> //将S当作节点x的左子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attach(BinTree<T> *&S, BinNodePosi<T> x)
{ // x->lc == NULL
    if (x->lc = S->_root)
        x->lc->parent = x; //接入
    _size += S->_size;
    updateHeightAbove(x); //更新全树规模与x所有祖先的高度
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x; //释放原树，返回接入位置
}
template <typename T> //将S当作节点x的右子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attach(BinNodePosi<T> x, BinTree<T> *&S)
{ // x->rc == NULL
    if (x->rc = S->_root)
        x->rc->parent = x; //接入
    _size += S->_size;
    updateHeightAbove(x); //更新全树规模与x所有祖先的高度
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x; //释放原树，返回接入位置
}

// ====================== 移除 ======================
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
int BinTree<T>::remove(BinNodePosi<T> x)
{                                 // assert: x为二叉树中的合法位置
    FromParentTo(*x) = NULL;      //切断来自父节点的指针
    updateHeightAbove(x->parent); //更新祖先高度
    int n = removeAt(x);
    _size -= n;
    return n; //删除子树x，更新规模，返回删除节点总数
}
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
static int removeAt(BinNodePosi<T> x)
{ // assert: x为二叉树中的合法位置
    if (!x)
        return 0;                                  //递归基：空树
    int n = 1 + removeAt(x->lc) + removeAt(x->rc); //递归释放左、右子树
    release(x->data);
    release(x);
    return n; //释放被摘除节点，并返回删除节点总数
} // release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包

// ====================== 子树分离 ======================
template <typename T> //二叉树子树分离算法：将子树x从当前树中摘除，将其封装为一棵独立子树返回
BinTree<T> *BinTree<T>::secede(BinNodePosi<T> x)
{                                 // assert: x为二叉树中的合法位置
    FromParentTo(*x) = NULL;      //切断来自父节点的指针
    updateHeightAbove(x->parent); //更新原树中所有祖先的高度
    BinTree<T> *S = new BinTree<T>;
    S->_root = x;
    x->parent = NULL; //新树以x为根
    S->_size = x->size();
    _size -= S->_size;
    return S; //更新规模，返回分离出来的子树
}
/*
// ====================== 统计二叉树子树规模 ======================
template <typename T>                  //统计二叉树子树规模
int BinTree<T>::size(BinNodePosi<T> x) // assert: x为二叉树中的合法位置
{
    return x ? size(x->lc) + size(x->RChild) : 0;
}
*/