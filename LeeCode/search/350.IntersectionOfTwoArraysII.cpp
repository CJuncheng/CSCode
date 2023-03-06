#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()) return intersect(nums2, nums1);
    unordered_map<int, int> umap;
    for(int& num : nums1) ++umap[num];
    vector<int> res;
    for(int& num : nums2) 
        if(umap.count(num)){
            res.push_back(num);
            --umap[num];
            if(umap[num]==0) umap.erase(num);
        }
        /*
            if(umap[num]){
                res.push_back(num);
                --umap[num];    
            }
        */
    return res;
}
