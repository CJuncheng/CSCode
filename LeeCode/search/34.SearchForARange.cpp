#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    vector<int> res(2,-1);
    while(lo < hi){
        int mid = lo + ((hi-lo)/2);
        if(nums[mid] > target) hi = mid; //深入前半段[lo, mi)继续查找
        else if(nums[mid] < target) lo = mid + 1; //深入后半段(mi, hi)继续查找
        else { // mid = target
            while(mid>0 && nums[mid]==nums[mid-1]) --mid; res[0] = mid; 
            while(mid<(int)(nums.size()-1) && nums[mid]==nums[mid+1]) ++mid; res[1] = mid;
            return res;
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    vector<int> vec = {2,2};
    vector<int> ret = searchRange(vec, 2);
    cout << ret[0] << " " << ret[1] << endl;
}