#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility> // pair
#include <queue>
#include "binary_tree.h"
using namespace std;
/*
// 使用 umap 和优先级队列
struct CompareMore{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.second < rhs.second;
    }
};

inline
void travIn_R(TreeNode* parent, unordered_map<int, int>& umap)
{
    if(parent == nullptr) return;
    travIn_R(parent->left, umap);
    ++umap[parent->val];
    travIn_R(parent->right, umap);
}
vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> umap;
    travIn_R(root, umap);
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMore> priQue(umap.begin(), umap.end());
    vector<int> res;
    res.push_back(priQue.top().first); 
    int frequency = priQue.top().second;
    priQue.pop();
    for(int i = 0; i < umap.size(); ++i){ 
        if(frequency==priQue.top().second){ res.push_back(priQue.top().first); priQue.pop();}
        else break;
    }
    return res;
}
*/

/*
// 中序遍历
int count = 0, maxCount = 0, pre = INT_MIN;
vector<int> res;
inline
void travIn_R(TreeNode* parent)
{
    if(parent == nullptr) return;
    travIn_R(parent->left);
    if(pre == parent->val) ++count;
    else count = 1;
    pre = parent->val;
    if(maxCount == count) res.push_back(parent->val);
    else if(count > maxCount) {
        maxCount = count;
        res.clear(); res.push_back(parent->val);
    }
    travIn_R(parent->right);
}

vector<int> findMode(TreeNode* root) {
    travIn_R(root);
    return res;
}
*/
