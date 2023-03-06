#include <iostream>
#include <vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size()-1;
    while(row < (int)matrix.size() && col>= 0){
        if(matrix[row][col] < target) ++row;
        else if(matrix[row][col] > target) --col;
        else return true;
    }
    return false;
}