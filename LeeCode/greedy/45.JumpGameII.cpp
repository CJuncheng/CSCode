#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 参考
class Solution {
    public int jump(int[] nums) {
        // 记录当前能跳跃到的位置的边界下标
        int border = 0;
        // 记录在边界范围内，能跳跃的最远位置的下标
        int maxPosition = 0;
        // 记录所用步数
        int steps = 0;
        for(int i=0;i<nums.length-1;i++){
            // 继续往下遍历，统计边界范围内，哪一格能跳得更远，每走一步就更新一次能跳跃的最远位置下标
            // 其实就是在统计下一步的最优情况
            maxPosition = Math.max(maxPosition,nums[i]+i);
            // 如果到达了边界，那么一定要跳了，下一跳的边界下标就是之前统计的最优情况maxPosition，并且步数加1
            if(i==border){
                border = maxPosition;
                steps++;
            }
        }
        return steps;
    }
}
*/
//以最小的步数增加最大的覆盖范围，直到覆盖范围覆盖了终点
int jump(vector<int>& nums) {
    const int len = nums.size();
    int maxPosition = 0, boder = 0, steps = 0;
    for(int i = 0; i < len -1; ++i){
        maxPosition = max(maxPosition, nums[i]+i);
        if(boder == i) {
            boder = maxPosition;
            ++steps;
            if(boder>=len-1) break;
        }
    }
    return steps;
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {2,3,1,1,4};
    int ret = jump(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}