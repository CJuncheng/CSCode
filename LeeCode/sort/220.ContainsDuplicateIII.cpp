#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
}
// https://leetcode.cn/problems/contains-duplicate-iii/solution/c-li-yong-tong-fen-zu-xiang-xi-jie-shi-b-ofj6/
inline long getID(long val, long t){
        return val>=0 ? val / ( t + 1 ) : ( val + 1 )/( t + 1 ) - 1;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    const int len = nums.size();
    //我们用unordered_map来实现桶,其底层实现是一个哈希表.
    unordered_map<int,int> m;
    for(int i = 0 ; i < len; i++ ){
        //当前元素
        long  val = nums[i];
        //给当前元素生成id,这里我们同一个id的桶内元素满足abs(nums[i] - nums[j]) <= t
        int id = getID(val,t);
        //前面的i-(k+1)是超出了范围的桶,我们把它提前删除,以免影响判断
        if( i-(k+1) >= 0 )
            //把下标不满足我们判断范围的桶删除了
            m.erase(getID(nums[i-(k+1)],t));
        //看看当前元素属于的桶中有没有元素
        if(m.find(id)!=m.end()) return true;
        //看看前面相邻桶有没有符合条件的
        if(m.find(id - 1) != m.end() && abs(m[id-1]-val) <= t) return true;
        //看看后面相邻桶有没有符合条件的
        if(m.find(id + 1) != m.end() && abs(m[id+1]-val) <= t) return true;
        //分桶,把这个元素放入其属于的桶
        m[id] = val;
    }
    return false;
}


