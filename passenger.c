#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum category {
        VIP, SENIOR_CITIZEN, GENERAL
    };
typedef  struct passenges{
    int passeger_id;
    char name[100];
    enum category Category;
    
}Passenger;

char *type[] = {"VIP", "SENIOR_CITIZEN", "GENERAL"};
enum category string_to_enum(char *type){
    if(strcmp(type,"VIP")==0) return VIP;
    else if (strcmp(type ,"GENERAL") == 0) return GENERAL;
    else if (strcmp(type,"SENIOR_CITIZEN") == 0) return SENIOR_CITIZEN;
    return -1;
}

void enquqe(Passenger *queue,int *front,int *rear,int size){
    if(*front == -1 && *rear == -1){
        *front = *rear = 0;
    }
    else{
        (*rear)++;
    }
    char *category = (char *)malloc (15 * sizeof(char));
    scanf(",%d,%[^,],\"%[^\"]\";",&queue[*rear].passeger_id,category,queue[*rear].name);
    
    getchar();
    if(string_to_enum(category)== -1) {
        printf("Invalid Input\n");
        return ;
    }
    else{
        queue[*rear].Category = string_to_enum(category);
    }
    
}
void deque(Passenger * queue,int *front,int *rear,int size){
    if(*front == -1 && *rear == -1){
        printf("Queue is empty\n");
    }
    else if(*front == *rear){
        int type_idx = queue[*front].Category;
        printf("ID : %d , Name : %s , Type : %s \n",queue[*front].passeger_id,queue[*front].name,type[type_idx]);
        *front  = *rear = -1;
    }
    else{
        int type_idx = queue[*front].Category;
        printf("ID : %d , Name : %s , Type : %s \n",queue[*front].passeger_id,queue[*front].name,type[type_idx]);
        (*front)++;

    }
}
void display(Passenger *queue,int *front,int *rear,int no_of_operations){
    if(*front == -1 && *rear == -1){
        printf("Queue is empty\n");
    }
    else{
        for(int i = *front ;i<= *rear;i++){
            int type_idx = queue[i].Category;
            printf("ID : %d , Name : %s , Type : %s \n",queue[i].passeger_id,queue[i].name,type[type_idx]);
        }
    }
}
void sortList(Passenger *queue,int *front,int *rear){
    for(int i = *front ;i<*rear ;i++){
        for(int j = *front ;j<*rear -i;j++){
            if(queue[j].Category > queue[j+1].Category){
                int temp_id = queue[j].passeger_id;
                queue[j].passeger_id = queue[j+1].passeger_id;
                queue[j+1].passeger_id = temp_id;

                int temp_type = queue[j].Category;
                queue[j].Category = queue[j+1].Category;
                queue[j+1].Category = temp_type;

                char *temp_name = (char *) malloc(20*sizeof(char));
                strcpy(temp_name,queue[j].name);
                strcpy(queue[j].name,queue[j+1].name);
                strcpy(queue[j+1].name,temp_name);
            }
        }
    }
}
int main(){
    
    int no_of_operations;
    scanf("%d",&no_of_operations);
    Passenger queue[no_of_operations];
    int front =-1,rear =-1;

    for(int i =0;i<no_of_operations;i++){
        int choice;
            scanf("%d",&choice);
            switch(choice){
                case 1:enquqe(queue,&front,&rear,no_of_operations);
                    break;

                case 2: sortList(queue,&front,&rear);
                        printf("Serving Passenger : \n");
                        deque(queue,&front,&rear,no_of_operations);
                        break;    
                case 3:
                        sortList(queue,&front,&rear);
                        printf("Waiting Passenger :  \n");
                        display(queue,&front,&rear,no_of_operations);
                        break; 
                case 4 : return 0;           
            }
        }
    return 0;
}
