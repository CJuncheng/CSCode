#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wiggleSort(vector<int>& nums) {
    vector<int> vec = nums;
    sort(vec.begin(), vec.end());
    for(auto it = vec.begin(); it != vec.end(); ++it) 
        cout << *it << " ";
    cout << endl;
    const int len = nums.size();
    int left = (len - 1)/2, right = len-1;
    for(int i = 0; i < len; ++i)
        nums[i] = i&0x1 ? vec[right--]  : vec[left--];
}

int main (int argc, char* argv[])
{
    vector<int> nums = {1,3,2,2,3,1};
    wiggleSort(nums);
    for(auto it = nums.begin(); it != nums.end(); ++it) 
        cout << *it << " ";
    cout << endl;
    return 0;
}