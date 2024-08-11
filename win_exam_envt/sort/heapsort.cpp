#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& vec, int idx, int end){
    int largest = idx, left = 2*idx+1, right = 2*idx+2;
    if(left<end&&vec[largest] < vec[left]) largest = left;
    if(right<end&&vec[largest] < vec[right]) largest = right;
    if(largest != idx){
        swap(vec[largest], vec[idx]);
        heapify(vec, largest, end);
    } 
}

void heapSort(vector<int>& vec){
    const int n = vec.size();
    for(int i = n/2-1; i>=0; --i)
        heapify(vec, i, n);
    for(int end = n - 1; end > 0; --end){
        swap(vec[0], vec[end]);
        heapify(vec, 0, end);
    }
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 100, -8, 102, 2, 6, 1, -1};
    const int n = vec.size();
    heapSort(vec);
    
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}