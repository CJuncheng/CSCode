
#include <vector>
#include <iostream>

int prim(const std::vector<std::vector<int>>& adjMat)
{
    const int n = adjMat.size();
    int sumLowCost = 0;
    std::vector<int> lowcost(n, INT_MAX); // -1 代表加入最小生成树
    int start = 0; // 可以设置任意起点
    lowcost[start] = -1;
    for(int i = 0; i < n; ++i){ // 初始化lowcost[]
        if(i==start) continue;
        lowcost[i] = adjMat[i][start];
    }
    for(int i = 1; i < n; ++i){
        int minIdx = -1, minVal = INT_MAX; // 找到离已有的最小生成树最近的点
        for(int j = 0; j < n; ++j)
            if(lowcost[j]!=-1&&lowcost[j]<minVal){
                minVal = lowcost[j];
                minIdx = j;
            }
        sumLowCost += minVal;
        lowcost[minIdx] = -1;
        for(int j = 0; j < n; ++j)
            if(lowcost[j]!=-1 && adjMat[j][minIdx] < lowcost[j])
                lowcost[j] = adjMat[j][minIdx]; //更新lowcost[]
    }
    return sumLowCost;
}