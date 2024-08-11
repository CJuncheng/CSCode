#include <stdlib.h>
#include <stdint.h>

void* Malloc(int size){
    const int alignment = 128;
    const int offset =  alignment -1 + sizeof(void*);
    void* ptr = malloc(size+offset);
    if(ptr){
        uintptr_t address = (uintptr_t)ptr;
        uintptr_t aligned_address = (address + offset) & ~(alignment - 1);
        void ** aligned_ptr = (void**) aligned_address;
        aligned_ptr[-1] = ptr;
        return (void*) aligned_address;
    }
    return NULL;
}

void* Free(void* aligned_ptr){
    if(aligned_ptr){
        void** ptr = (void**) aligned_ptr;
        void* old_ptr = ptr[-1];
        free(old_ptr);
    }​
​}


int main(int argc, char *argv[])
{
    int n;
   
    
    return 0;
}
