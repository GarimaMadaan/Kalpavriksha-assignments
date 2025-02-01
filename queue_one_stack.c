#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_empty(int top) {
    return top == -1;
}

void enque(int *stack, int *top, int size) {
    int data;
    printf("Enter data to push: ");
    scanf("%d", &data);
    if (*top == size - 1) {
        printf("Queue is full\n");
        return;         
    }

    if (is_empty(*top)) {
        *top = 0;
    }
    for (int i = *top; i >= 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = data;
    (*top)++;
}

void pop(int *stack, int *top) {
    if (is_empty(*top)) {
        printf("Queue is empty\n");
    } else {
        int data = stack[*top-1];
         {
            (*top)--;
        }
        printf("Dequed element : %d\n",data);
    }
}

void peek(int *stack, int top) {
    if (is_empty(top)) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", stack[top]);
    }
}

void display(int *stack, int top) {
    if (is_empty(top)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = top-1; i >=0 ; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int size(int top) {
    if (is_empty(top)) {
        return 0;
    }
    return top + 1;
}

int main() {
    int size_of_queue, choice, data;
    printf("Enter the size of queue: ");
    scanf("%d", &size_of_queue);

    int *stack = (int *)malloc(size_of_queue * sizeof(int));
    int top = -1; 

    do {
        printf("\nEnter your choice:\n");
        printf("1) Enque\n2) Deque\n3) Display\n4) Peek\n5) Size\n6) Is Empty\n7) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enque(stack, &top, size_of_queue);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                peek(stack,top);
                break;
            case 5:
                printf("Size of the stack is: %d\n", size(top));
                break;
            case 6:
                if (is_empty(top)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 7:
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
