

#include <stdio.h>

int main(int argc, char* argv[]){
    char* str = "0123456789";
    printf("%x\n", *(int*)str);     
    return 0;
}

