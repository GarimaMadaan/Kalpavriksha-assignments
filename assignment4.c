#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int rows, cols,i,j;


    printf("Enter the number of rows (1 = R = 10): ");
    scanf("%d", &rows);
    if (rows < 1 || rows > 10) {
        printf("Invalid number of rows. Exiting program.\n");
        return 1;
    }

    printf("Enter the number of columns (1 = C = 101): ");
    scanf("%d", &cols);
    if (cols < 1 || cols > 101) {
        printf("Invalid number of columns. Exiting program.\n");
        return 1;
    }

    char names[rows * cols][51]; 
    getchar(); 


    printf("Enter the names (max 50 characters each):\n");
    for (i = 0; i < rows * cols; i++) {
        printf("Name[%d]: ", i + 1);
        fgets(names[i], 51, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; 
    }

    printf("\nThe names in matrix format:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%-15s", names[i * cols + j]);
        }
        printf("\n");
    }
    
    int vowel_count = 0;
    char longest_name[51] = "";
    for (i = 0; i < rows * cols; i++) {
        if (is_vowel(names[i][0])) {
            vowel_count++;
        }
        if (strlen(names[i]) > strlen(longest_name)) {
            strcpy(longest_name, names[i]);
        }
    }


    printf("\nNumber of names starting with a vowel: %d\n", vowel_count);

    // Output: Longest name
    printf("The longest name: %s\n", longest_name);

    return 0;
}

