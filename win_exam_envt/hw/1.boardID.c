
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <stdio.h>
#include <string.h>
#include "securec.h"

#define STR_LEN 16
#define ARR_MAX_LEN 1000

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

// 待实现函数，请在此填入答题代码。
// 生成的信息列表存于outBuf中，maxOutBufLen是最大数组长度，返回值为实际长度。
static int GetAllFault(char **arrayA, int arrayASize, char **arrayB, int arrayBSize,
                       char outBuf[][STR_LEN], int maxOutBufLen)
{
    for (int i = 0; i < arrayASize; i++) strcpy(outBuf[i], arrayA[i]);
    for (int i = 0; i < arrayBSize; i++) strcpy(outBuf[arrayASize+i],arrayB[i]);
    int outputSize = arrayASize+arrayBSize;
    quickSort(outBuf, 0, outputSize-1);
    return removeDuplicates(outBuf, outputSize);
}

int main(void)
{
    int arrayASize = 0;
    if (scanf_s("%d", &arrayASize) != 1) { return -1; }

    char bufA[ARR_MAX_LEN][STR_LEN];
    char *arrayA[ARR_MAX_LEN];
    for (int i = 0; i < arrayASize; i++) {
        if (scanf_s("%s", &bufA[i], STR_LEN) != 1) { return -1; }
        arrayA[i] = bufA[i];
    }

    int arrayBSize = 0;
    if (scanf_s("%d", &arrayBSize) != 1) { return -1; }

    char bufB[ARR_MAX_LEN][STR_LEN];
    char *arrayB[ARR_MAX_LEN];
    for (int i = 0; i < arrayBSize; i++) {
        if (scanf_s("%s", &bufB[i], STR_LEN) != 1) { return -1; }
        arrayB[i] = bufB[i];
    }

    char outBuf[ARR_MAX_LEN * 2][STR_LEN];
    int outputSize = GetAllFault(arrayA, arrayASize, arrayB, arrayBSize, outBuf, ARR_MAX_LEN * 2);

    printf("[");
    for (int i = 0; i < outputSize; i++) {
        if (i == 0) {
            printf("%s", outBuf[i]);
        } else {
            printf(" %s", outBuf[i]);
        }
    }
    printf("]");

    return 0;
}
