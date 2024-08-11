#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    
    int n = str.length();
    std::vector<int> prefixSum(n, 0); // 前缀和数组，存储以每个位置结尾的子串中"oppo"的数量
    
    int count = 0; // 所有子串的权值和
    
    // 计算前缀和数组
    for (int i = 1; i < n; i++) {
        if (str.substr(i - 1, 4) == "oppo") {
            prefixSum[i] = prefixSum[i - 1] + 1;
        } else {
            prefixSum[i] = prefixSum[i - 1];
        }
    }
    
    // 计算所有子串的权值和
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            count += prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}