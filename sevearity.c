#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct patients{
    int patient_id;
    char *severity;
    struct patients *next;
}Patients;

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

        while (ptr1->next != lptr) {
            if (precedence(ptr1->severity) < precedence(ptr1->next->severity)) {
                int temp_id = ptr1->patient_id;
                char *temp_severity = ptr1->severity;

                ptr1->patient_id = ptr1->next->patient_id;
                ptr1->severity = ptr1->next->severity;

                ptr1->next->patient_id = temp_id;
                ptr1->next->severity = temp_severity;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    return head;
}

int main(){
    int no_of_patients;
    scanf("%d",&no_of_patients);
    char *str = (char *)malloc(10000 * sizeof(char));
    // Patients *patient =(Patients *)malloc(no_of_patients*(sizeof(patient)));
    Patients *head = NULL;
    Patients *temp = head; 
    getchar();
    for(int i =0;i<no_of_patients;i++){

        Patients *patient = (Patients*)malloc(sizeof(patient)); 
        scanf("%d",&patient->patient_id);
        getchar();
        patient->severity = (char *)malloc(100 * sizeof(char));
        scanf("%s", patient->severity);
        getchar();
        if(head == NULL){
            head= patient;
            temp = patient;
        }
        else{
            temp->next = patient;
            temp = temp->next;
        }
    }
    // printList(head);
    Patients*sortedHead = sort(head);
    printf("\n");
    printList(sortedHead);


}