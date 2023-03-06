#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

// 排序+双指针
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    const int len = nums.size();
    for(int i = 2; i < len; ++i){
        for(int j = i - 1, k = 0; k < j; --j){
            while(k<j&&nums[k]+nums[j]<=nums[i]) ++k;
            res+=j-k; 
        }
    }
    return res;
}

// 排序+二分
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    const int len = nums.size();
    for(int i = 2; i < len; ++i){
        for(int j = i - 1; j>0; --j){
            int lo = 0, hi = j-1;
            while(lo<hi){
                int mid = lo + ((hi-lo)>>1);
                nums[mid] + nums[j] > nums[i] ? hi = mid : lo = mid + 1;
            }
            if(nums[lo] + nums[j] > nums[i]) res+=j-lo;
        }
    }
    return res;
}
int main(int argc, char* argv[])
{
    vector<int> nums = {2,2,3,4};
    int ret = triangleNumber(nums);
    cout << ret << endl;
}