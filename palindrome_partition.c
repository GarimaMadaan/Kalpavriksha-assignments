#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool is_palindrome(char *str,int start,int end){
    while(start<= end){
        if(str[start++] != str[end--]){
            return false;
        }
    }
    return true;
}
void solve(char *str, int index, int size, char *path, int start) {
    if (index == size) {
        for (int i = 0; i < start; i++) {
            printf("%c", path[i]);
        }
        printf("\n");
        return;
    }
    for (int i = index; i < size; i++) {
        if (is_palindrome(str, index, i)) {
            int len = i - index + 1;
            strncpy(path + start, str + index, len);
            path[start + len] = ' ';
            solve(str, i + 1, size, path, start + len + 1);
        }
    }
}
int main(){
    int size ;
    printf("Enter the size of the string : ");
    scanf("%d",&size);
    size  = size+1;
    char str[size];
    char path[size];
    scanf("%s",str);
    solve(str,0,size,path,0);

}