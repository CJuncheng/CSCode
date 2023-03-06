#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
          //1.暴力双指针
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (auto a = nums.begin(); a != nums.end()-3; ++a) {
            if(a>nums.begin() && *a == *(a-1)) continue;
            for (auto b = a+1; b != nums.end()-2; ++b) {
                if(( b > a+1) && *a == *(a-1)) continue;
                auto c = b + 1, d = nums.end()-1;
                while (c < d){
                    if (((long long)*a + *b + *c + *d) < target) {
                        ++c;
                        while (c < d && *c == *(c-1)) ++c;
                    } else if((*a + *b + *c + *d) > target) {
                        --d;
                        while (c < d && *d == *(d+1)) --d;
                    } else {
                        result.push_back({*a, *b, *c, *d});
                        ++c; 
                        --d;
                        while (c < d && *c == *(c-1)) ++c;
                        while (c < d && *d == *(d+1)) --d;
                    }
                }
            }
        }
        return result;
        
/*
        // unordered_map
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        unordered_multimap<int, pair<size_t, size_t>> umap;
        for(size_t i=0; i<nums.size()-1; ++i)
            for(size_t j=i+1; j<nums.size(); ++j)
                umap.insert( make_pair(nums[i]+nums[j], make_pair(i, j)) );

        std::cout << "umap first: ";
        for(auto it = umap.begin(); it != umap.end(); ++it)
            std::cout << it->first << " ";
        std::cout << std::endl;

        for(auto it = umap.begin(); it != umap.end(); ++it){
            int remain = target - it->first;
            auto range = umap.equal_range(remain);
            for (auto it2 = range.first; it2 != range.second; ++it2) {
                size_t a = it->second.first;
                size_t b = it->second.second;
                size_t c = it2->second.first;
                size_t d = it2->second.second;
                if(a!=c&&a!=d&&b!=c&&b!=d){
                    vector<int> temp = {nums[a],nums[b], nums[c], nums[d]};
                    sort(temp.begin(), temp.end());
                    result.push_back(temp);
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(),result.end()), result.end());

        return result;       

*/  
}

int main (int argc, char* argv[])
{
    vector<int> nums = {1, 0, -1, 0, -2, 2 };
    int target = 0;
    vector<vector<int>> re = fourSum(nums, target);
    for (auto it = re.begin(); it != re.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
   }
    return 0;
}
