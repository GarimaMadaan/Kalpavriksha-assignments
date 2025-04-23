#include <stdio.h>
#include <string.h>

void processString(char *str, char *result) {
    int len = strlen(str);
    int index = 0; 
    
    for (int i = 0; i < len; i++) {
        if (str[i] == '#') {
            if (index > 0) {
                index--;
            }
        } else {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
}

int main() {
    char s[201], t[201], result_s[201], result_t[201];

    fgets(s, 201, stdin);
    s[strcspn(s, "\n")] = '\0';
    fgets(t, 201, stdin);
    t[strcspn(t, "\n")] = '\0';

    processString(s, result_s);
    processString(t, result_t);

    if (strcmp(result_s, result_t) == 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
