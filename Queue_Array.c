#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_Empty(int *queue,int *front,int *rear,int size_of_queue){
    if(*front == -1 && *rear == -1){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int *queue,int *front,int *rear,int size_of_queue){
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    if(*rear == size_of_queue -1){
        printf("Queue is full \n");
    }
    else if(*front == -1 && *rear == -1){
        *front = *rear = 0;
        queue[*rear] = data;
    }
    else{
        (*rear)++;
        queue[*rear] = data;
    }
}

void dequeue(int *queue,int *front,int *rear,int size_of_queue){
    int data;
    if(is_Empty(queue,front,rear,size_of_queue)){
        printf("Queue is Empty\n");
    }
    else if(*front == *rear){
        data = queue[*front];
        *front = *rear = -1;
    }
    else{
        data = queue[*front];
        (*front)++;
    }
    printf("Dequed Data : %d\n",data);
}

void peek(int *queue,int *front,int *rear,int size_of_queue){
    if(is_Empty(queue,front,rear,size_of_queue)){
        printf("Queue is Empty\n");
    }
    else{
        printf("Element at the front of the queue is : %d \n",queue[*front]);
    }
}

void size(int *queue,int *front,int *rear,int size_of_queue){
    if(is_Empty(queue, front, rear, size_of_queue)){
        printf("Size of the queue is : 0\n");
    } else {
        printf("Size of the queue is : %d\n", *rear - *front + 1);
    }
}

void display(int *queue,int *front,int *rear,int size_of_queue){
    if(is_Empty(queue,front,rear,size_of_queue)){
        printf("Queue is Empty\n");
    }
    
    else{
        for(int i =*front;i<*rear+1;i++){
            printf("%d ",queue[i]);
        }
        printf("\n"); 
    }
}

int main(){
    int size_of_queue,front = -1,rear = -1,choice;
    printf("Enter the size of Queue : ");
    scanf("%d",&size_of_queue);
    int *Queue = (int *)malloc(size_of_queue*sizeof(int));
    do{
    printf("Enter your choice :");
    printf("\n1) Enqueue \n2) Dequeue \n3) Peek \n4) Display \n5) Is Empty \n6) Size \n7)Exit : \n ");
    scanf("%d",&choice);
        switch(choice){
            case 1:
                    enqueue(Queue,&front,&rear,size_of_queue);
                    break;
            case 2:
                    dequeue(Queue,&front,&rear,size_of_queue);
                    break;
            case 3:
                    peek(Queue,&front,&rear,size_of_queue);
                    break;
            case 4:
                    display(Queue,&front, &rear,size_of_queue);
                    break;  
            case 5:
                     if(is_Empty(Queue,&front,&rear,size_of_queue)){
                        printf("Queue is empty\n");
                
                    }        
                    else{
                        printf("Queue is not empty\n");
                    }
                    break;

            case 6: size(Queue,&front,&rear,size_of_queue);
                    break;        

            case 7: return 0;
            default: 
                    printf("Invalid Input");
                    break;
        }
    }while(choice != 7);
    return 0;
}