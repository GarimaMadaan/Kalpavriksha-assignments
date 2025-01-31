#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int data;
    struct stack* next;
}Stack;

bool is_Empty(Stack *head){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    } 
}

void push(Stack **head){
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
}

void pop(Stack **head){
    if(is_Empty(*head)){
        printf("Stack is Empty");
    }
    else{
        int data;
        data = (*head)->data;
        Stack *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Popped Data : %d\n",data);
    }
}

void peek(Stack **head){
    if(is_Empty(head)){
        printf("Stack is Empty \n");
    }
    else{
        printf("Data at the top of the stack: %d",(*head)->data);
    }
}
void size(Stack **head){
    Stack *temp = *head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
    }
    printf("Size of the stack is : %d ",count);
}

void display(Stack **head){
    if(is_Empty(head)){
        printf("Stack is Empty\n");
    }
    else{
        Stack *temp = *head;
        while(temp != NULL){
            printf("%d\n",temp->data);
            temp= temp->next;
        }
    }
}



int main(){
    Stack *stack_head = NULL;
    int choice;
    do{
        
        printf("Enter your choice :");
        printf("\n1) Push \n2) Pop \n3) Peek \n4) Display \n5) Is Empty \n6) Size \n7)Exit : \n ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    push(&stack_head);
                    break;
            case 2:
                    pop(&stack_head);
                    break;
            case 3:
                    peek(&stack_head);
                    break;
            case 4:
                    display(&stack_head);
                    break;  
            case 5:
                    if(is_Empty(stack_head)){
                        printf("Stack is Empty\n");
                    }        
                    else{
                        printf("Stack is not empty\n");
                    }
                    break;
            case 6: size(&stack_head);
                    break;        

            case 7: return 0;
            default: 
                    printf("Invalid Input");
                    break;
        }
    }while(choice != 7);


}