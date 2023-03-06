#include <iostream>
#include <vector>

using namespace std;
    
inline int sum(const vector<int>& ivec)
{
    int sum = 0;
    for(auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        sum += *it;
    return sum;
}

vector<vector<int>> res;
vector<int> path;
void backTracking(int k, int n, int start){
    if((int)path.size()==k){
        if(sum(path)==n)
            res.push_back(path);
        return;
    }
    for(int i = start; i <= 9-(k-(int)path.size())+1; ++i){
        path.push_back(i);
        backTracking(k, n, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    int minSum = 0;
    for(int i = 1; i <= k; ++i)
        minSum += i;
    if(minSum > n || k > 9) return res;
    backTracking(k, n, 1);
    return res;
}

int main (int argc, char* argv[])
{
    vector<vector<int>> ret = combinationSum3(3, 9);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }
    return 0;
}