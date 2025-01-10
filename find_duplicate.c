#include<stdio.h>
#include<string.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of cols: ");
    scanf("%d", &cols);

    getchar();

    char matrix[rows * cols][51];
    int freq[rows * cols];

    printf("Enter the strings:\n");
    for (int i = 0; i < rows * cols; i++) {
        scanf("%s",matrix[i]);
        matrix[i][strcspn(matrix[i], "\n")] = '\0'; 
    }

    for (int i = 0; i < rows * cols; i++) {
        freq[i] = 1; 
    }

    int hasDuplicates = 0;  
    for (int i = 0; i < rows * cols; i++) {
        if (freq[i] == 0) continue; 
        for (int j = i + 1; j < rows * cols; j++) {
            if (strcmp(matrix[i], matrix[j]) == 0) {
                freq[i]++;
                freq[j] = 0;  
                hasDuplicates = 1; 
            }
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    if (hasDuplicates) {
        for (int i = 0; i < rows * cols; i++) {
            if (freq[i] > 0) {
                printf("'%s' - %d \n", matrix[i], freq[i]);
            }
        }
    } else {
        printf("\nNo duplicate elements found.\n");
    }

    return 0;
}

