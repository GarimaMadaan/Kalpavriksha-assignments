#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void bubbleSort(int *arr,int size){
    bool swapped;
    for(int i =0; i < size - 1; i++){
        swapped = false;
        for(int j = 0; j<size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (swapped == false)
        break;
    }
}
int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    if(size<=0){
        printf("Invalid Input");
        return 0;
    }
    printf("Enter the elements of the array :");
    int * input = (int *)malloc(size * sizeof(int));
    for(int i =0;i<size;i++){
        scanf("%d",&input[i]);
    }
    
    bubbleSort(input,size);
    printf("Sorted Array \n");
    for(int i = 0;i < size; i++){
        printf("%d ",input[i]);
    }
}