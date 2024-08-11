#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int partition(vector<int>& vec, int lo, int hi){
    swap(vec[lo], vec[lo+rand()%(hi-lo)]);
    --hi;
    int pivotValue = vec[lo];
    while(lo<hi){
        while(lo<hi)
            if(pivotValue < vec[hi]) --hi;
            else {vec[lo++] = vec[hi]; break; }
        while(lo<hi)
            if(pivotValue > vec[lo]) ++lo;
            else {vec[hi--] = vec[lo]; break; }
    }
    vec[lo] = pivotValue;
    return lo;
}

void quickSort(vector<int>& vec, int lo, int hi){
    if(hi-lo < 2) return;
    int pivot = partition(vec, lo, hi);
    for(auto val : vec){
        cout << val << " ";
    }
    cout << endl;
    quickSort(vec, lo, pivot);
    quickSort(vec, pivot, hi);
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 100, 2, 6, 1, -1};
    const int n = vec.size();
    quickSort(vec, 0, n);
    
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}