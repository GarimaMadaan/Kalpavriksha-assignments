#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int start, int end) {
    if (start == end) {
        printf("%s ", str);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&str[start], &str[i]);
            permute(str, start + 1, end);
            swap(&str[start], &str[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    
    int len = strlen(str);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                swap(&str[i], &str[j]);
            }
        }
    }

    printf("All permutations:\n");
    permute(str, 0, len - 1);

    return 0;
}

