#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    const int n = nums.size();
    unordered_map<int, int> ump;
    for(int i = 0; i < n; ++i) ump[nums[i]] = i;
    for(int i = 0; i < n; ++i)
        if(ump.count(target - nums[i]) && ump[target-nums[i]] != i)
            return vector<int>{i, ump[target-nums[i]]};
    return vector<int>{-1, -1};
}




#include <unordered_set>
#include <algorithm>
int lengthOfLongestSubstring(string s) {
    const int n = s.size();
    unordered_set<char> ust;
    int res = 0, left = 0;
    for(int right = 0; right < n; ++right){
        while(right<n&&ust.count(s[right])!=0){
            ust.erase(s[left]);
            ++left;
        }
        res = max(res, right-left+1);
        ust.insert(s[right]);
    }
    return res;

}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    int total = m+n;
    if (total & 0x1)
        return find_kth(nums1.begin(), m, nums2.begin(), n, total/2+1);
    else
        return (find_kth(nums1.begin(), m, nums2.begin(), n, total/2)+find_kth(nums1.begin(), m, nums2.begin(), n, total/2+1))/2.0;
}

static int find_kth(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k) {
    if (m > n) return find_kth(B, n, A, m, k);
    if (m == 0) return *(B+k-1);
    if (k == 1) return min(*A, *B);

    int ia = min (k/2, m), ib = k - ia;
    if (*(A+ia-1)<*(B+ib-1))
        return find_kth(A+ia, m-ia, B, n, k-ia);
    else if (*(A+ia-1)>*(B+ib-1))
        return find_kth(A, m, B+ib, n-ib, k-ib);
    else 
        return *(A+ia-1);
}
