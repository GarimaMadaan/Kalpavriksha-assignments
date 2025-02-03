#include<stdio.h>
void generate_parentheses_util(int pos, int n, int open, int close, char* str) {
    if (open==n && close==n) {
        printf("%s\n", str);
        return;
    } else {
        if (open > close) {
            str[pos] = ')';
            generate_parentheses_util(pos+ 1,n, open,close + 1, str);
        }
        if (open < n) {
            str[pos] = '(';
            generate_parentheses_util(pos + 1, n,open + 1,close, str);
        }
    }
}

void generate_parentheses(int size) {
    if (size > 0) {
        char str[2 * size + 1];
        str[2 *size] ='\0';
        generate_parentheses_util(0, size, 0, 0, str);
    }
}
int main(){
    int size;
    printf("Enter the number of parentisis : ");
    scanf("%d",&size);
    generate_parentheses(size);
}