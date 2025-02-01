#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_empty(int front, int rear) {
    return front == -1 && rear == -1;
}

void push(int *queue, int *front, int *rear, int size) {
    int data;
    printf("Enter data to push: ");
    scanf("%d", &data);
    if (*rear == size - 1) {
        printf("Stack is full\n");
        return;         
    }

    if (is_empty(*front, *rear)) {
        *front = 0;
        *rear = 0;
    } else {
        (*rear)++;
    }
    queue[*rear] = data;
    for (int i = *rear; i > *front; i--) {
        int temp = queue[i];
        queue[i] = queue[i - 1];
        queue[i - 1] = temp;
    }
}

void pop(int *queue, int *front, int *rear) {
    if (is_empty(*front, *rear)) {
        printf("Stack is empty\n");
    } else {
        int data = queue[*front];
        if (*front == *rear) {
            *front = -1;
            *rear = -1;
        } else {
            (*front)++;
        }
        printf("Popped element : %d\n",data);
    }
}

void peek(int *queue, int front, int rear) {
    if (is_empty(front, rear)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", queue[front]);
    }
}

void display(int *queue, int front, int rear) {
    if (is_empty(front, rear)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int size(int front, int rear) {
    if (is_empty(front, rear)) {
        return 0;
    }
    return rear - front + 1;
}

int main() {
    int size_of_stack, choice, data;
    printf("Enter the size of Stack: ");
    scanf("%d", &size_of_stack);

    int *queue = (int *)malloc(size_of_stack * sizeof(int));
    int front = -1, rear = -1;

    do {
        printf("\nEnter your choice:\n");
        printf("1) Push\n2) Pop\n3) Display\n4) Peek\n5) Size\n6) Is Empty\n7) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(queue, &front, &rear, size_of_stack);
                break;
            case 2:
                pop(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                peek(queue, front, rear);
                break;
            case 5:
                printf("Size of the stack is: %d\n", size(front, rear));
                break;
            case 6:
                if (is_empty(front, rear)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 7:
                free(queue);
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
