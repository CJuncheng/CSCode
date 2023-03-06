#include <iostream>  // size_t
#include <cstring>

// ====================== 蛮力算法 ======================
int bruteForce1(const char* T, const char* P) { //字符串蛮力算法实现1, O(m(n-m+1))时间复杂度
    size_t n = strlen(T), i = 0; //文本串长度、当前接受比对字符的位置
    size_t m = strlen(P), j = 0; //模式串长度、当前接受比对字符的位置
    for(i=0; i < n-m+1; ++i){
        for(j=0; j < m; ++j)
            if(T[i+j] != P[j]) break;
        if(j==m) return i; // found
    } 
    return -1; // not found
}

int bruteForce2(const char* T, const char* P) { //字符串蛮力算法实现2, O(m(n-m+1))时间复杂度
    size_t n = strlen(T), i = 0; //文本串长度、当前接受比对字符的位置
    size_t m = strlen(P), j = 0; //模式串长度、当前接受比对字符的位置
    while(i<n && j<m){
        if(T[i]==P[j]) {++i; ++j;}
        else {
            i+=1-j; j=0; //T回退，P复位
        }
    }
    return j == m ? i-j : -1; //return i-m, found; return n, not found
}

// ====================== KMP算法 ======================
inline
int* buildNext(const char* P)
{
    int m = strlen(P), j = 0; 
    int* next = new int[m];
    int t = next[0]=-1;
    while(j<m-1) {
        if(t==-1||P[j]==P[t])  //匹配； -1为通配哨兵
        {
            //1. 基础版本
            //next[++j] = ++t;     

            //2. 改进版本
            ++j; ++t;
            next[j] = (P[j]!=P[t]? t : next[t]);

        }
        else t = next[t];  //失配
    }
    return next;

}
int kmp(const char* T, const char* P) // O(m+n)时间复杂度
{ 
    int* next = buildNext(P);    //O(m)
    int n = strlen(T), i = 0; //文本串长度、当前接受比对字符的位置
    int m = strlen(P), j = 0; //模式串长度、当前接受比对字符的位置
    while(i<n && j<m){   //O(n)
        if(j==-1||T[i]==P[j]) {++i; ++j;} //若匹配，或P已移出最左侧（两个判断的次序不可交换）
        else j = next[j];  //模式串右移（注意：文本串不用回退）
    }
    delete [] next;
    return j == m ? i-j : -1; //return i-m, found; return n, not found
}

// test
int main (int argc, char* argv[])
{

     const char * TStr = "abcd people";
     const char * PStr = "people";

    int ret = kmp(TStr, PStr);
    std::cout << ret << std::endl;
    return 0;

}
