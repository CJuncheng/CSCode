#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={0,1,0,-1,1,0,-1,0};
vector<vector<bool>>visited;
void dfs(int x,int y,char ch,vector<vector<char>>& graph){
    for(int i=0;i<4;i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx<0||nextx>=graph.size()||nexty<0||nexty>=graph[0].size())continue;
        if(!visited[nextx][nexty]&&graph[nextx][nexty]==ch){
            visited[nextx][nexty]=1;
            dfs(nextx,nexty,ch,graph);
        } 
    }
}

int main() {
    int len;
    cin>>len;
    string str="";
    cin>>str;

    int ans=INT_MAX;
    
    for(int k=1;k<len;k++){
        if(len%k==0){
            int m = k,n = len/k;
            int cnt=0;
            vector<vector<char>> graph(m,vector<char>(n));
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    graph[i][j] = str[cnt];
                    cnt++;
                }
            }
            int tmp=0;
            visited=vector<vector<bool>>(m,vector<bool>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!visited[i][j]){
                        visited[i][j]=1;
                        dfs(i,j,graph[i][j],graph);
                        tmp++;
                    }
                }
            }
            ans=min(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
  
}
