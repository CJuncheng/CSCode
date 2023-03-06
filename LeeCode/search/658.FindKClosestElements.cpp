#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    /*
    //排序
        sort(arr.begin(), arr.end(), [x](int a, int b){
            return abs(a-x) < abs(b-x) || (abs(a-x) == abs(b-x)&&a<b);
        });
        sort(arr.begin(), arr.begin()+k);
        return vector<int> (arr.begin(), arr.begin()+k);
    */


    //二分+双指针
    //[right,)大于等于x, (,left]小于x
    auto right = lower_bound(arr.begin(), arr.end(), x), left = right-1;
    while(k--){
        if(left<arr.begin()) ++right;
        else if(right>=arr.end()) --left;
        else if(x-*left<=*right-x) --left;
        else ++right;
    }
    return vector<int>(++left, right); // 返回[left+1, right-1]
}