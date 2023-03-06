#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {
    if(x < 2) return x;
    int lo = 2, hi = x;  
    while(lo < hi) {
        int mid = lo + ((hi-lo)>>1);
        if(mid > x/mid) hi = mid;
        else if (mid < x/mid) lo = mid + 1;
        else return mid;
    }
    return hi-1;
}