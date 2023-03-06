#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int singleNumber(vector<int>& nums) {
    /*
    if(nums.size() < 2) return nums[0];
    sort(nums.begin(), nums.end()); 
    int count = 1;
    for(auto it = nums.cbegin()+1; it != nums.cend(); ++it, count = 1) {
        while(*it == *(it-1)){ ++count; ++it;}
        if(count==1) return *(it-1);
        if(it == nums.cend() - 1) return *it;
    }
    return 0;
    */
   
    int one = 0, two = 0, three=0;
    for (int num : nums) {
        // two的相应的位等于1，表示该位出现2次
        two |= (one & num);
        // one的相应的位等于1，表示该位出现1次
        one ^= num;
        // three的相应的位等于1，表示该位出现3次
        three = (one & two);
        // 如果相应的位出现3次，则该位重置为0
        two &= ~three;
        one &= ~three;
    }
    return one;

    /** 3. 逻辑电路状态：00->01->10->00
     * 0 ^ x = x,
     * x ^ x = 0；
     * x & ~x = 0,
     * x & ~0 =x;
     */  
    /*
    int a = 0, b = 0;
    for (auto& val : nums) {
        a = (a ^ val) & ~b;
        b = (b ^ val) & ~a;
    }
    return a;
    */
}


int main (int argc, char* argv[])
{
    vector<int> nums = {0,1,0,1,0,1,99};
    int ret = singleNumber(nums);
    std::cout << ret << endl;
    return 0;
}