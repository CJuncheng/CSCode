#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int len = nums.size()/2;
        unordered_map<int, int> umap;
        for(auto& val : nums) ++umap[val];
        for(auto it = umap.begin(); it != umap.end(); ++it)
            if(it->second > len) return it->first;
        return -1;
        /*
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        */
    }
};