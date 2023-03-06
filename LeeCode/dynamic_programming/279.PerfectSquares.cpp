#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/* 数学定理方法
 * 1.任何正整数都可以拆分成不超过4个数的平方和 ---> 答案只可能是1,2,3,4
 * 2.如果一个数最少可以拆成4个数的平方和，则这个数还满足 n = (4^a)*(8b+7) ---> 因此可以先看这个数是否满足上述公式，如果不满足，答案就是1,2,3了
 * 3.如果这个数本来就是某个数的平方，那么答案就是1，否则答案就只剩2,3了
 * 4.如果答案是2，即n=a^2+b^2，那么我们可以枚举a，来验证，如果验证通过则答案是2
 * 只能是3

*/
int numSquares(int n) {
    while(n%4==0) n/=4;
    if(n%8 == 7) return 4;

    if(pow((int)sqrt(n), 2) == n) return 1;

    /*
    for(int i = 0; i*i < n; ++i)
        for(int j = 0; j*j < n; ++j)
            if(n- i*i-j*j ==0) return 2;
    */
    for(int a = 1; a <= n/a; ++a) {
        int b = (int)sqrt(n - pow(a, 2));
        if(pow(a, 2) + pow(b, 2) == n) return 2;
    }
    return 3;
}

/* 完全背包方法， 数学定理方法更高效
 * dp[j]：和为j的完全平方数的最少数量为dp[j]
 * dp[j] = min(dp[j - i * i] + 1, dp[j])
*/
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i * i <= n; ++i) // 遍历物品
        for(int j = i*i; j <= n; ++j) // 遍历背包
            dp[j] = min(dp[j], dp[j-i*i] +1);
    return dp[n];
}