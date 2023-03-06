#include "linked_list.h"
using namespace std;
#include <algorithm>

/*
// 计数排序
void sortColors(vector<int>& nums) {
    int const len = nums.size();
    int count[3] = {0}; // 记录每种出现次数
    for(int i = 0; i < len; ++i)
        ++count[nums[i]];
    for(int i = 0, index = 0; i < 3; ++i)
        for(int j = 0; j < count[i]; ++j)
            nums[index++] = i;
}
*/
//双指针
void sortColors(vector<int>& nums) {
    int const len = nums.size();
    int red = 0, blue = len-1;
    for(int i = 0; i < blue+1;){
        if(nums[i] == 0)
            swap(nums[i++], nums[red++]);
        else if(nums[i] == 2)
            swap(nums[i], nums[blue--]);
        else
            ++i;    
    }
}