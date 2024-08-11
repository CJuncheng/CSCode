#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// https://blog.csdn.net/jin739738709/article/details/122992753
// https://www.cnblogs.com/sigma0/p/10837760.html

void* aligned_malloc(size_t size, size_t alignment){
    // 分配足够的内存, 这里的算法很经典, 早期的STL中使用的就是这个算法 

    const size_t psize = sizeof(void*);

    // alignment - 1 + pointerSize这个是FreeBlock内存对齐需要的内存大小  
	// 前面的例子sizeof(T) = 20, __alignof(T) = 16,  
	// g_MaxNumberOfObjectsInPool = 1000  
	// 那么调用本函数就是alignedMalloc(1000 * 20, 16)  
	// 那么alignment - 1 + pointSize = 19 
    const size_t request_size = size + alignment - 1 + psize;
    // 分配的实际大小就是20000 + 19 = 20019  
    void* raw = (void*)malloc(request_size);
    uintptr_t start = (uintptr_t)raw + psize;
    void** aligned = (void**) ( (start+alignment-1) & ~(alignment-1));
    aligned[-1] = raw;
    return aligned;
}

void aligned_free(void* aligned){
    void* raw = ((void**)aligned)[-1];
    free(raw);
}

bool isAligned(void* data, int alignment)
{ 
	return ((uintptr_t)data & (alignment - 1)) == 0;
}

int main(int argc, char* argv[])
{
    /*
    const int n = 20; // 分配的内存个数
	int* data = (int*)aligned_malloc(sizeof(int)*n, 32);
    if (isAligned(data, 32)) {
        printf("isAligned\n");
	}
    */
   
    void * p[5];
    for(int i = 0; i < 5; ++i) {
        p[i] = aligned_malloc(sizeof(int)*3, 32);
        printf("%p\n", p[i]);
        //uintptr_t address = (uintptr_t)p[i]; // 将地址转换为uintptr_t类型
        printf("Address of x in decimal: %lu\n", p[i]); // 以十进制形式输出地址
    }

    for(int i = 0; i < 5; ++i)
        aligned_free(p[i]);

   /*
    void *p = malloc(2);
    printf("0x%p\n", p);
    uintptr_t address = (uintptr_t)p; // 将地址转换为uintptr_t类型
    printf("Address of x in decimal: %lu\n", address); // 以十进制形式输出地址

    void *p2 = malloc(3);
    printf("0x%p\n", p2);
    uintptr_t address2 = (uintptr_t)p2; // 将地址转换为uintptr_t类型
    printf("Address of x in decimal: %lu\n", address2); // 以十进制形式输出地址
    
    free(p2);
    free(p);

    */







    /*
    void * p[n];
    for(int i = 0; i < n; ++i) {
        p[i] = aligned_malloc(i, 32); // 16字节对齐
        printf("%p\n", p[i]);
    }

    for(int i = 0; i < n; ++i)
        aligned_free(p[i]);
    */
    return 0;
}