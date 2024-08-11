#include <string>
#include <cstring> 
#include <iostream>

using namespace std;

int* buildNext(const char* P)
{
    int m = strlen(P), j = 0; 
    int* next = new int[m];
    int t = next[0]=-1;
    while(j<m-1) {
        if(t==-1||P[j]==P[t])  //匹配； -1为通配哨兵
            next[++j] = ++t;    
        else t = next[t];  //失配
    }
    return next;
}
/*
int* buildNext(const char* P)
{
    int m = strlen(P), j = 0; 
    int* next = new int[m];
    int t = next[0]=-1;
    while(j<m-1) {
        if(t==-1||P[j]==P[t])  //匹配； -1为通配哨兵
        {
            ++j; ++t;
            next[j] = (P[j]!=P[t]? t : next[t]);
        }
        else t = next[t];  //失配
    }
    return next;
}
*/

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

int main(int argc, char *argv[])
{
    //string t = "acdf", p = "cd";
    //int flag = kmp(t.c_str(), p.c_str());
    //cout << flag << endl;
    //string t = "caccbacbb";
    //buildNext(t.c_str(t))
    string t = "abcdeabcde";
    int* next = buildNext(t.c_str());
    cout << *next << endl;
    cout << *(next+1) << endl;
    cout << *(next+2) << endl;
    cout << *(next+3) << endl;
    cout << *(next+4) << endl;


   
    return 0;
}