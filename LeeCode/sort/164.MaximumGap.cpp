#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maximumGap(vector<int>& nums) {
    const int len = nums.size();
    if (len < 2) return 0;
    int max = nums[0];
    for(int i = 1; i < len; ++i)
        if(nums[i]>max) max = nums[i]; // 找到[lo, hi)中最大值
    for(int exp = 1; max/exp > 0; exp*=10) // 按指数 exp 进行排序，exp 按个位。。。
    {
        vector<int> output(len), buckets(10); // buckets记录对应桶中数据的次数
        for(int i = 0; i < len; ++i) 
            ++buckets[nums[i]/exp%10];
        for(int j = 1; j < 10; ++j) // 更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
            buckets[j]+=buckets[j-1];
        for(int i = len-1; i>=0; --i){  // 将数据存储到临时数组output中
            output[buckets[nums[i]/exp%10] - 1] = nums[i];
            --buckets[nums[i]/exp%10];
        }
        for(int i = 0; i < len; ++i) 
            nums[i] = output[i];        
    }
    int ret = 0;
    for(int i = 1; i < len; ++i)
        ret = std::max(ret, nums[i]-nums[i-1]);
    return ret;
}

