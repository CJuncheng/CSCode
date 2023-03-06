/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * April 9, 2022
 ******************************************************************************************/
#pragma once

#include "list.h"
template <typename T>
class Queue : public List<T>  // 队列模板类（继承list原有接口）
{
    public: // size(), empty()以及其他开放接口，均可直接沿用
        void enqueue(T const &e) { List<T>::insertAsLast(e); }    // 入队：尾部插入
        T dequeue() { return List<T>::remove(List<T>::first()); } // 出队：首部删除
        T &front() { return List<T>::first()->data; }    // 队首
};

// ====================== 队列的应用 ======================
// 银行服务模型
struct Customer
{                      //顾客类：
    int window;        //所属窗口（队列）
    unsigned int time; //需要的服务时长
    int id;
};

int bestWindow(Queue<Customer> windows[], int nWin)
{                                                 //为新到顾客确定最佳队列
    int minSize = windows[0].size(), optiWin = 0; //最优队列（窗口）
    for (int i = 1; i < nWin; i++)
        if (minSize > windows[i].size())
        { //挑选出队列最短者
            minSize = windows[i].size();
            optiWin = i;
        }

    return optiWin;
}

//模拟在银行中接受服务的过程
void simulate(int nWin, int servTime)
{                                                         //按指定窗口数，服务总时间模拟银行业务
    Queue<Customer> *windows = new Queue<Customer>[nWin]; //为每一窗口创建一个队列

    for (int now = 0; now < servTime; now++)
    { //在下班前，每隔一个单位时间
        if (rand() % (1 + nWin))
        { //新顾客以 nWin/(nWin+1) 的概率到达
            Customer c;
            c.id = now;
            c.time = 1 + rand() % 98;             //新顾客到达，服务时长随机确定
            c.window = bestWindow(windows, nWin); //找出最佳（最短）的服务窗口
            windows[c.window].enqueue(c);         //新顾客入对应的队列
            cout << "Customer " << c.id << " enters Queue " << c.window << endl;
        }

        for (int i = 0; i < nWin; i++) //分别检查
            if (!windows[i].empty())   //各非空队列
                if (--windows[i].front().time <= 0)
                {                                      // 队首顾客的服务时长减少一个单位
                    Customer c = windows[i].dequeue(); //服务完毕的顾客出列，由后继顾客接替
                    cout << "Customer " << c.id << " leaves Queue " << c.window << endl;
                }
    } // for

    for (int i = 0; i < nWin; i++)
    {
        cout << "Queue " << i + 1 << " Size:" << windows[i].size() << endl;
    }

    delete[] windows;
}