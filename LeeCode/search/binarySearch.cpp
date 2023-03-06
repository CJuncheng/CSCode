#include <iostream>
#include <vector>
using namespace std;

/*
// 迭代版本 1
int binarySearch(const vector<int>& vec, int target, int lo, int hi) // [lo, hi)内查找元素 target 的索引
{
    while(lo < hi){
        int mid = lo + ((hi-lo)>>1);
        if(vec[mid] > target) hi = mid; //深入前半段[lo, mi)继续查找
        else if(vec[mid] < target) lo = mid + 1; //深入后半段(mi, hi)继续查找
        else return mid;
    }
    return -1;
}
*/


/*
// 迭代版本 2
int binarySearch(const vector<int>& vec, int target, int lo, int hi) // [lo, hi)内查找元素 target 的索引
{
    while(1 < hi-lo){
        int mid = lo + ((hi-lo)>>1);
        vec[mid] > target ? hi = mid : lo = mid; //经比较后确定深入[lo, mi)戒[mi, hi)
    } //出口时hi = lo + 1，查找区间仅含一个元素A[lo]
    return target == vec[lo] ? lo : -1;
}
*/
int binarySearch(const vector<int>& vec, int target, int lo, int hi) // [lo, hi]内查找元素 target 的索引
{
    while( hi>lo){
        int mid = lo + ((hi-lo)>>1);
        vec[mid] < target ? lo = mid+1 : hi = mid; //经比较后确定深入[lo, mi)和[mi, hi)
    } //出口时hi = lo ，查找区间仅含一个元素A[lo, lo]
    return target == vec[lo] ? lo : -1;
}

/*
// 递归版本 1
int binarySearch(const vector<int>& vec, int target, int lo, int hi) // [lo, hi)内查找元素 target 的索引
{
    if(lo>=hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if(vec[mid] > target) return binarySearch(vec, target, lo, mid); //深入前半段[lo, mi)继续查找
    else if(vec[mid] < target) return binarySearch(vec, target, mid+1, hi); //深入后半段(mi, hi)继续查找
    else return mid;
}


// 递归版本 2
int binarySearch(const vector<int>& vec, int target, int lo, int hi)
{
    if (hi > lo) {
        int mid = lo + (hi - lo) / 2;
        if (vec[mid] == target)
            return mid;
        if (vec[mid] > target)
            return binarySearch(vec, target, lo, mid);
        return binarySearch(vec, target, mid + 1, hi);
    }
    return -1;
}
*/


int main(int argc, char* argv[])
{
    vector<int> vec = {5,7,7,8,8,10};
    int ret = binarySearch(vec, 8, 0, vec.size());
    cout << ret << endl;
}