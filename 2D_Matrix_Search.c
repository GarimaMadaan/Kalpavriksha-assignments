#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchTarget(int **matrix, int rows, int cols, int target) {
    int i = 0;
    int j = cols - 1;
    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    int rows, cols, target,i=0,j=0;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of cols: ");
    scanf("%d", &cols);
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool found = searchTarget(matrix, rows, cols, target);
    if (found) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

