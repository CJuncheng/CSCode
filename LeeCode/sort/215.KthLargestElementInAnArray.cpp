#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int partition(vector<int>& vec, int lo, int hi) // [lo, hi)
{   
    swap(vec[lo], vec[lo+rand()%(hi-lo)]); //任选一个元素与首元素交换, rand()*(hi-lo)取值[0, hi-lo-1]
    --hi;
    int pivotValue = vec[lo];  //以首元素为候选轴点——经以上交换，等效于随机选取
    while(lo<hi){ //从向量的两端交替地向中间扫描
        while(lo<hi) 
            if(pivotValue < vec[hi]) --hi; // hi直接向左移动
            else { vec[lo++] = vec[hi]; break;} //vec[hi]移到lo, lo向前移动一步
        while(lo<hi)
            if(pivotValue > vec[lo]) ++lo;
            else { vec[hi--] = vec[lo]; break;}
    } //assert: lo == hi 
    vec[lo] = pivotValue; //将备份的 pivotValue 记录置于前、后子向量之间
    return lo; //返回 pivot
}
void quickSort(vector<int>& vec, int lo, int hi) // [lo, hi), hi = A.size()
{
    if(hi-lo < 2) return;
    int pivot = partition(vec, lo, hi); //在[lo, hi)内构造轴点
    quickSort(vec, lo, pivot);  //[lo, pivot)
    quickSort(vec, pivot+1, hi); //[pivot+1, hi)  
}

int findKthLargest(vector<int>& nums, int k) {
    quickSort(nums, 0, nums.size());
    return nums[nums.size()-k];
}