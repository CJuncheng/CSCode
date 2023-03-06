#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

void printOneDegreeVector(const vector<int>& vec){
    cout << "Result: " << endl;
    for(auto& val : vec)
        cout << val << " ";
    cout << endl;
}

/*
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> umap;
    const int len2 = arr2.size();
    for(int i = 0; i < len2; ++i) umap[arr2[i]] = i;
    vector<vector<int>> vecs(len2);
    vector<int> remain;
    for(auto& val : arr1)
        if(umap.count(val)) vecs[umap[val]].push_back(val);
        else remain.push_back(val);
    sort(remain.begin(), remain.end());
    vector<int> res;
    for(auto& vec : vecs)
        for(auto& val : vec) 
            res.push_back(val);
    for(auto& val : remain) res.push_back(val);
    return res;
}

//计数排序
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int max = *max_element(arr1.begin(), arr1.end());
    vector<int> counts(max + 1);
    for (int& x: arr1) ++counts[x];
    vector<int> res;
    for (int& x: arr2) {
        for (int i = 0; i < counts[x]; ++i) res.push_back(x);
        counts[x] = 0;
    }
    for (int x = 0; x <= max; ++x) 
        for (int i = 0; i < counts[x]; ++i) 
            res.push_back(x);
    return res;
}
*/

//计数排序 hash表--来自上面计数排序的思路
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> counts; // <arr1 val, 次数>
    for(auto& val : arr1) ++counts[val];
    vector<int> res;
    for(auto& val : arr2){
        for(int i = 0; i < counts[val]; ++i) res.push_back(val);
        counts[val] = 0;
    }
    for(auto it = counts.begin(); it != counts.end(); ++it) 
        for(int i = 0; i < it->second; ++i) res.push_back(it->first);
    return res;
}

int main (int argc, char* argv[])
{
    vector<int>  arr1 = {2,3,1,3,2,4,6,7,9,2,19}, arr2 = {2,1,4,3,9,6};
    vector<int> ret = relativeSortArray(arr1, arr2);
    printOneDegreeVector(ret);
    
    return 0;
}