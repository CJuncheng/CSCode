#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoWayMerge(vector<int>& vec, int lo, int mid, int hi){
    int i = 0, lenA = mid - lo;
    vector<int> A(lenA);
    for(int i = lo; i < mid; ++i) A[i-lo] = vec[lo];
    int j = mid, idx = lo;
    while(i < lenA && j < hi)
        vec[idx++] = A[i] > vec[j] ? vec[j++] : A[i++];
    while(i<lenA) vec[idx++] = A[i++];
}

void mergeSort(vector<int>& vec, int lo, int hi){
    if(hi-lo < 2) return;
    int mid = lo + ((hi-lo)>>1);
    mergeSort(vec, lo, mid); mergeSort(vec, mid, hi);
    twoWayMerge(vec, lo, mid, hi);
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 2, 6, 1, -1};
    const int n = vec.size();
    mergeSort(vec, 0, n);
    
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}