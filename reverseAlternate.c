#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *createList(char *str){
    Node *head = NULL;
    Node *temp = NULL;
    Node *tail = NULL;
    int i =0;
    while(str[i] != '\0'){
        if((str[i] >= '0' && str[i] <='9') || str[i] =='-'){
            int sign = 1;
            int num = 0;
            if(str[i] == '-'){
                sign = -1;
                i++;
            }
            while(str[i] >='0' && str[i]<='9'){
                num = num *10 + (str[i] -'0');
                i++;
            }
            temp = (Node*)malloc(sizeof(Node));
            temp->data = num*sign;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }
        else{
            i++;
        }
    }
    return head;
}

Node *rotatelist(Node *head,int window){
    if(!head || window<=0){
        return head;
    }
    Node *temp = head;
    Node* dummy = NULL;
    Node *end = NULL;
    
    while(temp != NULL){
        Node *start = temp;
        Node* prev = NULL;
        int count = 0;
        while(temp != NULL && count < window){
            Node *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            count ++;
        }
        if(dummy == NULL){
            dummy = prev;
        } 
        else{
            end->next = prev;
        }
        start->next = temp; 
        count =0;
        while(temp != NULL && count <window){
            prev = temp;
            temp = temp->next;
            count++;
        }
        end = prev;
    }
    return dummy;

}



void printlist(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';
    // printf("%s\n",str);
    Node *l1 = createList(str);

    int window;
    scanf("%d",&window);
    
    printlist(l1); 
    Node *res = rotatelist(l1,window); 
    printlist(res);

    
    return 0;
}