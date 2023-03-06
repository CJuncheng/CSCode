#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 中心扩展法
 * 以一个字符为中心 len 个， 以两个字符为中心 len-1 个， 一共 2*len-1 个
 * 以中心向两边扩展计算回文子串个数
 */
/*
int countSubstrings(string s) {
    const int len = s.size();
    int res = 0;
    for(int i = 0; i < 2*len -1; ++i){ // i代表第几个中心
        // right = left,以一个字符为中心
        // right = left +1, 以两个字符为中心
        int left = i/2;
        int right = left + i%2;
        while(left>=0&&right<len&&s[left]==s[right]){
            --left; ++right; ++res;
        }
    }
    return res;
}
*/
/* 动态规划法
 * 布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
 * dp[i][j] 用到 dp[i+1][j-1] 所以一定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
 * j一定是大于等于i的
 */
int countSubstrings(string s) {
    const int len = s.size();
    int res = 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for(int i = len-1; i>=0; --i) // 从下到上
        for(int j = i; j<len; ++j){ // 从左到右
            // if(s[i] != s[j]) dp[i][j] = false; 省略
            /* 可以简化
            if(s[i] = s[j]) {
                if(j-i<=1) {
                    dp[i][j] = true; ++res; 情况一， 二
                } else if(dp[i+1] = s[j-1]) {
                    dp[i][j] = true; ++res; 情况三
                }
            }
            */ 
           if(s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                dp[i][j] = true; ++res;
           }
        }
    return res;
}


int main (int argc, char* argv[])
{
    string str =  "abc";
    int ret = countSubstrings(str);
    cout << "Result: " << ret << endl;
    
    return 0;
}