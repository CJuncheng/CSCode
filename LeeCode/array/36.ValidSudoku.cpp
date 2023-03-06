#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype> // tolower()
#include <utility> // pait
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int n = 9;

int isValidSudoku(vector<vector<char>>& board) {
    /*
    for(int i = 0; i < n; ++i)
    {
        std::unordered_multiset<char> rowSet;
        for(int j = 0; j < n; ++j)
            rowSet.insert(board[i][j]);
        rowSet.erase('.');
        for(auto rowSet_it = rowSet.begin(); rowSet_it != rowSet.end(); ++rowSet_it)
        {
            if(rowSet.count(*rowSet_it) > 1) return false;
        }
        
        std::unordered_multiset<char> colSet;
        for (int j = 0; j < n; ++j)
            colSet.insert(board[j][i]);
        colSet.erase('.');
        for(auto colSet_it = colSet.begin(); colSet_it != colSet.end(); ++colSet_it)
        {
            if(colSet.count(*colSet_it) > 1) return false;
        }

    }
    for (size_t r = 0; r < 3; ++r)
        for (size_t c = 0; c < 3; ++c) {
            std::unordered_multiset<char> rowColSet;
            for (size_t i = 3*r ; i < 3*r+3; ++i)
                for (size_t j = 3*c; j < 3*c+3; ++j)
                    rowColSet.insert(board[i][j]);
            rowColSet.erase('.');
            for(auto rowColSet_it = rowColSet.begin(); rowColSet_it != rowColSet.end(); ++rowColSet_it)
            {
                if(rowColSet.count(*rowColSet_it) > 1) return false;
            }
        }
    */
    int row[9][9] = {0};
    int col[9][9] = {0};
    int subbox[3][3][9];
    for(int r = 0; r < 9; ++r)
        for(int c = 0; c < 9; ++c){
            if(board[r][c]=='.') continue;
            int index = board[r][c] - '0' -1;
            ++row[r][index];
            ++col[c][index];
            ++subbox[r/3][c/3][index];
            if (row[r][index]>1 || col[c][index] >1 || subbox[r/3][c/3][index]>1)
                return false;
        }
    return true;
}

int main (int argc, char* argv[])
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.','2', '.', '8', '.' },
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
                           
    int ret = isValidSudoku(board);
    std::cout << ret << std::endl;
    return 0;
}

