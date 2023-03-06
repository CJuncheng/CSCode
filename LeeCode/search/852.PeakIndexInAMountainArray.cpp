#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    const int len = arr.size();
    int i = 1;
    while(i<len&&arr[i-1]<arr[i]) ++i;
    return --i;
}