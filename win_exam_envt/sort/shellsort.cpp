#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shellSort(vector<int>& vec){
    const int n = vec.size();
    for(int inc = n/2; inc>0; inc /= 2){
        for(int i = inc; i < n; ++i){
            int key = vec[i], j = i - inc;
            while(j>=0 && vec[j]>key){
                vec[j+inc] = vec[j];
                j -= inc;
            }
            vec[j+inc] = key;
        }    
    }
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 2, 6, 1};
    shellSort(vec);
    const int n = vec.size();
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}