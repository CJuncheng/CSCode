#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size()-1;
    while(lo<hi){
        int mid = lo + ((hi-lo)>>1);
        nums[mid] > nums[mid+1] ? hi = mid : lo = mid + 1;
    }
    return lo;
}