#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int counts = 0;
void twoWayMerge(vector<int>& vec, int lo, int mid, int hi) // [lo, mi)和[mi, hi)各自有序，lo < mi < hi
{
    vector<int> tmpVec(hi-lo);
    for(int i = lo, j = mid; i<mid; ){
        while(j<hi&&(long)vec[i]>2*(long)vec[j]) ++j;
        counts += j-mid;
        ++i;
    }   
    int index = 0, i = lo, j = mid;
    while(i<mid && j < hi)
        tmpVec[index++] = vec[i]<=vec[j] ? vec[i++] : vec[j++];
    while(i<mid) tmpVec[index++] = vec[i++];
    while(j < hi) tmpVec[index++] = vec[j++];
    for(int i = 0; i < hi-lo; ++i) vec[lo+i] = tmpVec[i];
}
void mergeSort(vector<int>& vec, int lo, int hi)
{
    if(hi-lo < 2) return;
    int mi = (lo+hi)/2; //以中点为界
    mergeSort(vec, lo, mi); mergeSort(vec, mi, hi); //分别排序
    twoWayMerge(vec, lo, mi, hi); //归并
}
int reversePairs(vector<int>& nums) {
    const int len = nums.size();
    if(len<2) return 0;
    mergeSort(nums, 0, len);
    return counts;
}

int main (int argc, char* argv[])
{
    vector<int> nums = {1,3,2,3,1};
    cout << reversePairs(nums) << endl;
    //printTwoDegreeVector(matrix);
    return 0;
}