#include <iostream>
#include <vector>
using namespace std;
/*
// 二分 O(nlogn)
int binarySearch(const vector<int>& vec, int target, int lo, int hi) 
{
    while(1 < hi-lo){
        int mid = lo + ((hi-lo)>>1);
        vec[mid] > target ? hi = mid : lo = mid; 
    }
    return target == vec[lo] ? lo : INT_MIN;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    const int len = numbers.size();
    vector<int> res(2, -1);
    for(int i = 0; i < len-1; ++i){
        int ret = binarySearch(numbers, target - numbers[i], i+1, len);
        if(ret!=INT_MIN){
            res[0] = i + 1; res[1] = ret + 1;
            return res;
        }
    }
    return res;
}
*/

// 双指针
vector<int> twoSum(vector<int>& numbers, int target) {
    int lo = 0, hi = numbers.size()-1;
    while(lo < hi) {
        int sum = numbers[lo] + numbers[hi];
        if(target > sum) ++lo;
        else if(target < sum) --hi;
        else return {lo+1, hi+1};
    }
    return {-1, -1};
}


int main(int argc, char* argv[])
{
    vector<int> vec = {2,7,11,15};
    vector<int> ret = twoSum(vec, 9);
    cout << ret[0] << " " << ret[1] << endl;
}