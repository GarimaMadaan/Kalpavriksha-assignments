#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256

typedef struct{
    int charcount;
    int index;
} map;

map mp[MAX_CHAR];

void firstNonRepeating(char *str) {
    for(int i = 0; i < MAX_CHAR; i++){
        mp[i].charcount = 0;
        mp[i].index = -1;
    }
    
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        mp[ch].charcount++;
        if (mp[ch].charcount == 1) {
            mp[ch].index = i;
        } else {
            mp[ch].index = -1;
        }
        
        int non_repeating_index = -1;
        for (int j = 0; j < MAX_CHAR; j++) {
            if (mp[j].charcount == 1 && (non_repeating_index == -1 || mp[j].index < non_repeating_index)) {
                non_repeating_index = mp[j].index;
            }
        }

        if (non_repeating_index == -1) {
            printf("-1");
        } else {
            printf("%c", str[non_repeating_index]);
        }
    }
    printf("\n");
}

int main() {
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    firstNonRepeating(str);
    return 0;
}
