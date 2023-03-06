#include <iostream>
#include <vector>
using namespace std;


int findMin(vector<int>& nums) {
    const int len = nums.size();
    if(len==1) return nums[0];
    int i = 1;
    while(i<len&&nums[i-1] < nums[i]) ++i;
    return i == len ? nums[0] : nums[i];
}

int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size()-1;
    while(lo <= hi) {
        if(nums[lo]<=nums[hi]) return nums[lo];
        int mid = lo + ((hi-lo)>>1);
        nums[lo] <= nums[mid] ? lo = mid+1 : hi = mid;
    }
    return -1;   
}
