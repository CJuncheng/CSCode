#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
    int checkFreq; cin >> checkFreq;
    string str; cin >> str;
    vector<pair<int, int>> vec;
    
    int freq = 0, loss = 0;
    string tmp = "";
    for(int i = 0; i < (int)str.size(); ++i){
        if(str[i] == ':'){
            freq = stoi(tmp);
            tmp = "";
            
        } else if(str[i] == ','){
            loss = stoi(tmp); tmp = "";
            vec.push_back({freq, loss});
            
        } else {
            tmp += str[i];
        }
        
        if(i==(int)str.size()-1){
            loss = stoi(tmp); tmp = "";
            vec.push_back({freq, loss});
        } 
    }
    
    vector<pair<int, int>> res;
    sort(vec.begin(), vec.end());
    
    int num = INT_MAX;
    for(int i = 0; i < (int)vec.size(); ++i){
        if(abs(checkFreq-vec[i].first) <num){
            res.clear();
            num = abs(checkFreq-vec[i].first);
            res.push_back(vec[i]);
        } else if(abs(checkFreq-vec[i].first) == num)
            res.push_back(vec[i]);
    }
    double sum = 0;
    for(int i = 0; i < res.size(); ++i)
        sum += res[i].second;
    
    sum /= res.size();
    cout << fixed << setprecision(1) << sum << endl;
    
    return 0;
}