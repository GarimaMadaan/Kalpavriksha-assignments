#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int stack_size, *queue_1, *queue_2, front_1 = -1, rear_1 = -1, front_2 = -1, rear_2 = -1, count = 0;

bool is_empty() {
    return count == 0;
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void enqueue_in_queue1(int value) {
    if (rear_1 == stack_size - 1) {
        printf("Overflow.\n");
    } else if (front_1 == -1 && rear_1 == -1) {
        front_1 = rear_1 = 0;
        queue_1[rear_1] = value;
    } else {
        rear_1++;
        queue_1[rear_1] = value;
    }
}

void enqueue_in_queue2(int value) {
    if (rear_2 == stack_size - 1) {
        printf("Overflow.\n");
    } else if (front_2 == -1 && rear_2 == -1) {
        front_2 = rear_2 = 0;
        queue_2[rear_2] = value;
    } else {
        rear_2++;
        queue_2[rear_2] = value;
    }
}

int dequeue_in_queue1() {
    return queue_1[front_1++];
}

int dequeue_in_queue2() {
    return queue_2[front_2++];
}

void push(int *queue1, int *front1, int *rear1, int *queue2, int *front2, int *rear2) {
    int value;
    printf("Enter the data ");
    scanf("%d", &value);
    enqueue_in_queue1(value);
    count++;
}

void pop(int *queue1, int *front1, int *rear1, int *queue2, int *front2, int *rear2) {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }

    while (*front1 != *rear1) {
        enqueue_in_queue2(dequeue_in_queue1());
    }

    printf("Popped element is: %d\n", dequeue_in_queue1());
    count--;
    swap(front1, front2);
    swap(rear1, rear2);
}

void peek(int *queue1, int *front1, int *rear1, int *queue2, int *front2, int *rear2) {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }

    while (*front1 != *rear1) {
        enqueue_in_queue2(dequeue_in_queue1());
    }

    printf("Top element is: %d\n", queue_1[*front1 + 1]);
}

void size() {
    printf("Size of stack is: %d\n", count);
}

void display(int *queue1, int *front1, int *rear1, int *queue2, int *front2, int *rear2) {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements in the stack are:\n");

    for (int i = *rear1; i >= *front1; i--) {
        printf("%d ", queue_1[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter the size of the stack:\n");
    scanf("%d", &stack_size);

    queue_1 = (int *)malloc(stack_size * sizeof(int));
    queue_2 = (int *)malloc(stack_size * sizeof(int));

    do {
        printf("\nEnter your choice:\n");
        printf("1) Push\n2) Pop \n3) Peek\n4) Display \n5) Size\n6) Is Empty\n7) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(queue_1,&front_1,&rear_1,queue_2,&front_2,&rear_2);
                break;
            case 2:
                pop(queue_1,&front_1,&rear_1,queue_2,&front_2,&rear_2);
                break;
            case 3:
                peek(queue_1, &front_1,&rear_1,queue_2,&front_2,&rear_2);
                break;
            case 4:
                display(queue_1,&front_1,&rear_1,queue_2,&front_2,&rear_2);
                break;
            case 5:
                size();
                break;
            case 6:
                if (is_empty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
