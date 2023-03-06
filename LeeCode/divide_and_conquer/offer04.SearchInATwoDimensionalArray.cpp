#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;   
class Solution {
public:
    // 根据矩阵特性，按行递增， 按列递增
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        const int nRow = matrix.size(), nCol = matrix[0].size();
        int i = nRow -1, j = 0;
        while(i>=0&&j<nCol){
            if(matrix[i][j]<target) ++j;
            else if(matrix[i][j]>target) --i;
            else return true;
        }
        return false;
    }
};