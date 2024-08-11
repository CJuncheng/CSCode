#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> selectedNumbers;
int minNumbers = INT_MAX;

void generateCombinations(vector<int>& nums, int target, vector<int>& currentCombination, int currentIndex, int currentSum) {
    if (currentSum == target) {
        if (currentCombination.size() < minNumbers) {
            minNumbers = currentCombination.size();
            selectedNumbers = currentCombination;
        }
        return;
    }
    
    if (currentIndex >= nums.size() || currentSum > target) {
        return;
    }
    
    for (int i = currentIndex; i < nums.size(); i++) {
        if (i > currentIndex && nums[i] == nums[i-1]) {
            continue; // skip duplicate numbers
        }
        
        currentCombination.push_back(nums[i]);
        generateCombinations(nums, target, currentCombination, i+1, currentSum + nums[i]);
        currentCombination.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M; // 输入正整数个数和目标数字和

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i]; // 输入N个正整数
    }

    sort(nums.begin(), nums.end()); // 对正整数进行排序

    vector<int> currentCombination;
    generateCombinations(nums, M, currentCombination, 0, 0);

    if (selectedNumbers.empty()) {
        cout << "No solution" << endl;
    } else {
        cout << minNumbers << endl;
    }

    return 0;
}