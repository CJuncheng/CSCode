#include <stdio.h>
main(){
    char *p="abcdefgh", *r;
    long *q;
    q=(long *)p;
    q++;
    r=(char *)q;
    printf("%s\n", r);

    return 0;
}