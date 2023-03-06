/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * March 30, 2022
 ******************************************************************************************/
#pragma once
#include <cstdlib>

using Rank = size_t; //秩
using int32 = int;
#define DEFAULT_CAPACITY 3 //默认的初始容量（实际应用中可设置为更大）

template <typename T>
class Vector 
{
    protected:
        Rank size_; int32 capacity_; T* elem_; //规模、 容量、 数据区
        void copyFrom (T const * A, Rank lo, Rank hi); //复制数组区间 A[lo, hi)
        void expand(void);                                  //空间不足时扩容
        void shrink(void);                                 //装填因子过小时压缩
    public:
        //构造函数
        Vector(int32 c = DEFAULT_CAPACITY, int32 s = 0, T v = 0) //容量为c、规模为s、所有元素初始为v
        {
            elem_ = new T[capacity_ = c];
            for (size_ = 0; size_ < s; elem_[size_++] = v);
        }
        Vector (T const* A, Rank n) { copyFrom(A, 0, n);} //数组整体复制
        Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //数组区间复制
        Vector (Vector<T> const & V){ copyFrom(V.elem_, 0, V.size_);} //向量整体复制
        Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V.elem_, lo, hi); } //向量整体复制
        //析构函数
        ~Vector(){ delete [] elem_; }
        //只读访问接口
        Rank size(void) const {return size_;} //规模
        Rank empty(void) const { return !size_; } //判空

        //可写访问接口
        T &operator[](Rank r);                   //重载下标操作符，可以类似于数组形式引用各元素
        const T &operator[](Rank r) const;       //仅限于做右值的重载版本
        Vector<T> &operator=(Vector<T> const &); //重载赋值操作符，以便直接克隆向量
        T remove(Rank r);                        //删除秩为r的元素
        int remove(Rank lo, Rank hi);            //删除秩在区间[lo, hi)之内的元素
        Rank insert(Rank r, T const &e);         //插入元素
        Rank insert(T const &e) { return insert(size_, e); } //默认作为末元素插入
};

template <typename T> // T为基本类型，或已重载赋值操作符'='
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{                                             //以数组区间A[lo, hi)为蓝本复制向量
    elem_ = new T[capacity_ = 2 * (hi - lo)]; //分配空间
    for (size_ = 0; lo < hi; size_++, lo++)   // A[lo, hi)内的元素逐一
        elem_[size_] = A[lo];                 //复制至elem_[0, hi - lo)
} //用const修饰，保证A中的元素不致被篡改；运行时间 = O(hi-lo)

template <typename T>
void Vector<T>::expand(void)
{    //向量空间不足时扩容
    if (size_ < capacity_)
        return; //尚未满员时，不必扩容
    if (capacity_ < DEFAULT_CAPACITY)
        capacity_ = DEFAULT_CAPACITY; //不低于最小容量
    T *oldElem = elem_;
    elem_ = new T[capacity_ <<= 1]; //容量加倍
    for (int i = 0; i < size_; i++)
        elem_[i] = oldElem[i]; //复制原向量内容（T为基本类型，或已重载赋值操作符'='）
    /*DSA*/                    // printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n", oldElem, _size, _capacity/2, _elem, _size, _capacity);
    delete[] oldElem;          //释放原空间
}

template <typename T>
void Vector<T>::shrink(void)
{ //装填因子过小时压缩向量所占空间
    if (capacity_ < DEFAULT_CAPACITY << 1)
        return; //不致收缩到DEFAULT_CAPACITY以下
    if (size_ << 2 > capacity_)
        return; //以25%为界
    T *oldElem = elem_;
    elem_ = new T[capacity_ >>= 1]; //容量减半
    for (int i = 0; i < size_; i++)
        elem_[i] = oldElem[i]; //复制原向量内容
    delete[] oldElem;          //释放原空间
}

template <typename T>
T &Vector<T>::operator[](Rank r) //重载下标操作符
{
    return elem_[r];
} // assert: 0 <= r < _size

template <typename T>
const T &Vector<T>::operator[](Rank r) const //仅限于做右值
{
    return elem_[r];
} // assert: 0 <= r < _size

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{ //深复制
    if (elem_)
        delete[] elem_;             //释放原有内容
    copyFrom(V.elem_, 0, V.size()); //整体复制
    return *this;                   //返回当前对象的引用，以便链式赋值
}

template <typename T>
T Vector<T>::remove(Rank r)
{                     //删除向量中秩为r的元素，0 <= r < size
    T e = elem_[r];   //备份被删除元素
    remove(r, r + 1); //调用区间删除算法，等效于对区间[r, r + 1)的删除
    return e;         //返回被删除元素
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{ //删除区间[lo, hi)
    if (lo == hi)
        return 0;                  //出于效率考虑，单独处理退化情况，比如remove(0, 0)
    while (hi < size_)             //区间[hi, _size)
        elem_[lo++] = elem_[hi++]; //顺次前移hi - lo个单元
    size_ = lo;                    //更新规模，直接丢弃尾部[lo, _size = hi)区间
    shrink();                      //若有必要，则缩容
    return hi - lo;                //返回被删除元素的数目
}

template <typename T> //将e作为秩为r元素插入
Rank Vector<T>::insert(Rank r, T const &e)
{                                   // assert: 0 <= r <= size
    expand();                       //若有必要，扩容
    for (int i = size_; i > r; i--) //自后向前，后继元素
        elem_[i] = elem_[i - 1];    //顺次后移一个单元
    elem_[r] = e;
    size_++;  //置入新元素并更新容量
    return r; //返回秩
}
