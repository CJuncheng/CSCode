#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergeArrays(vector<int>& A, vector<int>& B) {
    // 将数组B中的元素合并到数组A中
    for (int i = 0; i < B.size(); i++) {
        A.push_back(B[i]);
    }

    // 对数组A进行升序排序
    sort(A.begin(), A.end());

    // 去除数组A中的重复元素
    A.erase(unique(A.begin(), A.end()), A.end());

    return A;
}

int main() {
    // 初始化数组A和数组B
    vector<int> A = {6, 7, 1};
    vector<int> B = {4, 2, 6};

    // 合并数组A和数组B
    vector<int> mergedArray = mergeArrays(A, B);

    // 输出合并后的数组A
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}