#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;
    
    std::string keyboard;
    std::cin >> keyboard;

    std::unordered_map<char, int> countMap;
    int windowStart = 0;
    int maxSubstringCount = 0;

    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        char currChar = s[windowEnd];
        countMap[currChar]++;
        
        while (countMap.size() > k) {
            char startChar = s[windowStart];
            countMap[startChar]--;
            if (countMap[startChar] == 0) {
                countMap.erase(startChar);
            }
            windowStart++;
        }

        int windowLength = windowEnd - windowStart + 1;
        maxSubstringCount += windowLength;
    }

    std::cout << maxSubstringCount << std::endl;

    return 0;
}