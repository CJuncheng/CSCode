#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st; //单调递增栈
    int res = 0;
    heights.push_back(0);
    const int len = heights.size();
    for(int i = 0; i < len; ++i) {
        while(!st.empty() && heights[st.top()]>=heights[i]) // 合并栈
        {
            int h = heights[st.top()];
            st.pop();
            res = max(res, h*(st.empty()? i : i - st.top()-1)); //更新结果
        }
        st.push(i);
    }
    return res;


}

int main (int argc, char* argv[])
{
    vector<int> iVec = {2, 1, 5, 6, 2, 3};
    int ret = largestRectangleArea(iVec);
    cout << ret << endl;   // 返回 1
    return 0;
}