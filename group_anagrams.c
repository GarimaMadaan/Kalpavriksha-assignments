#include <stdio.h>

int stringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int stringCompare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void stringCopy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void sortString(char *str) {
    int len = stringLength(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void groupAnagrams(char strs[][101], int strsSize) {
    if (strsSize == 0) 
    {
        printf("[]\n");
        return;
    };

    char sortedStrs[strsSize][101];
    int visited[strsSize];

    for (int i = 0; i < strsSize; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < strsSize; i++) {
        stringCopy(sortedStrs[i], strs[i]);
        sortString(sortedStrs[i]);
    }

    printf("[");
    for (int i = 0; i < strsSize; i++) {
        if (visited[i]) continue;

        printf("[\"%s\"", strs[i]);
        visited[i] = 1;

        for (int j = i + 1; j < strsSize; j++) {
            if (!visited[j] && stringCompare(sortedStrs[i], sortedStrs[j]) == 0) {
                printf(",\"%s\"", strs[j]);
                visited[j] = 1;
            }
        }
        printf("]");

        int remaining = 0;
        for (int k = i + 1; k < strsSize; k++) {
            if (!visited[k]) remaining++;
        }
        if (remaining > 0) printf(",");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char strs[n][101];
    for (int i = 0; i < n; i++) {
        strs[i][0] = '\0';
    }
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);
    }

    groupAnagrams(strs, n);

    return 0;
}
