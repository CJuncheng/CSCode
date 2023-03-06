#include <iostream>
#include <vector>
using namespace std;

/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size()-1;
    while(row < (int)matrix.size() && col>= 0){
        if(matrix[row][col] < target) ++row;
        else if(matrix[row][col] > target) --col;
        else return true;
    }
    return false;
}
*/


// 标准二分查找
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int len = matrix[0].size();
    int lo = 0, hi = matrix.size() * len;
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        if(matrix[mid/len][mid%len] > target) hi = mid; //深入前半段[lo, mi)继续查找
        else if(matrix[mid/len][mid%len] < target) lo = mid + 1; //深入后半段(mi, hi)继续查找
        else return true;
    }
    return false;
}



int main(int argc, char* argv[])
{
    vector<vector<int>> vec = {{1, 3}};
    bool ret = searchMatrix(vec, 3);
    cout << ret << endl;
}
