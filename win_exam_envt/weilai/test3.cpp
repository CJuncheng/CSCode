#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool hasLeadingZero(long long  num) {
    std::string strNum = std::to_string(num);
    return strNum.length() > 1 && strNum[0] == '0';
}

int countValidNumbers(long long n, int m) {
    std::string strN = std::to_string(n);
    std::sort(strN.begin(), strN.end());
    int count = 0;
    std::unordered_set<int> seen;
    do {
        long long permutedNum = std::stoll(strN);
        if (!hasLeadingZero(permutedNum) && permutedNum % m == 0) {
            seen.insert(permutedNum);
        }
    } while (std::next_permutation(strN.begin(), strN.end()));
    return seen.size();
}

int main() {
    int n, m;
    cin >> n >> m;

    long long result = countValidNumbers(n, m);
    std::cout << result << std::endl;
    return 0;
}