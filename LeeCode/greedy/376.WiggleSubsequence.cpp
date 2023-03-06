#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int wiggleMaxLength(vector<int>& nums) {
    const int len = nums.size();
    if(len < 2) return len;
    int up = 1, down = 1;
    for(int i = 1; i < len; ++i){
        if(nums[i] > nums[i-1])
            up = down + 1;
        if(nums[i] < nums[i-1])
            down = up + 1;
    }
    return max(up, down);
}