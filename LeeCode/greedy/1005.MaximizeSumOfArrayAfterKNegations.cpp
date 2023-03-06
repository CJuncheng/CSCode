#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(int a, int b)
{
    return abs(a) > abs(b);
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    const int len = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end(), compare); // 按绝对值由大到小排序
    cout << nums[1] << endl;
    for(int i = 0; i < len; ++i) {
        if(nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            --k;
        }   
    }
    if(k&0x1)  nums[len -1] = -nums[len -1];                // k为奇数
    for(int & val : nums) res += val;
    return res;
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {2,-3,-1,5,-4};
    int ret = largestSumAfterKNegations(iVec, 2);
    cout << "Result: " << ret << endl;
    
    return 0;
}