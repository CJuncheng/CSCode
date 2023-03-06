#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 没有太理解
class Solution {
private:
    const int INF = 0x3f3f3f3f;
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int n = boxes.size();
        deque<int> deq;
        vector<int> sum(n+2, 0);
        for(int i = 2; i<=n; ++i)
            if(boxes[i-1][0]==boxes[i-2][0]) sum[i] = sum[i-1];
            else sum[i]=sum[i-1]+1;
        sum[n+1] = sum[n];
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        vector<long> prefix(n+1, 0);
        deq.push_back(0);
        for(int i=1;i<=n;++i){
            prefix[i] = prefix[i-1] + boxes[i-1][1];
            while(deq.size() && (deq.front()+maxBoxes < i || prefix[deq.front()]+maxWeight<prefix[i])) deq.pop_front();
            dp[i] = min(dp[i],dp[deq.front()] - sum[deq.front()+1] + sum[i] + 2);
            // 最小值 维护一个单调递增队列  注意这里维护的是f[i]-sum[i+1] 这是由问题具体含义而定
            while(deq.size() && dp[deq.back()] - sum[deq.back()+1] >= dp[i] - sum[i+1]) deq.pop_back();
            deq.push_back(i);
        }
        return dp[n];
    }
};