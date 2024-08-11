#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> calculateFValues(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> fValues(n);

    // 计算每个f(i)的值
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fValues[i] = std::abs(nums[i] - nums[i+1]); // 第一个元素特殊处理
        } else if (i == n-1) {
            fValues[i] = std::abs(nums[i] - nums[i-1]); // 最后一个元素特殊处理
        } else {
            fValues[i] = std::min(std::abs(nums[i] - nums[i-1]), std::abs(nums[i] - nums[i+1]));
        }
    }

    return fValues;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<int> fValues = calculateFValues(nums);

    for (int i = 0; i < n; i++) {
        std::cout << fValues[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}