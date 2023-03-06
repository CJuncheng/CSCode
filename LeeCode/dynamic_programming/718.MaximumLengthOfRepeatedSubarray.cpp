#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 动态规划
 * dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]。 
 * （特别注意： “以下标i - 1为结尾的A” 标明一定是 以A[i-1]为结尾的字符串 ）
 *  dp[i][0] 和 dp[0][j]其实都是没有意义的！均为0
 *
 *
 */

int findLength(vector<int>& nums1, vector<int>& nums2) {
    const int lenA = nums1.size(), lenB = nums2.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    int res = 0;
    for(int i = 1; i <= lenA; ++i) {
        for(int j = 1; j <= lenB; ++j){
            if(nums1[i-1] == nums2[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            if(dp[i][j] > res) res = dp[i][j];
        }
    }
    return res;
}


int main (int argc, char* argv[])
{
    vector<int> iVec1 = {1,2,3,2,1};
    vector<int> iVec2 = {3,2,1,4,7};
    int ret = findLength(iVec1, iVec2);
    cout << "Result: " << ret << endl;
    
    return 0;
}