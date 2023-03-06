#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    const int len = nums.size();
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int i = 0; i < len; i+=2)
        res += nums[i];
    return res;
}