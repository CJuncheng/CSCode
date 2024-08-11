#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *RLE_encode(const char *src) {
    int srcLength = strlen(src);
    char *encodedString = (char *)malloc((2 * srcLength + 1) * sizeof(char));
    int encodedIndex = 0;  

    char currentChar = src[0];
    int count = 1;
    for (int i = 1; i < srcLength; i++) {
        if (src[i] == currentChar) {
            count++;
        } else {
            encodedIndex += sprintf(&encodedString[encodedIndex], "%c%d", currentChar, count);
            currentChar = src[i];
            count = 1;
        }
    }
    encodedIndex += sprintf(&encodedString[encodedIndex], "%c%d", currentChar, count);
    encodedString[encodedIndex] = '\0'; 
    if (encodedIndex >= srcLength) { 
        free(encodedString);  
        encodedString = strdup(src);  
    }
    return encodedString;
}

int main() {
    const char *originalString = "AAAAbKKKKKKKKJdEEEEExx";
    char *encodedString = RLE_encode(originalString);
    printf("Encoded string: %s\n", encodedString);
    free(encodedString);

    return 0;
}