/*
一个n*m的棋盘，'X'表示有棋子，'.'表示没有棋子，统计四个棋子：(x1,y1),(x2,y2),(x3,y3),(x4,y4)之间围成的形状是正方形的数目。
只要有一颗棋子坐标不同，则是不同的组合。

根据数学知识若知道正方形的两个点，则可以确定另外两个点，已知A(x1,y1),B(x2,y2)，不妨正方形由假设AB顺时针旋转得到，则可以知道：

x3 = x1 - (y1 - y2), y3 = y1 + (x1 - x2), x4 = x2 - (y1 - y2), y4 = y2 + (x1 - x2)。
*/


#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> points;
    set<pair<int, int>> st;
    char tmp;
    for(int i = 0 ; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> tmp;
            if(tmp == 'X'){
                points.emplace_back(i, j);
                st.insert(i, j);
            }
        }
    const int len = points.size();
    int cnt = 0;
    for(int i = 0; i < len; ++i)
        for(int j = i+1; j < len; ++j){
            int x1 = points[i].first, y1 = points[i].second, 
                x2 = points[j].first, y2 = points[j].second;
            int x3 = x1 - (y1-y2), y3  = y1 + (x1-x2), x4 = x2 - (y1-y2), y4 = y2 - (x1-x2);
            if(st.count({x3, y3}) && st.count({x4, y4})){
                ++cnt;
            }
        }

    cout << cnt << endl;
    
    return 0;
}