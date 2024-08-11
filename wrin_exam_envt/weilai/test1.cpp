#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 池化操作
int poolOperation(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    while (n > 1) {
        std::vector<std::vector<int>> newMatrix(n / 2, std::vector<int>(n / 2, 0));
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                std::vector<int> temp;
                temp.push_back(matrix[i][j]);
                if (i + 1 < n) temp.push_back(matrix[i + 1][j]);
                if (j + 1 < n) temp.push_back(matrix[i][j + 1]);
                if (i + 1 < n && j + 1 < n) temp.push_back(matrix[i + 1][j + 1]);
                std::sort(temp.begin(), temp.end());
                newMatrix[i / 2][j / 2] = temp[temp.size() - 2];
            }
        }
        matrix = newMatrix;
        n /= 2;
    }
    return matrix[0][0];
}

int main() {
    int N; cin >> N;
    vector<vector<int>> matrix;
    for(int i = 0; i < N; ++i){
        vector<int> tmp;
        for(int j = 0; j < N; ++j) {
            int val; cin >> val;
            tmp.push_back(val);
        }
        matrix.push_back(tmp);
    }
    int ret = poolOperation(matrix);
    cout << ret << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")