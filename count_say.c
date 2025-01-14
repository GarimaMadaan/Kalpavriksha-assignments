#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void stringCopy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void runLengthEncode(char *input, char *output) {
    int i = 0, index = 0, length = stringLength(input);
    while (i < length) {
        char currentChar = input[i];
        int count = 0;
        while (i < length && input[i] == currentChar) {
            count++;
            i++;
        }
        output[index++] = count + '0';
        output[index++] = currentChar;
    }
    output[index] = '\0';
}

char* countAndSay(int n) {
    if (n <= 0) return NULL;
    char *current = malloc(5000);
    char *next = malloc(5000);
    current[0] = '1';
    current[1] = '\0';
    for (int i = 2; i <= n; i++) {
        runLengthEncode(current, next);
        stringCopy(current, next);
    }
    free(next);
    return current;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    char *result = countAndSay(n);
    printf("countAndSay(%d) = %s\n", n, result);
    free(result);
    return 0;
}
