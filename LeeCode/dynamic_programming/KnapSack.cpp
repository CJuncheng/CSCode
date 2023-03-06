#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> knapSack(void)
{
    int wKnapSack = 5; // 背包载重 5
    vector<int> weight = {1, 2, 3, 4}, value = {3, 4, 5, 6}; // 物品
    const int len = weight.size();
    vector<vector<int>> dp(len, vector<int>(wKnapSack+1, 0));
    
    for(int j = weight[0]; j <= wKnapSack; ++j) dp[0][j] = value[0];  //初始化
    for(int i = 1; i < len; ++i)
        for(int j = 0; j <= wKnapSack; ++j) {
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    return dp;
}

int knapSack1(void)
{
    int wKnapSack = 5; // 背包载重 5
    vector<int> weight = {1, 2, 3, 4}, value = {3, 4, 5, 6}; // 物品
    const int len = weight.size();
    vector<int> dp(wKnapSack+1, 0);
    
    for(int i = 0; i < len; ++i)
        for(int j = wKnapSack; j >= weight[i]; --j) 
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    return dp[wKnapSack];
}

int main (int argc, char* argv[])
{  
    vector<vector<int>>  ret = knapSack();
    cout << "Result: "  << endl;
    for(auto it = ret.begin(); it != ret.end(); ++it) {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    }

    knapSack1();
    return 0;
}