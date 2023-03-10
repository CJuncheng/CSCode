/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * June 20, 2022
 ******************************************************************************************/
#pragma once

#include "bin_tree.h"

/******************************************************************************************
 * 由BinTree派生BST模板类
 ******************************************************************************************/
template <typename T>
class BinSearchTree : public BinTree<T> 
{
protected:
    BinNodePosi<T> _hot;                 //“命中”节点的父亲
    BinNodePosi<T> connect34(            //按照“3 + 4”结构，联接3个节点及四棵子树
        BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
        BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>);
    BinNodePosi<T> rotateAt(BinNodePosi<T> x); //对x及其父亲、祖父做统一旋转调整
public:                                        //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
    virtual BinNodePosi<T> &search(const T &e); //查找
    //virtual BinNodePosi<T> &search_R(const T &e); //查找
    virtual BinNodePosi<T> insert(const T &e);  //插入
    virtual bool remove(const T &e);            //删除
    virtual bool remove_t(const T &e);            //删除
};

/******************************************************************************************
 * 按照“3 + 4”结构联接3个节点及其四棵子树，返回重组之后的局部子树根节点位置（即b）
 * 子树根节点与上层节点之间的双向联接，均须由上层调用者完成
 * 可用于AVL和RedBlack的局部平衡调整
 ******************************************************************************************/
template <typename T>
BinNodePosi<T> BinSearchTree<T>::connect34(
    BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
    BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3)
{
    //*DSA*/print(a); print(b); print(c); printf("\n");
    a->lc = T0;
    if (T0)
        T0->parent = a;
    a->rc = T1;
    if (T1)
        T1->parent = a;
    updateHeight(a);
    c->lc = T2;
    if (T2)
        T2->parent = c;
    c->rc = T3;
    if (T3)
        T3->parent = c;
    updateHeight(c);
    b->lc = a;
    a->parent = b;
    b->rc = c;
    c->parent = b;
    updateHeight(b);
    return b; //该子树新的根节点
}

/******************************************************************************************
 * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
 * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
 ******************************************************************************************/
template <typename T>
BinNodePosi<T> BinSearchTree<T>::rotateAt(BinNodePosi<T> v)
{ // v为非空孙辈节点
    /*DSA*/ if (!v)
    {
        printf("\a\nFail to rotate a null node\n");
        exit(-1);
    }
    BinNodePosi<T> p = v->parent;
    BinNodePosi<T> g = p->parent; //视v、p和g相对位置分四种情况
    if (IsLChild(*p))             /* zig */
        if (IsLChild(*v))
        { /* zig-zig */            //*DSA*/printf("\tzIg-zIg: ");
            p->parent = g->parent; //向上联接
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else
        { /* zig-zag */            //*DSA*/printf("\tzIg-zAg: ");
            v->parent = g->parent; //向上联接
            return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    else /* zag */
        if (IsRChild(*v))
        { /* zag-zag */            //*DSA*/printf("\tzAg-zAg: ");
            p->parent = g->parent; //向上联接
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }
        else
        { /* zag-zig */            //*DSA*/printf("\tzAg-zIg: ");
            v->parent = g->parent; //向上联接
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
}

// ====================== BST查找（迭代版本） ======================
template <typename T>
BinNodePosi<T> &BinSearchTree<T>::search(const T &e)
{ //在BST中查找关键码e
    if (!BinTree<T>::_root || e == BinTree<T>::_root->data)
    {
        _hot = NULL;
        return BinTree<T>::_root;
    } //空树，或恰在树根命中
    for (_hot = BinTree<T>::_root;;)
    {                                                               //否则，自顶而下
        BinNodePosi<T> &v = (e < _hot->data) ? _hot->lc : _hot->rc; //确定方向，深入一层
        if (!v || e == v->data)
            return v;
        _hot = v; //一旦命中或抵达叶子，随即返回
    }             //返回目标节点位置的引用，以便后续插入、删除操作
} //无论命中或失败，_hot均指向v之父亲（v是根时，hot为NULL
/*
// ====================== BST查找（递归版本） ======================
template <typename T>
BinNodePosi<T> &BinSearchTree<T>::search_R(const T &e)
{
    return searchIn(BinTree<T>::_root, e, _hot=NULL);
} 
static BinNodePosi<T> & searchIn(BinNodePosi<T> &v, const T &e, BinNodePosi<T> &hot)
{
    if(!v||(e == v->data)) return v; //足以确保成功
    hot = v; //先记下挡墙（非空）节点，然后再...
    return searchIn( (e < v->data ? v->lc : v->rc), e, hot);
} //运行时间正比于返回节点V的深度，不超过树的高度O(h)

*/
template <typename T>
BinNodePosi<T> BinSearchTree<T>::insert(const T &e)
{ //将关键码e插入BST树中
    BinNodePosi<T> &x = search(e);
    if (x)                       //如有雷同元素，返回x
        return x;                //确认目标不存在（留意对_hot的设置）
    x = new BinNode<T>(e, _hot); //创建新节点x：以e为关键码，以_hot为父
    BinTree<T>::_size++;         //更新全树规模
    updateHeightAbove(x);        //更新x及其历代祖先的高度
    return x;                    //新插入的节点，必为叶子
} //无论e是否存在于原树中，返回时总有x->data == e


/******************************************************************************************
 * BST节点删除算法：删除位置x所指的节点（全局静态模板函数，适用于AVL、Splay、RedBlack等各种BST）
 * 目标x在此前经查找定位，并确认非NULL，故必删除成功；与searchIn不同，调用之前不必将hot置空
 * 返回值指向实际被删除节点的接替者，hot指向实际被删除节点的父亲——二者均有可能是NULL
 ******************************************************************************************/
template <typename T>
BinNodePosi<T> removeAt ( BinNodePosi<T> & x, BinNodePosi<T> & hot ) {
   BinNodePosi<T> w = x; //实际被摘除的节点，初值同x
   BinNodePosi<T> succ = NULL; //实际被删除节点的接替者
   if ( !HasLChild ( *x ) ) //若*x的左子树为空，则可
      succ = x = x->rc; //直接将*x替换为其右子树, 这里可以删除中间的x
   else if ( !HasRChild ( *x ) ) //若右子树为空，则可
      succ = x = x->lc; //对称地处理——注意：此时succ != NULL
   else { //若左右子树均存在，则选择x的直接后继作为实际被摘除节点，为此需要
      w = w->succ(); //（在右子树中）找到*x的直接后继*w
      swap ( x->data, w->data ); //交换*x和*w的数据元素
      BinNodePosi<T> u = w->parent; 
      ( ( u == x ) ? u->rc : u->lc ) = succ = w->rc; //隔离节点*w
   }
   hot = w->parent; //记录实际被删除节点的父亲
   if ( succ ) succ->parent = hot; //并将被删除节点的接替者与hot相联
   release ( w->data ); release ( w ); return succ; //释放被摘除节点，返回接替者
} //r

template <typename T>
bool BinSearchTree<T>::remove(const T &e)
{ //从BST树中删除关键码e
    BinNodePosi<T> &x = search(e);
    if (!x)
        return false; //确认目标存在（留意_hot的设置）
    removeAt(x, _hot);
    BinTree<T>::_size--;     //更新全树高度
    updateHeightAbove(_hot); //更新_hot及其历代祖先的高度
    return true;
} //删除成功与否，由返回值指示


template <typename T>
static BinNodePosi<T> removeAt_t(BinNodePosi<T> &x, BinNodePosi<T> & hot)
{   
    BinNodePosi<T> w = x;
    BinNodePosi<T> succ = NULL;
    if(!HasLChild(*x))
        succ = x->rc;
    else if(!HasRChild(*x))
        succ = x->lc;
    else {
        w = w->succ();
        swap(x->data, w->data);
        BinNodePosi<T> u = w->parent;
        ((u==x) ? u->rc : u->lc) = succ = w->rc;
    }
    hot = w->parent;
    if (succ) succ->parent = hot;
    release(w->data); release(w); return succ;

}

template <typename T>
bool BinSearchTree<T>::remove_t(const T &e)
{
    BinNodePosi<T> &x = search(e);
    if(!x)
        return false;
    removeAt_t(x, _hot);
    BinTree<T>::_size--;
    updateHeightAbove(_hot);
    return true;
}