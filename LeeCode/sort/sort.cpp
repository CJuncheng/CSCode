#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "linked_list.h"

using namespace std;

// bubble sort
void bubbleSort(vector<int>& vec, int lo, int hi) // [lo, hi)
{
    while(lo < --hi)
        for(int i = lo; i < hi; ++i)
            if(vec[i] > vec[i+1]) 
                std::swap(vec[i], vec[i+1]);
}

// merge sort: array
/*
void twoWayMerge(vector<int>& vec, int lo, int mi, int hi) // [lo, mi)和[mi, hi)各自有序，lo < mi < hi
{
    int index = lo; // vec对应的索引 [lo, hi)
    int i = 0, lenA = mi - lo;
    vector<int> A(lenA); // A 需要新建
    for(int i=0; i<lenA; ++i) A[i] = vec[lo+i]; //前子向量A = vec[lo, mi)
    int j = mi; //后子向量 vec[mi, hi)
    while(i<lenA && j<hi)
        vec[index++] = A[i] > vec[j] ? A[i++] : vec[j++];
    while(i<lenA) // 后子向量 vec[mi, hi)先耗尽
        vec[index++] = A[i++];  //若前子向量先耗尽，vec直接保持后子向量的内容
}
*/

void twoWayMerge(vector<int>& vec, int lo, int mid, int hi) // [lo, mi)和[mi, hi)各自有序，lo < mi < hi
{
    vector<int> tmpVec(hi-lo);
    int index = 0, i = lo, j = mid;
    while(i<mid && j < hi)
        tmpVec[index++] = vec[i]>vec[j] ? vec[i++] : vec[j++];
    while(i<mid) tmpVec[index++] = vec[i++];
    while(j < hi) tmpVec[index++] = vec[j++];
    for(int i = 0; i < hi-lo; ++i)
        vec[lo+i] = tmpVec[i];
}

void mergeSort(vector<int>& vec, int lo, int hi)
{
    if(hi-lo < 2) return;
    int mi = (lo+hi)/2; //以中点为界
    mergeSort(vec, lo, mi); mergeSort(vec, mi, hi); //分别排序
    twoWayMerge(vec, lo, mi, hi); //归并
}

// merge sort: list
ListNode* twoWayMerge(ListNode* list1, ListNode* list2) { //list1, list2各自有序
    ListNode dummyHead(0);
    ListNode* cur = &dummyHead;
    while(list1 && list2){
        ListNode* &tmpNode = list1->val < list2->val ? list1 : list2;
        cur = cur->next = tmpNode;
        tmpNode = tmpNode->next;
    }
    cur->next = list1 ? list1 : list2;
    return dummyHead.next; 
}

ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;
    fast = slow->next, slow->next = nullptr; // 切链
    return twoWayMerge(mergeSort(head), mergeSort(fast));
}

// selection sort
void selectionSort(vector<int>& vec, int lo, int hi) // [lo, hi)
{
    while(lo < --hi){
        int mx = hi, last = hi; // mx 对应[lo, hi]中的最大者的索引
        while(lo < last--) 
            if(vec[last]>vec[mx]) mx = last;
        swap(vec[mx], vec[hi]); //将[hi]与[lo, hi]中的最大者交换
    }   
}

//insertion sort
void insertionSort(vector<int>& vec, int lo, int hi) // [lo, hi)
{
    for(int i = lo+1; i < hi; ++i){
        int key = vec[i], j = i-1;
        while(j>=lo&&vec[j]>key) {
            vec[j+1] = vec[j]; 
            --j;
        }
        vec[j+1] = key;
    }
}

// shell sort
void shellSort(vector<int>& vec, int lo, int hi)
{
    int len = hi - lo;
    for(int inc = len/2; inc>0; inc /= 2){
        for(int i = lo + inc; i < hi; ++i){ // 每一趟采用插入排序
            int key = vec[i], j = i - inc;
            for(; j>=lo&&vec[j]>key; j-=inc)
                vec[j+inc] = vec[j];
            vec[j+inc] = key;
        }
    }
}


// quick sort
// https://www.bilibili.com/video/BV1at411T75o/?spm_id_from=333.337.search-card.all.click&vd_source=7e207334419dc8142fdc0d30691a9168
int partition(vector<int>& vec, int lo, int hi) // [lo, hi)
{   
    swap(vec[lo], vec[lo+rand()%(hi-lo)]); //任选一个元素与首元素交换, rand()*(hi-lo)取值[0, hi-lo-1]
    --hi;
    int pivotValue = vec[lo];  //以首元素为候选轴点——经以上交换，等效于随机选取
    while(lo<hi){ //从向量的两端交替地向中间扫描
        while(lo<hi) 
            if(pivotValue < vec[hi]) --hi; // hi直接向左移动
            else { vec[lo++] = vec[hi]; break;} //vec[hi]移到lo, lo向前移动一步
        while(lo<hi)
            if(pivotValue > vec[lo]) ++lo;
            else { vec[hi--] = vec[lo]; break;}
    } //assert: lo == hi 
    vec[lo] = pivotValue; //将备份的 pivotValue 记录置于前、后子向量之间
    return lo; //返回 pivot
}
void quickSort(vector<int>& vec, int lo, int hi) // [lo, hi)
{
    if(hi-lo < 2) return;
    int pivot = partition(vec, lo, hi); //在[lo, hi)内构造轴点
    quickSort(vec, lo, pivot);  //[lo, pivot)
    quickSort(vec, pivot+1, hi); //[pivot+1, hi)  
}

// heap sort
// https://www.bilibili.com/video/BV1fp4y1D7cj/?spm_id_from=333.788&vd_source=7e207334419dc8142fdc0d30691a9168

/* 维护某一节点 idx 的堆性质: O(logn)
 * @param vec : 存储堆的向量
 * @param inx : 待维护节点的下标， inx < hi
 */
void heapify(vector<int>& vec, int idx, int end)   // idx < end
{
    int largest = idx, left = 2*idx+1, right = 2*idx+2;
    if(left < end && vec[largest] < vec[left]) largest = left;
    if(right < end && vec[largest] < vec[right]) largest = right; // 此时，largest为三个点最大值的下标
    if(largest!=idx) {
        swap(vec[idx], vec[largest]);
        heapify(vec, largest, end);
    }
}

// O(nlogn)
void heapSort(vector<int>& vec) // [lo, hi)
{
    const int len = vec.size();
    // build heap: O(N), 将无序数组调整为有序的大顶堆, 下表为0的位置对应最大值
    for(int i = len/2-1; i >=0; --i) // 初始化，i从最后一个父节点开始调整
        heapify(vec, i, len);
    // sort
    for(int end = len - 1; end > 0; --end) // i = lo 时，就剩一个元素不用管
    {
        swap(vec[0], vec[end]); // 堆顶元素和最后一个元素交换
        heapify(vec, 0, end); // 维护剩余vec元素的大堆性质
    }
}

// bucket sort
ListNode* insert(ListNode* head, int val)
{
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode* prev = &dummyHead, *cur = head;
    while(cur && cur->val <= val){
        prev = cur;
        cur = cur->next;
    }
    ListNode* newNode = new ListNode(val);
    prev->next = newNode;
    newNode->next = cur;
    return dummyHead.next;
}

void bucketSort(vector<int>& vec, int lo, int hi) // [lo, hi)
{
    //const int BUCKET_NUM = 5;
    const int maxValue = *(max_element(vec.begin()+lo, vec.begin()+hi));
    const int minValue = *(min_element(vec.begin()+lo, vec.begin()+hi));
    const int BUCKET_NUM = maxValue-minValue+1;
    vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
    for(int i = lo; i < hi; ++i){
        //int index = vec[i]/BUCKET_NUM;
        int index = vec[i]-minValue;
        ListNode* head = buckets[index];
        buckets[index] = insert(head, vec[i]);
    }
    ListNode* head = buckets[0];
    for(int j = 1; j < BUCKET_NUM; ++j)
        head = twoWayMerge(head, buckets[j]);
    for(int i = lo; i < hi; ++i){
        vec[i] = head->val;
        head = head->next;
    }
}

// counting sort
void countingSort(vector<int>& vec, int lo, int hi)
{
    int max = vec[lo];
    for(int i = lo+1; i < hi; ++i)
        if(vec[i]>max) max = vec[i]; // 找到[lo, hi)中最大值
    vector<int> output(hi-lo), count(max+1);
    for(int i = lo; i < hi; ++i)
        ++count[vec[i]];
    for(int j = 1; j < max + 1; ++j)
        count[j] += count[j-1];
    for(int i = hi-1; i>=lo; --i){
        output[count[vec[i]]-1] = vec[i];
        --count[vec[i]];
    }
    for(int i = lo; i < hi; ++i) 
        vec[i] = output[i-lo];     
}

// radix sort
void radixSort(vector<int>& vec, int lo, int hi)
{
    int max = vec[lo];
    for(int i = lo+1; i < hi; ++i)
        if(vec[i]>max) max = vec[i]; // 找到[lo, hi)中最大值
    for(int exp = 1; max/exp > 0; exp*=10) // 按指数 exp 进行排序，exp 按个位。。。
    {
        vector<int> output(hi-lo), buckets(10); // buckets记录对应桶中数据的次数
        for(int i = lo; i < hi; ++i) 
            ++buckets[vec[i]/exp%10];
        for(int j = 1; j < 10; ++j) // 更改buckets[i]。目的是让更改后的buckets[i]的值，是该数据在output[]中的位置。
            buckets[j]+=buckets[j-1];
        for(int i = hi-1; i>=lo; --i){  // 将数据存储到临时数组output中
            output[buckets[vec[i]/exp%10] - 1] = vec[i];
            --buckets[vec[i]/exp%10];
        }
        for(int i = lo; i < hi; ++i) 
            vec[i] = output[i-lo];        
    }
}



void printOneDegreeVector(const vector<int>& vec){
    cout << "Result: " << endl;
    for(auto& val : vec)
        cout << val << " ";
    cout << endl;
}

void printTwoDegreeVector(const vector<vector<int>>& matrix){
    cout << "Result: " << endl;
    for(auto& vec : matrix){
        for(auto& val : vec)
            cout << val << " ";
        cout << endl;
    }
}

int main (int argc, char* argv[])
{
    vector<int> vec1 = {5, 2, 7, 4, 6, 3, 1};
    //bubbleSort(vec1, 0, A.size());
    vector<int> vec2 = {6, 2, 2, 7, 2, 5, 8, 1, 12, 1, 0, 1};
    mergeSort(vec2, 0, vec2.size());
    //selectionSort(vec2, 2, vec2.size());
    //insertionSort(vec2, 2, vec2.size());
    //heapSort(vec2);
    //shellSort(vec2, 0, vec2.size());
    //quickSort(vec2, 2, vec2.size());
    vector<int> vec3 = {11, 9, -1, 8, 17, 19, 13, 1, 24, 12, 10, 3};
    //bucketSort(vec3, 0, vec3.size());

    vector<int> vec4 = {53, 3, 542, 748, 14, 214, 154, 63, 616};
    //countingSort(vec4, 2, vec4.size());
    
    //radixSort(vec4, 0, vec4.size());

    printOneDegreeVector(vec2);
    return 0;
}