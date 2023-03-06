#include <vector>
#include <algorithm>
using namespace std;
vector<int> sortArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums;
}