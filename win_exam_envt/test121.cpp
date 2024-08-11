#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


int main() {
    vector<int> vecs = {1, 2, 3};
    const int n = vecs.size();
    int s = 10;
    if(s%2==0) {
        int half = s/2;
        int cnt = (half-1)*2 + 1;
        for(int i = 0; i < n; ++i)
            if(vecs[i] < half) cnt -= 2;
            else if(vecs[i] == half) cnt -= 1;
        cout << cnt << endl;
    } else {
        int cnt = s;
        for(int i = 0; i < n; ++i)
            if(vecs[i] < s/2) cnt -= 2;
    }

    return 0;
}



/*
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


int cntPairs(const vector<int>& nums, int s){
    
    unordered_set<int> uset(nums.begin(), nums.end());
    
    int cnt = 0;

    int i = 1, j = s-1;
    while(i<j){
        if(uset.find(i) != uset.end()) ++i;
        if(uset.find(j) != uset.end()) --j;
        if(i+j > s) --j;
        else if(i+j < s) ++i;
        else{
            ++cnt;
            ++i, --j;
        }
    }  
    return cnt;
}

int main() {
    int n, s;
    
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    cin >> s;

    sort(nums.begin(), nums.end());
    int cnt = cntPairs(nums, s);
    cout << cnt << endl;

    return 0;
}
*/