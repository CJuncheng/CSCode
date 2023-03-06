#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
   
    int lo = 0, hi = nums.size();
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        if(nums[mid] > target) hi = mid; //深入前半段[lo, mi)继续查找
        else if(nums[mid] < target) lo = mid + 1; //深入后半段(mi, hi)继续查找
        else return mid;
    }
    // 分别处理如下四种情况
    // 目标值在数组所有元素之前 [0,0)
    // 目标值等于数组中某一个元素 return middle
    // 目标值插入数组中的位置 [left, right) ，return right 即可
    // 目标值在数组所有元素之后的情况 [left, right)，因为是右开区间，所以 return right
    return hi;
}

int main(int argc, char* argv[])
{
    vector<int> vec = {1, 3, 5, 7, 9, 10};
    int ret = searchInsert(vec, 0);
    cout << ret << endl;
}