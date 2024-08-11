#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertSort(vector<int>& vec){
    const int n = vec.size();
    for(int i = 1; i < n; ++i){
        int key = vec[i], j = i-1;
        while(j>=0&&vec[j]>key){
            vec[j+1] = vec[j];
            --j;
        }
        vec[j+1] = key;
    }
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 2, 6, 1};
    insertSort(vec);
    const int n = vec.size();
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}