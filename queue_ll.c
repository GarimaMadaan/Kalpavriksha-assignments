#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue{
    int data;
    struct queue* next;
}Queue;

bool is_Empty(Queue *front,Queue *rear){
    if(front == NULL && rear == NULL){
        return true;
    }
    else {
        return false;
    }
}

void enqueue(Queue **front,Queue **rear){
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    Queue *newNode = (Queue *) malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    if(*front == NULL && *rear == NULL){
        *front = *rear = newNode;
    }
    else{
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(Queue **front,Queue **rear){
    if(is_Empty(*front,*rear)){
        printf("Queue is Empty");
    }
    else{
        int data = (*front)->data;
        Queue *temp = *front;
        *front = (*front)->next;
        free(temp);
        printf("Enqued Data : %d\n",data);
    }
}
void peek(Queue *front,Queue *rear){
    if(is_Empty(front,rear)){
        printf("Queue is Empty");
    }
    else{
        printf("Data at the front : %d",front->data);
    }
}

void size(Queue *front,Queue *rear){
    Queue *temp = front;
    int count =0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Size of the queue : %d ",count);
}
void display(Queue *front,Queue *rear){
    if(is_Empty(front,rear)){
        printf("Queue is Empty");
    }
    else{
    Queue *temp = front;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp ->next;
    }
    }
}

int main(){
    int choice;
    Queue *front = NULL;
    Queue *rear = NULL;
    do{
    printf("Enter your choice :");
    printf("\n1) Enqueue \n2) Dequeue \n3) Peek \n4) Display \n5) Is Empty \n6) Size \n7) Exit \n ");
    scanf("%d",&choice);
    
        switch(choice){
            case 1:
                    enqueue(&front,&rear);
                    break;
            case 2:
                    dequeue(&front,&rear);
                    break;
            case 3:
                    peek(front,rear);
                    break;
            case 4:
                    display(front,rear);
                    break;  
            case 5:
                    if(is_Empty(front,rear)){
                        printf("Queue is Empty\n");
                    }        
                    else{
                        printf("Queue is not empty\n");
                    }
                    break;

            case 6: size(front,rear);
                    break;        

            case 7: return 0;
            default: 
                    printf("Invalid Input");
                    break;
        }
    }while(choice != 7);
    return 0;
}
