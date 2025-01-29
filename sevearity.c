#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct patients{
    int patient_id;
    char *severity;
    struct patients *next;
}Patients;

typedef struct map{
    int id;
}Map; 

void printList(Patients *head){
    Patients *temp = head;
    while(temp != NULL){
        printf("%d ",temp->patient_id);
        printf("%s",temp->severity);
        printf("\n");
        temp = temp->next;
    }
}
int precedence(char *severity){
    if(strcmp(severity,"Critical") ==0) return 2;
    else if(strcmp(severity,"Serious") ==0) return 1;
    else if(strcmp(severity,"Stable") == 0) return 0;
}

Patients* sort(Patients *head) {
    if (head == NULL) return head;

    int swapped;
    Patients *ptr1;
    Patients *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        printList(head);
        while (ptr1->next != lptr) {
            printList(head);
            Patients *ptr=ptr1->next;
            if (precedence(ptr1->severity) < precedence(ptr->severity)) {
                printList(head);
                int temp_id = ptr1->patient_id;
                char *temp_severity =(char*)malloc(100*sizeof(char));
                strcpy(temp_severity,ptr1->severity);

                ptr1->patient_id = ptr->patient_id;
                strcpy(ptr1->severity,ptr->severity);

                ptr->patient_id = temp_id;
                strcpy(ptr->severity,temp_severity);
                swapped = 1;
            }

            ptr1 = ptr1->next;
            
        }
        
        lptr = ptr1;
    } while (swapped);
    return head;
}
int take_severity(Patients *patient,Patients*head,Patients*temp){
    patient->severity = (char *)malloc(100 * sizeof(char));
    scanf("%s", patient->severity);
    if(strcmp(patient->severity,"Critical") == 0 || strcmp(patient->severity,"Serious") == 0 ||strcmp(patient->severity,"Stable") == 0 ){
        patient->next=NULL;
        if(head == NULL){
            head= patient;
            temp = patient;
        }
        else{
            temp->next = patient;
            temp = patient;
        }
        }
        else{
            printf("Invalid Input,Enter Severity again");
            return 1;
        }
        return 0;
}

int main(){
    int no_of_patients;
    scanf("%d",&no_of_patients);
    char *str = (char *)malloc(10000 * sizeof(char));
    // Patients *patient =(Patients *)malloc(no_of_patients*(sizeof(patient)));
    Patients *head = NULL;
    Patients *temp = head; 
    getchar();
    Map mp[100];
    int index =0;
    for(int i =0;i<no_of_patients;i++){

        Patients *patient = (Patients*)malloc(sizeof(patient)); 
        scanf("%d",&patient->patient_id);
        int is_duplicate = 0;
        for(int i=0;i<index;i++){
            if(mp[i].id == patient->patient_id){
                is_duplicate = 1;
                break;
            }
        }
        if(is_duplicate ==1){
            printf("Duplicate id ,Enter Again ");
            i--;
            continue;
        }
        mp[index++].id = patient->patient_id;
        while(take_severity(patient,head,temp));
    }
    printList(head);
    Patients* sortedHead = sort(head);
    printf("\n");
    printList(sortedHead);


}
