#include <iostream>
#include <vector>

using namespace std;

template<typename Iter>
inline bool isPalindrome(Iter first, Iter last)
{
    for(; first < last; ++first, --last)
        if(*first != *last) return false;
    return true;
}

vector<vector<string>> res;
vector<string> path;
void backtracking(const string& str, string::iterator first){
    if(first >= str.end()){
        res.push_back(path);
        return;
    }
    for(auto last = first; last != str.end(); ++last){
        if(isPalindrome(first, last)){
            string s = string(first, last+1);
            path.push_back(s);
            backtracking(str, last+1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    backtracking(s, s.begin());
    return res;
}

int main (int argc, char* argv[])
{
    string str = "aab";
    vector<vector<string>> ret = partition(str);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " " ;
        std::cout << std::endl;
    }
    return 0;
}