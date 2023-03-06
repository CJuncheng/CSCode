#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index = m+n-1;
    --m; --n;
    while(n>=0) {
        if(m>=0 && nums1[m] > nums2[n]) 
            nums1[index--] = nums1[m--];
        else 
            nums1[index--] = nums2[n--];
    }
}

int main (int argc, char* argv[])
{
   
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    cout << "Result: " << endl;
    for(auto it = nums1.cbegin(); it != nums1.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}