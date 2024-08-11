#include <string.h>
#include <stdio.h>

void swap(char* str1, char* str2){
    char tmp[16];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}

void quickSort(char arr[][16], int left, int right)  // [,]
{
    if (left>= right) return;
    char* pivotValue = arr[left]; //  pivot = left;  以首元素为候选轴点
    int i = left, j = right;
    while(i<j){
        while(i<j && strcmp(arr[j], pivotValue)>=0) --j; // 从右向左找到第一个小于 pivotValue 的位置 j
        while(i<j && strcmp(arr[i], pivotValue)<=0) ++i; // 从左向右找到第一个大于 pivotValue 的位置 i
        if(i<j) swap(arr[i], arr[j]); // 当 i==j 时，退出
    }
    swap(arr[i], arr[left]); //相遇点与轴点的值交换
    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);
}

int removeDuplicates(char arr[][16], int n)
{
    int l = 0;
    for(int r = 1; r < n; ++r){
        if(strcmp(arr[l], arr[r]) != 0){
            ++l;
            strcpy(arr[l], arr[r]);
        }
    }
    return ++l;
}

int main(int argc,char* argv[]){
    char outBuf[][16] = {"00001001", "00ABCD00", "FFFFFAAB", "FFFFFAAB", "00ABCD00"};
    int outputSize = 5;
    quickSort(outBuf, 0, 4);
    outputSize = removeDuplicates(outBuf, outputSize);
    for (int i = 0; i < outputSize; ++i) 
        printf("%s\n", outBuf[i]); 
    return 0;
}