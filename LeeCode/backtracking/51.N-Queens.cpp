#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> res;
inline
bool isValid(int row, int col, vector<string>& chessboard, int n)
{
    for(int i = 0; i < row; ++i) // 检查列
        if(chessboard[i][col] == 'Q') return false;
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) // 检查45度
        if(chessboard[i][j] == 'Q') return false;
    for(int i = row - 1, j = col + 1; i >= 0 && j >= 0; --i, ++j) // 检查135度数
        if(chessboard[i][j] == 'Q') return false;
    return true;
}
void backtracking(int n, int row, vector<string>& chessboard)
{
    if(row == n) { 
        res.push_back(chessboard);
        return;
    }
    for(int col = 0; col < n; ++col) {
        if(isValid(row, col, chessboard, n)){
            chessboard[row][col] = 'Q';
            backtracking(n, row+1, chessboard);
            chessboard[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.'));
    backtracking(n, 0, chessboard);
    return res;
}