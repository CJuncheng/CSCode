#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    const int len = citations.size();
    sort(citations.begin(), citations.end());
    for(int i = 0; i < len; ++i){
        int h = len-i;
        if(citations[i]>=h) return h;
    }
    return 0;
}

int main(int argc, char* argv[]){
    map<int, int> map;
    map[3] = 1;
    map[2] = 3;
    for(auto it = map.begin(); it != map.end(); ++it){
        cout << it->first << " " << it->second <<endl;
    }
    return 0;
}