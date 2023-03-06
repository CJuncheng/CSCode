#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    int maxH = 0;
    const int len = citations.size();
    sort(citations.begin(), citations.end());
    for(int i = 0; i < len; ++i){
        int h = len-i;
        if(citations[i]==h) 
            if(h>maxH) maxH = h;
    }
    return maxH;
}

int main(int argc, char* argv[])
{
    vector<int> citations = {0,1,3,5,6};
    int ret = hIndex(citations);
    cout << ret << endl;
}