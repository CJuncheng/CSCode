/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * April 27, 2022
 ******************************************************************************************/
#pragma once

#include <typeinfo>
#include <cstdlib>
#include <ctime> //通常用当前时刻设置随机种子


template <typename T>
struct Double //函数对象：倍增一个T类对象
{
    virtual void operator()(T &e) { e *= 2; }
}; //假设T可直接倍增

template <typename T>
struct Increase //函数对象：递增一个T类对象
{
    virtual void operator()(T &e) { e++; }
}; //假设T可直接递增或已重载++


template <typename T>
struct Cleaner
{
    static void clean(T x)
    { //相当于递归基
#ifdef _DEBUG
        static int n = 0;
        if (7 > strlen(typeid(T).name()))
        { //复杂类型一概忽略，只输出基本类型
            printf("\t<%s>[%d]=", typeid(T).name(), ++n);
            print(x);
            printf(" purged\n");
        }
#endif
    }
};
template <typename T>
struct Cleaner<T *>
{
    static void clean(T *x)
    {
        if (x)
        {
            delete x;
        } //如果其中包含指针，递归释放
#ifdef _DEBUG
        static int n = 0;
        printf("\t<%s>[%d] released\n", typeid(T *).name(), ++n);
#endif
    }
};
template <typename T>
void release(T x) { Cleaner<T>::clean(x); }

template <typename T>
struct Hailstone
{ //函数对象：按照Hailstone规则转化一个T类对象
    virtual void operator()(T &e)
    {                 //假设T可直接做算术运算
        int step = 0; //转换所需步数
        while (1 != e)
        { //按奇、偶逐步转换，直至为1
            (e % 2) ? e = 3 *e + 1 : e /= 2;
            step++;
        }
        e = step; //返回转换所经步数
    }
};

/******************************************************************************************
 * 在[0, range)内随机生成一个数
 ******************************************************************************************/
static int dice(int range) { return rand() % range; }               //取[0, range)中的随机整数
static int dice(int lo, int hi) { return lo + rand() % (hi - lo); } //取[lo, hi)中的随机整数
static float dice(float range) { return rand() % (1000 * (int)range) / (float)1000.; }
static double dice(double range) { return rand() % (1000 * (int)range) / (double)1000.; }
static char dice() { return (char)(32 + rand() % 96); }