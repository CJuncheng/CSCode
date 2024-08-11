#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> matA(n, vector<int>(m, 0));
    vector<vector<int>> matB(m, vector<int>(k, 0));
    vector<vector<int>> matC(n, vector<int>(k, 0));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> matA[i][j];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < k; ++j)
            cin >> matB[i][j];
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            for(int k = 0; k < m; ++k){
                matC[i][j] += matA[i][k]*matB[k][j];
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j)
            cout << matC[i][j] << " ";
        cout << endl;
    }
    return 0;
}