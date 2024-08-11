/*
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编
号，根结点编号为1。现在有两个结点a,b。请设计一个算法，求出a和
b点的最近公共祖先的编号。
*/

#include <iostream>
using namespace std;

int commonAncestor(int a, int b){
    while(a!=b){
        if(a >b){
            a = a/2;
        }else {
            b = b/2;
        }
    }
    return a;
}

int main() {
    int a, b; cin >> a >> b;
    int ret = commonAncestor(a, b);
    cout << ret << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")

