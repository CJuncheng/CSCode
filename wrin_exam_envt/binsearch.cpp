
#include <iostream>
#include <vector>
#include <map>
#include<queue>
#include <utility> // pair
#include <memory>

using namespace std;

int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while(1 < hi - lo) {
            int mid = lo + ((hi-lo)>>1);
            nums[mid] > target ? hi = mid : lo = mid;
        } 
        return nums[lo] == target ? lo : -1;
 }

int main(int argc, char **argv)
{
    vector<int> arr = {0,1,1,1,2,2,2,3};
    int ret = search(arr, 2);
    std::cout << ret << std::endl;

    
    return 0;
}

