#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *arr,int size){
    for(int i =0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1 ; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    selectionSort(input,size);
    printf("Sorted Array \n");
    for(int i = 0;i < size; i++){
        printf("%d ",input[i]);
    }
}