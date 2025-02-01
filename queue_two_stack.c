#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_empty(int top) {
    return top == -1;
}

void enqueue(int *stack1, int *top1, int *stack2, int *top2, int size) {
        int data;
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        if (*top1 == size - 1) {
                printf("Queue is full\n");
        } else {
                stack1[++(*top1)] = data;
        }
}

int queue_size(int top1, int top2) {
        printf("Size of the queue is : %d\n",(top1 + 1) + (top2 + 1)) ;
}

void dequeue(int *stack1, int *top1, int *stack2, int *top2) {
        int data;
        if (is_empty(*top2)) {
                while (!is_empty(*top1)) {
                stack2[++(*top2)] = stack1[(*top1)--];
                }
        }

        if (is_empty(*top2)) {
                printf("Queue is empty\n");
        } else {
                data = stack2[(*top2)--];
        }
        printf("dequed data : %d\n",data);
}
int size(int top1, int top2) {
        return (top1 + 1) + (top2 + 1);
}
void peek(int *stack1, int top1, int *stack2, int top2) {
        if (is_empty(top1) && is_empty(top2)) {
                printf("Queue is empty\n");
                return;
        }
        if (!is_empty(top2)) {
                printf("Peek element: %d\n", stack2[top2]);
        } else {
                printf("Peek element: %d\n", stack1[0]);
        }
}
void display(int *stack1, int top1, int *stack2, int top2) {
    if (is_empty(top1) && is_empty(top2)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int size_of_queue, choice, data;
    printf("Enter the size of Queue: ");
    scanf("%d", &size_of_queue);

    int *stack1 = (int *)malloc(size_of_queue * sizeof(int));  
    int *stack2 = (int *)malloc(size_of_queue * sizeof(int));  
    int top1 = -1, top2 = -1;

    do {
        printf("\nEnter your choice:\n");
        printf("1) Enqueue\n2) Dequeue\n3) Display \n4) Peek \n5) Size \n6) Is Empty\n7) Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue(stack1, &top1, stack2, &top2, size_of_queue);
                break;
            case 2:
                dequeue(stack1, &top1, stack2, &top2);
                break;
            case 3:
                display(stack1, top1, stack2, top2);
                break;
            case 4: peek(stack1, top1, stack2, top2);
                   break;   
            case 5:queue_size(top1,top2);
                   break;     
            case 6:
                if (is_empty(top1) && is_empty(top2)) {
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
