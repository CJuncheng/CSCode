#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selecSort(vector<int>& vec){
    int n = vec.size();
    while(--n){
        int mx = n, last = n;
        while(last--){
            if(vec[last]>vec[mx]) mx = last;
        }
        swap(vec[mx], vec[n]);
    }
}

int main (int argc, char* argv[]){
    vector<int> vec = {2, 5, 9, 2, 6};
    selecSort(vec);
    const int n = vec.size();
    for(int i = 0; i < n; ++i)
        cout << vec[i] << endl;
}