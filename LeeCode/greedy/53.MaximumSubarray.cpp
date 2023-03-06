#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力法, 超时
/*
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    const int len = nums.size();
    for(int i = 0; i < len; ++i) {
        int sum = 0;
        for(int j = i; j < len; ++j){
            sum += nums[j];
            maxSum = sum > maxSum ? sum : maxSum;
        }
    }
    return maxSum;
}
*/
// 贪心算法
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    const int len = nums.size();
    for(int i = 0; i < len; ++i) {
        sum += nums[i];
        if(sum > maxSum) maxSum = sum;
        if(sum<=0) sum = 0; 
    }
    return maxSum;
}

int main (int argc, char* argv[])
{
    vector<int> iVec = {-2,-1};
    int ret = maxSubArray(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}