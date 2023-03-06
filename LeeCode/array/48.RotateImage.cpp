#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &x, int &y)
{
    x = x^y;
    y = x^y;
    x = x^y;
}


void rotate(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n-1-i; ++j)
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
    std::cout << std::endl;

    for(int i = 0; i < (n>>1); ++i)
        for(int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n-1-i][j]);
   
}

int main (int argc, char* argv[])
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    for (auto it = matrix.begin(); it != matrix.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
   }

    rotate(matrix);
   
    
    return 0;

}