

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& vec){
    int n = vec.size();
    while(--n)
        for(int i = 0; i < n; ++i)
            if(vec[i]>vec[i+1])
                swap(vec[i], vec[i+1]);
    
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 2, 6};
    bubbleSort(vec);
    const int n = vec.size();
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}