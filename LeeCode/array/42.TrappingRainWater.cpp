
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    // 按列访问 O(n^2) 超时
    /**
    int sum = 0;
    for (auto it = height.begin()+1; it != height.end()-1; ++it)
    {
        
        auto left = std::max_element(height.begin(), it);
        auto right = std::max_element(it, height.end());
        auto min = *left <= *right ? left : right;
        if(*it < *min)
            sum = sum + (*min - *it);
    }
    return sum;
    **/
    // 动态规划
    /*
    const int n = height.size();
    int sum =0;
    int *max_left = new int[n]();
    int *max_right = new int[n]();
    for(int i = 1; i < n ; ++i) {
        max_left[i] = std::max(max_left[i-1], height[i-1]);
        max_right[n-i-1] = std::max(max_right[n-i], height[n-i]);
    }
    for(int i = 1; i < n-1; ++i){
        int min_ = std::min(max_left[i], max_right[i]);
        if(height[i] < min_) sum += min_ - height[i];
    }
    delete[] max_left;
    delete[] max_right;
    return sum;
    */
   // 分两块
    int max = 0;
    for (size_t i = 1; i < height.size(); ++i)
        if (height[i] > height[max]) max = i;
    int flag_left =0, flag_right = 0, water = 0;
    for (int i = 0; i < max; ++i){
        if (height[i]>flag_left)  flag_left = height[i];
        else water += flag_left - height[i];
    }
    for(int  j = height.size()-1; j>max; --j){
        if(height[j] > flag_right) flag_right = height[j];
        else water += flag_right - height[j];
    }
    return water;

    // 利用栈



}

int main (int argc, char* argv[])
{   
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trap(height) << std::endl;
    
    return 0;
}