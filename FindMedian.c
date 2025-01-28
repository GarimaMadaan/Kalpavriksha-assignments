#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

Node *createList(char *input) {
    Node *head = NULL;
    Node *current = NULL;
    char *token = strtok(input, " ");
    while (token != NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->value = atoi(token);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }
        token = strtok(NULL, " ");
    }
    return head;
}

void printLinkedList(Node *head) {
    Node *current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int find_count(Node *head) {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

float find_median(Node *head, int count) {
    Node *temp = head;
    int mid = count / 2;
    float median = 0;
    for (int i = 0; i < mid-1; i++) {
        temp = temp->next;
    }
    if (count % 2 == 0) {
        median = (temp->value + temp->next->value) / 2.0;
    } else {
        median = temp->value;
    }
    return median;
}

Node *split(Node *head) {
    int count = find_count(head);
    int mid = count / 2;
    Node *temp = head;
    for (int i = 0; i < mid - 1; i++) {
        temp = temp->next;
    }
    Node *head2 = temp->next;
    temp->next = NULL;
    return head2;
}

Node *merge(Node *first, Node *second) {
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    if (first->value < second->value) {
        first->next = merge(first->next, second);
        return first;
    } else {
        second->next = merge(first, second->next);
        return second;
    }
}

Node *mergeSort(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *head2 = split(head);
    head = mergeSort(head);
    head2 = mergeSort(head2);
    return merge(head, head2);
}

Node *mergeTwoLists(Node *head1, Node *head2) {
    return merge(head1, head2);
}

int main() {
    char input1[1000], input2[1000];
    

    printf("Enter the first list ");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = 0;

    printf("Enter the second list ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = 0;

    Node *head1 = createList(input1);
    Node *head2 = createList(input2);

    printf("First List: ");
    printLinkedList(head1);
    printf("Second List: ");
    printLinkedList(head2);

    Node *mergedHead = mergeTwoLists(head1, head2);

    mergedHead = mergeSort(mergedHead);
    printf("Merged and Sorted List: ");
    printLinkedList(mergedHead);

    int count = find_count(mergedHead);
    
    float ans = find_median(mergedHead, count);
    printf("Median: %.2f\n", ans);

    return 0;
}
