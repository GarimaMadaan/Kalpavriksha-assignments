#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool is_Empty(int *stack,int *top,int size_of_stack){
    if(*top == -1) return true;
    return false;
}

void push(int *stack,int *top,int size_of_stack){
    int data;
    printf("Enter Data : ");
    scanf("%d",&data);
    if(*top == size_of_stack - 1){
        printf("Stack is full\n");
        return ;
    }
    else{
        (*top)++;
        stack[*top] = data;
    }
}

void size(int *stack,int *top,int size_of_stack){
    printf("Size of the stack is : %d",*top);
}


void pop(int *stack,int *top,int size_of_stack){
    int data;
    if(is_Empty(stack,top,size_of_stack)){
        printf("Stack is Empty\n");
    }
    else{
        data = stack[*top];
        (*top)--;
        printf("Popped value : %d\n",data);
    }
}

void peek(int *stack,int *top,int size_of_stack){
    if(is_Empty(stack,top,size_of_stack)){
        printf("Stack is Empty\n");
    }
    else
    printf("Data at top of stack : %d\n",stack[*top]);
}

void display(int *stack,int *top,int size_of_stack){
    if(is_Empty(stack,top,size_of_stack)){
        printf("Stack is Empty \n");
    }
    else{
    printf("Elements in the Stack : \n");
    for(int i=*top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
    }
}
int main(){
    int size_of_stack;
    printf("Enter the size of Stack : ");
    scanf("%d",&size_of_stack);
    int *stack = (int *)malloc(size_of_stack*sizeof(int));
    int stack_top = -1;
    int choice;
    do{
        
        printf("Enter your choice :");
        printf("\n1) Push \n2) Pop \n3) Peek \n4) Display \n5) Is Empty \n6) Size \n7)Exit : \n ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    push(stack,&stack_top,size_of_stack);
                    break;
            case 2:
                    pop(stack,&stack_top,size_of_stack);
                    break;
            case 3:
                    peek(stack,&stack_top,size_of_stack);
                    break;
            case 4:
                    display(stack,&stack_top,size_of_stack);
                    break;  
            case 5:
                    if(is_Empty(stack,&stack_top,size_of_stack)){
                        printf("Stack is Empty\n");
                    }        
                    else{
                        printf("Stack is not empty\n");
                    }
                    break;

            case 6: size(stack,&stack_top,size_of_stack);
                    break;        

            case 7: return 0;
            default: 
                    printf("Invalid Input");
                    break;
        }
    }while(choice != 7);

    return 0;

}