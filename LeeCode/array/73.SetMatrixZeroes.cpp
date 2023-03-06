#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    // 空间复杂度 O(m+n)
    /*
    const size_t nRow = matrix.size();
    const size_t nCol = matrix[0].size();
    std::vector<bool> vec_row(nRow, false);
    std::vector<bool> vec_col(nCol, false);
    for(size_t i = 0; i < nRow; ++i) 
        for(size_t j = 0; j < nCol; ++j)
            if (matrix[i][j] == 0) 
                vec_row[i] = vec_col[j] = true;
    for(size_t i = 0; i < nRow; ++i) 
        if(vec_row[i] == true) 
            fill(matrix[i].begin(), matrix[i].end(), 0);
    for(size_t j = 0; j < nCol; ++j)
        if(vec_col[j] == true) {
            for(size_t i = 0; i < nRow; ++i)
                matrix[i][j] = 0;
        }
    */
    // 空间复杂度 O(1)
    const size_t nRow = matrix.size();
    const size_t nCol = matrix[0].size();
    bool firstRowWithZero = false;
    bool firstColWithZero = false;
    for(size_t i = 0; i < nRow; ++i)
        if(!matrix[i][0]){
            firstColWithZero = true;
            break;
        }
    for(size_t j = 0; j < nCol; ++j)
        if(!matrix[0][j]){
            firstRowWithZero = true;
            break;
        }
    for(size_t i = 1; i < nRow; ++i) 
        for(size_t j = 1; j < nCol; ++j)
            if (!matrix[i][j]) 
                matrix[0][j] = matrix[i][0] = 0;
    for(size_t i = 1; i < nRow; ++i) 
        for(size_t j = 1; j < nCol; ++j)
            if (!matrix[0][j] || !matrix[i][0]) 
                matrix[i][j] = 0;
    if(firstRowWithZero)
        fill(matrix[0].begin(), matrix[0].end(), 0);
    if(firstColWithZero)
        for(size_t i = 0; i < nRow; ++i)
            matrix[i][0] = 0;
}
int main (int argc, char* argv[])
{
    
    vector<vector<int>> matrix = {{1,7,3},{0,5,6},{0,8,9}};
    setZeroes(matrix);
    for (auto it = matrix.begin(); it != matrix.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }

    return 0;

}