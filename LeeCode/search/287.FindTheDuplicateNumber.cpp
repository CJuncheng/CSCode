#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int lo = 1, hi = nums.size() - 1;
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        int count = 0;
        for(auto& val : nums)
            if(val <= mid) ++count;
        if(count > mid) hi = mid;
        else lo = mid+1;
    }
    return lo;
}