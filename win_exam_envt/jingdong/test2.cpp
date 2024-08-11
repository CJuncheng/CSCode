/*
小红有一个数组,她需要对效组操作n-1次,每次操作有两种选择:
1：选择数组的最后两个数,记x,y,将它们从数组中删除,然后将x＋y的个位数放到数组最后
2：选择数组的最后两个数,记x,y,将它们从数组中删除,然后将x*y的个位数放到数组最后
操作n-1步之后就剩一个数字，从0到9都有可能，
输出0-9可能的方案数

思路：动态规划，设计二维dp[i][j]表示第i次操作后，个位数为j的方案数，i从1到n，j取值0-9

理解题意相当于每次操作0-9的方案总数会*2

根据两种操作，动态规划递推式为
                int op1 = (j + nums[n-i-1]) % 10;
                int op2 = (j * nums[n-i-1]) % 10;
                dp[i][op1] += dp[i-1][j] ;
                dp[i][op2] += dp[i-1][j] ;

*/

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

void solution(vector<int>& nums){
    const int n =  nums.size();
    vector<vector<int>> dp(n, vector<int>(10)); // i 代表第 i 次操作[0, n-1], 0-9 数字
    for(int j = 0; j < 10; ++j)
        dp[0][j] = nums[n-1] == j ? 1 : 0;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < 10; ++j){
            int op1 = (j + nums[n-1-i]) % 10;
            int op2 = (j * nums[n-1-i]) % 10;
            dp[i][op1] += dp[i-1][j] % MOD;
            dp[i][op2] += dp[i-1][j] % MOD;
        }
    for(int j = 0; j < 10; ++j)
        cout << dp[n-1][j] << " ";
    cout << endl;
}

int main() {
  
    vector<int> nums = {1, 2, 3, 4};
    solution(nums);
    
    

    return 0;
}