#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;   
bool judgeSquareSum(int c) {
    int l = 0, r = sqrt(c);
    cout << r << endl;
    while(l<=r){
        long sum = (long)l*l+(long)r*r;
        if(sum==c) return true;
        else if(sum<c) ++l;
        else --r;
    }
    return false;
}