#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int nLessThanMid(const int& m, const int& n, int mid){
    int count = 0;
    for(int i = 1; i <= m; ++i)
        count += min(mid/i, n);
    return count;
}

int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m*n;
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        nLessThanMid(m, n, mid) < k ? lo = mid+1 : hi = mid;
    }
    return lo;
}




int main(int argc, char* argv[]){
    int ret = findKthNumber(2, 3, 6);
    cout << ret << endl;
    return 0;
}