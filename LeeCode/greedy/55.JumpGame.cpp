#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    const int len = nums.size();
    if(len < 2) return true;
    int maxCover = nums[0];
    for(int i = 1; i < len - 1; ++i) {
        if(maxCover>=i)
            maxCover = max(i + nums[i], maxCover);
        else break;
    }
    return maxCover >= len - 1;
}

int main (int argc, char* argv[])
{
   
    vector<int> iVec = {2,3,1,1,4};
    bool ret = canJump(iVec);
    cout << "Result: " << ret << endl;
    
    return 0;
}