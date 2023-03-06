#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> w;
public:
    Solution(vector<int>& W) {
        partial_sum(W.begin(), W.end(), back_inserter(w));
    }
    
    int pickIndex() {
        int weight = rand() % w.back();
        return upper_bound(w.begin(), w.end(), weight) - w.begin();
    }
};