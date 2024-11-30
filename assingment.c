#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluateExpression(const char* expression, int* error);
int evaluateTerm(const char** expr, int* error);
int isDigit(const char** expr, int* error);

int main() {
    char expression[50];
    int error = 0;
    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression, &error);

    if (error) {
        if (error == 1)
            printf("Error: Division by zero.\n");
        else
            printf("Error: Invalid expression.\n");
    } else {
        printf("Result: %d\n", result);
    }
    return 0;
}
int evaluateExpression(const char* expression, int* error) {
    const char* expr = expression;
    int result = evaluateTerm(&expr, error);

    while (*expr != '\0' && *error == 0) {
        char op = *expr;

        if (op == '+' || op == '-') {
            expr++;
            int term = evaluateTerm(&expr, error);
            if (op == '+') {
                result += term;
            } else {
                result -= term;
            }
        } else if (isspace(op)) {
            expr++;
        } else {
            *error = 2; 
            return 0;
        }
    
    return result;
}

int evaluateTerm(const char** expr, int* error) {
    int result = isDigit(expr, error);
    while (**expr != '\0' && *error == 0) {
        char op = **expr;
        if (op == '*' || op == '/') {
            (*expr)++;
            int digit = isDigit(expr, error);
            if (op == '/') {
                if (digit == 0) {
                    *error = 1;
                    return 0;
                }
                result /= digit;
            } else {
                result *= digit;
            }
        } else if (isspace(op)) {
            (*expr)++;
        } else {
            break;
        }
    }
    return result;
}
int isDigit(const char** expr, int* error) {
    int num = 0;

    while (isspace(**expr)) {
        (*expr)++;
    }
    if (isdigit(**expr)) {
        while (isdigit(**expr)) {
            num = num * 10 + (**expr - '0');
            (*expr)++;
        }
    } else {
        *error = 2; 
    }
    return num;
}
