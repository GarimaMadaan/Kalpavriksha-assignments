#include<stdio.h>
#include<stdlib.h>
void InsertionSort(int *arr,int size){
    for(int i =1; i < size; i++){
        int temp = arr[i];
        int j = i - 1;
        for(j = i - 1 ; j >=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}
int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the elements of the array :");
    int * input = (int *)malloc(size * sizeof(int));
    for(int i =0;i<size;i++){
        scanf("%d",&input[i]);
    }
    InsertionSort(input,size);
    printf("Sorted Array \n");
    for(int i = 0;i < size; i++){
        printf("%d ",input[i]);
    }
}