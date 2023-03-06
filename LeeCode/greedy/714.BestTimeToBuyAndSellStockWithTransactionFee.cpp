#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 贪心
int maxProfit(vector<int>& prices, int fee) {
    int profit = 0;
    const int len = prices.size();
    if(len < 2) return profit;
    int minPrice = prices[0];
    for(int i = 1; i < len; ++i) {
        if(minPrice > prices[i]) minPrice = prices[i];
        //if(prices[i]>=minPrice&&prices[i]<=minPrice+fee) continue;
        if(prices[i]>minPrice+fee) { //盈利
           profit += prices[i] - minPrice - fee;
           minPrice = prices[i] - fee; // 实际卖出，更新 minPrice;
        }
    }
    return profit;
}

// 动态规划
int main (int argc, char* argv[])
{
   
    vector<int> iVec = {1, 3, 2, 8, 4, 9};
    int ret = maxProfit(iVec, 2);
    cout << "Result: " << ret << endl;
    
    return 0;
}