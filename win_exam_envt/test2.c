

#include "stdio.h"


#pragma pack(push) 
#pragma pack(2)     
struct MyPackedData
{
    char Data1;
    int* Data2;
    short Data3;
};
#pragma pack(pop)  

struct StructType {
    char Data1;
    int* Data2;
    short Data3;
} __attribute__((aligned(2))); 


struct StructType2 {
    int a;
    alignas(8) char b;
}; // 将MyStruct结构体的对齐方式设置为8字节

int main(int argc, char *argv[])
{
    struct StructType2 obj;

    printf("%d\n", sizeof(obj));

    return 0;
}