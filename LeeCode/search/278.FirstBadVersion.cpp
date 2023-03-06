#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        //if(isBadVersion(mid)) 
        hi = mid;
        //else lo = mid+1;
    }
    return lo;
}