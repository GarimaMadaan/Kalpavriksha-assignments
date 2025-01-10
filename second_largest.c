#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char words[MAX][MAX];
    int wordCount = 0;
    int i = 0, j = 0;
    int maxlen = 0, second_max_len = 0, max_index = -1, second_max_index = -1;

    char sentence[100];
    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    while (sentence[i] != '\0') {
        while (sentence[i] == ' ') {
            i++;
        }
        if (sentence[i] != '\0') {
            j = 0;
            while (sentence[i] != ' ' && sentence[i] != '\0') {
                words[wordCount][j++] = sentence[i++];
            }
            words[wordCount][j] = '\0';
            wordCount++;
        }
    }

    if (wordCount < 2) {
        printf("Not enough words to find the second largest.\n");
        return 0;
    }

    for (i = 0; i < wordCount; i++) {
        int len = strlen(words[i]);
        if (len > maxlen) {
            second_max_len = maxlen;
            second_max_index = max_index;
            maxlen = len;
            max_index = i;
        } else if (len > second_max_len && len < maxlen) {
            second_max_len = len;
            second_max_index = i;
        }
    }

    if (second_max_index != -1) {
        printf("Second largest string is: %s\n", words[second_max_index]);
    } else {
        printf("Second largest string not found.\n");
    }

    return 0;
}

