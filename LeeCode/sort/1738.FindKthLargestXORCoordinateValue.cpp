#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void printTwoDegreeVector(const vector<vector<int>>& matrix){
    cout << "Result: " << endl;
    for(auto& vec : matrix){
        for(auto& val : vec)
            cout << val << " ";
        cout << endl;
    }
}

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    const int nRow = matrix.size(), nCol = matrix[0].size();
    for(int i = 0; i < nRow; ++i)
        for(int j = 1; j < nCol; ++j)
            matrix[i][j] ^= matrix[i][j-1];
    for(int j = 0; j < nCol; ++j)
        for(int i = 1; i < nRow; ++i)
            matrix[i][j] ^= matrix[i-1][j];
    priority_queue<int, vector<int>, greater<int>> priQue;
    for(auto& vec : matrix)
        for(auto& val : vec) {
            if(priQue.size()<k) priQue.push(val);
            else if(val > priQue.top()) {
                priQue.pop();
                priQue.push(val);
            }
        }
    return priQue.top();
}

int main (int argc, char* argv[])
{
    vector<vector<int>> matrix = {{5,2},{1,6}};
    int ret = kthLargestValue(matrix, 2);
    cout << ret << endl;
    //printTwoDegreeVector(matrix);
    return 0;
}