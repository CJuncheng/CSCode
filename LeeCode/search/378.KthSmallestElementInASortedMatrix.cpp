#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/solution/er-fen-chao-ji-jian-dan-by-jacksu1024/

int nLessThanMid(vector<vector<int>>& matrix, int mid, const int& row, const int& col){
    int i = row-1, j = 0, count = 0;
    while(i>=0&&j<col){
        if(matrix[i][j]<=mid) { count+=i+1; ++j;}
        else --i;
    }
    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int row = matrix.size(), col = matrix[0].size();
    int lo = matrix[0][0], hi = matrix[row-1][col-1];
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        int n = nLessThanMid(matrix, mid, row, col);
        n < k ? lo = mid+1 : hi = mid;
    }
    return lo;
}