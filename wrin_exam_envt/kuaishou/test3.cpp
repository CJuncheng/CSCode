#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, std::vector<int>> maxNonAdjacentSum(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return std::make_pair(0, std::vector<int>());
    }
    if (n == 1) {
        return std::make_pair(nums[0], std::vector<int>({0}));
    }
    
    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    std::vector<int> selectedIndices;
    int j = n - 1;
    while (j >= 0) {
        if (j == 0) {
            selectedIndices.push_back(j);
            break;
        } else if (dp[j] == dp[j-1]) {
            j--;
        } else {
            selectedIndices.push_back(j);
            j -= 2;
        }
    }
    
    std::reverse(selectedIndices.begin(), selectedIndices.end());
    return std::make_pair(dp[n-1], selectedIndices);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::pair<int, std::vector<int>> result = maxNonAdjacentSum(nums);
    
    std::cout << "Maximum sum: " << result.first << std::endl;
    std::cout << "Selected indices: ";
    for (int index : result.second) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    
    return 0;
}