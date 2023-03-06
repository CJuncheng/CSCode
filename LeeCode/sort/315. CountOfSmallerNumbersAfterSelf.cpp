#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void printOneDegreeVector(const vector<int>& vec){
    cout << "Result: " << endl;
    for(auto& val : vec)
        cout << val << " ";
    cout << endl;
}
// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/solution/zhen-xiao-bai-jiang-jie-gei-ni-bai-kai-l-78qf/

vector<int> index; // 存放 nums 的索引
vector<int> counts;
 
void twoWayMerge(vector<int>& nums, int lo, int mid, int hi) // [lo, mi)和[mi, hi)各自有序，lo < mi < hi
{
    vector<int> tmpIndex(hi-lo); // 存放临时区间的索引
    vector<int> tmpNums(hi-lo);
    int idx = 0; // tmpNums对应的索引 [lo, hi)
    int i = lo, j = mid;
    while(i<mid && j < hi){
        if(nums[i]>nums[j]) {
            counts[index[i]] += hi-j;
            tmpIndex[idx] = index[i];
            tmpNums[idx++] = nums[i++];
        } else {
            tmpIndex[idx] = index[j];
            tmpNums[idx++] = nums[j++];
        }
    }
    while(i<mid){
        tmpIndex[idx] = index[i];
        tmpNums[idx++] = nums[i++];
    }
    while(j < hi){
        tmpIndex[idx] = index[j];
        tmpNums[idx++] = nums[j++];
    }
    for(int i = 0; i < hi-lo; ++i){
        index[lo+i] = tmpIndex[i];
        nums[lo+i] = tmpNums[i];
    }
}

void mergeSort(vector<int>& nums, int lo, int hi) //[lo, hi)
{
    if(hi-lo<2) return;
    int mid = (lo+hi)/2;
    mergeSort(nums, lo, mid); mergeSort(nums, mid, hi);
    twoWayMerge(nums, lo, mid, hi);
}

vector<int> countSmaller(vector<int>& nums) {
    int len = nums.size();
    for(int i = 0; i < len; ++i) { 
        index.push_back(i);
        counts.push_back(0);
    }
    mergeSort(nums, 0, len);
    return counts;
}

int main (int argc, char* argv[])
{
    vector<int> nums = {5,2,6,1};
    vector<int> ret = countSmaller(nums);
    printOneDegreeVector(counts);
    return 0;
}