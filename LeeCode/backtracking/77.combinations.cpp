#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;
void backTracking(int n, int k, int start){
    if((int)path.size()==k){
        res.push_back(path);
        return;
    }
    for(int i = start; i <= n-(k-(int)path.size())+1; ++i){ //剪枝优化
        path.push_back(i);
        backTracking(n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    backTracking(n, k, 1);
    return res;
}

int main (int argc, char* argv[])
{
    vector<vector<int>> ret = combine(4, 2);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }

   
    return 0;
}