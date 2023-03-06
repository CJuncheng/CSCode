#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int child = 0;
    int cookie = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while(child < (int)g.size()&& cookie < (int)s.size()) {
        if(g[child] <= s[cookie]) ++child;
        ++cookie;
    }
    return child;
}

int main (int argc, char* argv[])
{
   
    vector<int> gVec = {1,2};
    vector<int> sVec = {1,2,3};
    int ret = findContentChildren(gVec, sVec);
    cout << "Result: " << ret << endl;

    return 0;
}