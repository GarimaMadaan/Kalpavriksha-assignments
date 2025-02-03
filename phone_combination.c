#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void find_all_digits(int idx, char *digits, int size, char **map, char *result, int result_size){
    if(size == 0){
        return;
    }
    if(idx == size){
        result[idx] = '\0';
        printf("%s", result);
        printf("\n");
        return;
    }
    char ch = digits[idx];
    char *str = map[ch - '0'];

    for(int i = 0; i < strlen(str); i++){
        result[result_size] = str[i];
        find_all_digits(idx + 1, digits, size, map, result, result_size + 1);
    }
}

int main(){
    int size;
    printf("Enter the size of the string : ");
    scanf("%d",&size);
    char * digits = (char *)malloc(size*sizeof(char));
    getchar();
    scanf("%s",digits);
    char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char *result = (char *)malloc(10 * sizeof(char));

    find_all_digits(0,digits,size,map,result,0);

}