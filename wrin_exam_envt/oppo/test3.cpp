#include <iostream>
#include <string>
using namespace std;

int calculateWeight(const std::string& str) {
    int weight = 0;
    for (int i = 0; i < (int)str.size() - 3; i++) 
        if (str.substr(i, 4) == "oppo") 
            weight++;
    return weight;
}

int main() {
   
    std::string str;
    std::cin >> str;
    
    const int n = str.size();
    int weightSum = 0;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n-i; ++len) {
            std::string subStr = str.substr(i, len);
            weightSum += calculateWeight(subStr);
        }
    }
    
    std::cout << weightSum << std::endl;
    

    return 0;
}