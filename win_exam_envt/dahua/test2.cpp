#include <stdio.h>
#include <stdlib.h>

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;


int main() {
    char input[100];
    scanf("%s", input);

    int num = stringToInt(input);
    printf("%d\n", num);

    return 0;
}