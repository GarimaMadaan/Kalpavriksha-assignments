#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *input = (char *)malloc(100000 *sizeof(char));
    fgets(input,100000,stdin);
    input[strcspn(input,"\n")] = '\0';
    char word[100];
    int index = 0,word_idx = 0;
    int size =0;
    char **arr = (char **)malloc(100000 * sizeof(char *));
    while(input[index] != '\0'){
        if(input[index] != ' ' && input[index] != '\n'){
            word[word_idx++] = input[index];
        }
        else if(word_idx>0){
            word[word_idx] = '\0';
            arr[size] = (char *)malloc((word_idx + 1) * sizeof(char));
            strcpy(arr[size++],word);
            word_idx = 0;
        }
        index++;
    }
    

    int max_ans = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int ch[26] = {0};
            int duplicate = 0;
            for(int k = 0;k<strlen(arr[i]);k++){
                ch[arr[i][k] -'a'] = 1;
            }
            for(int k = 0;k<strlen(arr[j]);k++){
                if(ch[arr[j][k] -'a'] == 1){
                    duplicate  = 1;
                    break;
                }
            }
            if(duplicate  == 0)
            {
                int product = strlen(arr[i]) * strlen(arr[j]);
                if (product > max_ans) {
                    max_ans = product;
                }
            }
        }
    }

    printf("%d\n", max_ans);
    return 0;
}