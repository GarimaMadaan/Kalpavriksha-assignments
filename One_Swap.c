#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool oneSwap(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 != len2) {
        return false;
    }
    
    int idx[2];
    int diff = 0;
    int idx_cnt = 0;
    
    int i=0;
    for (i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) {
            if (diff == 2) {
                return false;
            }
            idx[idx_cnt++] = i;
            diff++;
        }
    }
    
    if (diff == 0) {
        return true;
    }
    
    if (diff == 2) {
        return (s1[idx[0]] == s2[idx[1]] && s1[idx[1]] == s2[idx[0]]);
    }
    
    return false;
}

int main() {
    char *s1 = (char *)malloc(100 * sizeof(char));
    char *s2 = (char *)malloc(100 * sizeof(char));

    if (s1 == NULL || s2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the first string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = '\0';

    bool swapped = oneSwap(s1, s2);
    if (swapped) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(s1);
    free(s2);
    return 0;
}

