#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/* dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
 * 
 *
 */

int numDistinct(string s, string t) 
{
    const int lenS = s.size(), lenT = t.size();
    vector<vector<uint64_t>> dp(lenS+1, vector<uint64_t>(lenT+1));
    for(int i = 0; i <= lenS; ++i) dp[i][0] = 1;
    //for(int j = 1; j <= lenT; ++j) dp[0][j] = 0;
    for(int i = 1; i <= lenS; ++i) 
        for(int j = 1; j <= lenT; ++j){
            /* 用 s[i-1] 匹配 t[j-1]，dp[i-1][j-1]
             * 不用 s[i-1] 匹配 t[j-1]， 删掉 s[i-1]， 即dp[i-2][j-1] --> dp[i-1][j]
             */
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
            else dp[i][j] = dp[i-1][j]; 
        }
    return dp[lenS][lenT];
}

int main (int argc, char* argv[])
{ 
    string str1 = "babgbag", str2 = "bag";
    int ret = numDistinct(str1, str2);
    cout << "Result: " << ret << endl;
    return 0;
}