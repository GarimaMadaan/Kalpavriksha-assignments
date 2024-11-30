#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "crud.txt"

typedef struct {
    int id;
    char name[200];
    int age;
} User;

void addUser();
void listUsers();
void modifyUser();
void removeUser();
void initializeFile();

int main() {
    int ch;

    initializeFile();

    while (1) {
        printf("\n--- User Management System ---\n");
        printf("  1. Add New User\n  2. List All Users\n  3. Modify User by ID\n  4. Remove User by ID\n  5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch (ch) {
            case 1:
                addUser();
                break;
            case 2:
                listUsers();
                break;
            case 3:
                modifyUser();
                break;
            case 4:
                removeUser();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addUser() {
    User user;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        printf("File not Found.\n");
        return;
    }
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);
    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully!\n");
}

void listUsers() {
    User user;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    printf("\nUsers\n");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }

    fclose(file);
}

void modifyUser() {
    int idToUpdate, found = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error: Could not open file for reading or writing.\n");
        return;
    }

    printf("Enter User ID to modify: ");
    scanf("%d", &idToUpdate);

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) {
        if (user.id == idToUpdate) {
            found = 1;
            printf("Enter New Name: ");
    		scanf(" %[^\n]s", user.name);
    		printf("Enter Age: ");
    		scanf("%d", &user.age);

        }
        fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User modified successfully!\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", idToUpdate);
    }
}

void removeUser() {
    int idToDelete, found = 0;
    User user;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Could not Open file.\n");
        return;
    }

    printf("Enter User ID to remove: ");
    scanf("%d", &idToDelete);

while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) {
        if (user.id == idToDelete) {
            found = 1;
        } else {
            fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User removed successfully!\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", idToDelete);
    }
}

// Ensure the file exists; create it if necessary
void initializeFile() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error: Could not initialize file.\n");
        exit(1);
    }
    fclose(file);
}

