#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isPerfectSquare(int num) {
    if(num == 1) return num;
    int lo = 2, hi = num;
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        if(mid < num/mid) lo=mid+1;
        else if(mid > num/mid) hi=mid;
        else {
            if(num%mid==0) return true;
            lo=mid+1;
        }
    }
    return false;
}