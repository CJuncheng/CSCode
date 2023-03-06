#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <vector>
using namespace std;

// 使用deque来实现单调队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    const int len = nums.size();
    vector<int> res;
    deque<int> dq;
    for(int i = 0; i < len; ++i) {
        if(i>=k&&nums[i-k]==dq.front()) dq.pop_front(); // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        while(!dq.empty()&&nums[i]>dq.back()) dq.pop_back();
        dq.push_back(nums[i]);
        if(i>=k-1) res.push_back(dq.front());
    }
    return res;
}

int main (int argc, char* argv[])
{
    vector<int> iVec = {1,3,-1,-3,5,3,6,7};
    vector<int> ret = maxSlidingWindow(iVec, 3);
    cout<< "Data: ";
    for(auto & val : ret)
        cout << val << " ";   // 返回 1
    cout << endl;
    return 0;
}