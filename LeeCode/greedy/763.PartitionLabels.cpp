#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> res;
    unordered_map<char, int> umap;
    const int len = s.size();
    for(int i = 0; i < len; ++i) 
        umap[s[i]] = i;
    int start = 0, end = 0;
    for(int i = 0; i < len; ++i) {
        end = max(end, umap[s[i]]);
        if(i == end) {
            res.push_back(end - start +1);
            start = i + 1;
        }
    }
    return res;
}

int main (int argc, char* argv[])
{ 
    string str = "ababcbacadefegdehijhklij";
    vector<int> ret = partitionLabels(str);
    cout << "Result: "  << endl;
    for(auto it = ret.begin(); it != ret.end(); ++it) 
        cout << *it << " ";
    cout << endl;
    return 0;
}