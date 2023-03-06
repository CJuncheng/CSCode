#include <iostream>
#include <vector>

using namespace std;

// 递归
int fib(int n) {
    if(n < 2) return n;
    return fib(n-1) + fib(n-2);
}

/*
// dp table
int fib(int n) {
    if(n < 2) return n;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
*/

// dp 状态压缩
int fib(int n) {
    if(n < 2) return n;
    int cur = 1, prev = 0;
    for(int i = 2; i <= n; ++i) {
        int tmp = cur + prev;
        prev = cur;
        cur = tmp;
    } 
    return cur;     
}

int main (int argc, char* argv[])
{
    int ret = fib(4);
    cout << "Result: " << ret << endl;
    
    return 0;
}