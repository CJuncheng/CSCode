#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

static bool cmp(const string& str1, const string& str2)
{
    if(str1.size() == str2.size()) return str1 > str2;
    return str1.size() > str2.size();
}
string kthLargestNumber(vector<string>& nums, int k) {
    sort(nums.begin(), nums.end(), cmp);
    return nums[k-1];
}

int main (int argc, char* argv[])
{
    vector<string> nums = {"3","7"};
    string ret = kthLargestNumber(nums, 2);
    //cout << ret << endl;
    //printTwoDegreeVector(matrix);
    return 0;
}