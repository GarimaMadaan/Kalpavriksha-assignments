#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *head = NULL;
// void createNode(Node *head){
//     Node *newNode = (Node *) malloc (sizeof(Node));
//      Node->data = 0;
//      Node->next = NULL:
// }
void countt(){
    int count =0;
    Node * temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    printf("%d\n",count);
}

void insertAtBeginning(int element){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int element){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int position,int element){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    if(position ==1){
        newNode->next = head;
        head = newNode;
    }
    else if(position > count+1){
        printf("Invalid Position\n");
        return;
    }
    else{
        temp = head;
        for(int i =1;i<position-1;i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }
}

void display(){
    if(head == NULL){
        printf("Empty LinkedList\n");
        return;
    }
    Node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void updateAtPosition(int position,int element){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    temp = head;
    if(position > count){
        printf("Invalid Position\n");
        return;
    }
    else{
    for(int i=1;i<position;i++){
        temp = temp->next;
    }
    temp->data = element;
    }
}

void deleteAtBeginning(){
    if(head ==NULL){
        printf("Empty Linked List");
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next=NULL;
}

void deleteAtEnd(){
    if(head == NULL){
        printf("Empty Linked List");
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void deleteAtPosition(int position){
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    temp = head;
    if(position > count){
        printf("Invalid Position\n");
        return;
    }
    if(position ==1){
        deleteAtBeginning();
    }
    else{
    temp = head;
    for(int i =1;i< position -1;i++){
        temp = temp ->next;
    }
    temp->next = temp->next->next;
    }
}
int main(){
   int no_of_operations;
   scanf("%d",&no_of_operations);
   if(no_of_operations<1 || no_of_operations>100){
    printf("Operation Range : 1 to 100\n");
    return 0;
   }
   for(int i = 0;i<no_of_operations;i++){
    int operation;
    scanf("%d",&operation);
    int element,position;
    switch(operation){
        case 1: scanf("%d",&element);
                if(element<-1000 || element>1000){
                    printf("Data Range :-1000 to 1000 \n");
                    return 0;
                }
                insertAtEnd(element);
                break;
        
        case 2: scanf("%d",&element);
                if(element<-1000 || element>1000){
                    printf("Data Range :-1000 to 1000 \n");
                    return 0;
                }
                insertAtBeginning(element);
                break;

        case 3:scanf("%d %d",&position,&element);
                if(element<-1000 || element>1000){
                    printf("Data Range :-1000 to 1000 \n");
                    return 0;
                }
                insertAtPosition(position,element);
                break;

        case 4: display();
                break;

        case 5:scanf("%d %d",&position,&element);
                if(element<-1000 || element>1000){
                    printf("Data Range :-1000 to 1000 \n");
                    return 0;
                }
               updateAtPosition(position,element);
               break;

        case 6:deleteAtBeginning();
               break;

        case 7:deleteAtEnd();
               break;
               
        case 8:scanf("%d",&position);
               deleteAtPosition(position);
               break;
        case 9:countt();
                break;                                                           

    }
   }
    return 0;

}