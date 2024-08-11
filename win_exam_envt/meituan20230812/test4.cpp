#include <iostream>
#include <vector>

using namespace std;

constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(const vector<vector<char>>& matrix, vector<vector<bool>>& vst, int x, int y){
    vst[x][y] = true;
    const int nRow = matrix.size(), nCol = matrix[0].size();
    for(int i = 0; i < 4; ++i){
        int x_ = x+dirs[i][0], y_ = y+dirs[i][1];
        if(x_>=0 && x_ < nRow && y_ >= 0 && y_ < nCol && matrix[x_][y_] == matrix[x][y])
            if(!vst[x_][y_]) dfs(matrix, vst, x_, y_);
    }
}

int main() {
    int len;
    string s;
    cin >> len;
    cin >> s;

    int res = INT_MAX;
    for(int k = 1; k < len; ++k){
        if(len%k==0){
            int n = k, m = len/k;
            vector<vector<char>> matrix(n, vector<char>(m));
            int idx = 0;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    matrix[i][j] = s[idx++];
            vector<vector<bool>> vst(n, vector<bool>(m, false));
            int cnt = 0;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    if(!vst[i][j]){
                        ++cnt;
                        dfs(matrix, vst, i, j);
                    }
            res = min(res, cnt);
        }
    }
    cout << res << endl;
    
    return 0;
}