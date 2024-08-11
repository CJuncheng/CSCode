#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    static bool compare(vector<int>& vec1,vector<int>& vec2){
        if(vec1[0]==vec2[0]){
            return vec1[1]<vec2[1];
        }   
        return vec1[0]<vec2[0];
    }
    int slove(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int result=0;
        int left=intervals[0][0];
        int right=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(right>=intervals[i][1]){
                result++;
                left=intervals[i][0];
                right=intervals[i][1];
            }else if(intervals[i][0]<right){
                result++;
            }else{
                left=intervals[i][0];
                right=intervals[i][1];
            }
        }

        return result+1;
    }
};

int main(){
    vector<vector<int>> vec={{1,2},{2,3}};
    Solution s;
    cout<<s.slove(vec);
    return 0;
}

