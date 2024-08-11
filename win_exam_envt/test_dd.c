#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* GetMemory(void){
    char* p= "hello world";
    return p;
}


int main(int argc, char *argv[])
{
   char *buf = NULL;
   buf = GetMemory();
   printf(buf);

   return 0;
}
