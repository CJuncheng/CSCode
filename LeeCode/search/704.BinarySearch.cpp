#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while(1 < hi - lo) {
        int mid = lo + ((hi-lo)>>1);
        nums[mid] > target ? hi = mid : lo = mid;
    } 
    return nums[lo] == target ? lo : -1;
}