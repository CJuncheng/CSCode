#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 递归, 超时
int climbStairs(int n)
{
    if(n <=2 ) return n;
    return climbStairs(n-1) + climbStairs(n-2);
}

// dp table
int climbStairs(int n)
{
    //if(n <=2 ) return n;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    //dp[2] = 2;
    for(int i = 2; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// dp 压缩状态
int climbStairs(int n)
{
    //if(n <=2 ) return n;
    int prev = 1;
    int cur = 1;
    for(int i = 2; i <= n; ++i) {
        int tmp = cur + prev;
        prev = cur;
        cur = tmp;
    }
    return cur;     
}


int main (int argc, char* argv[])
{
    int ret = climbStairs(4);
    cout << "Result: " << ret << endl;
    
    return 0;
}