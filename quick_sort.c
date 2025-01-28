#include<stdio.h>
#include<stdlib.h>
int partition(int *arr,int low,int high){
    int pivot = arr[low];
    int left = low;
    int right = high;
    while(left < right){
        while(arr[left] < pivot && left <= high){
            left++;
        }
        while(arr[right] > pivot && right >= low){
            right--;
        }
        if(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
        }
    }
    int temp = arr[right];
    arr[right] = pivot;
    pivot = temp;
    return right;
}
void QuickSort(int *arr,int low,int high){
    if(low<high){
        int partitionIndex = partition(arr,low,high);
        QuickSort(arr,low,partitionIndex-1);
        QuickSort(arr,partitionIndex+1,high);
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
    int *input = (int *)malloc(size * sizeof(int));
    for(int i =0;i<size;i++){
        scanf("%d",&input[i]);
    }
    QuickSort(input,0,size-1);
    printf("Sorted Array \n");
    for(int i = 0;i < size; i++){
        printf("%d ",input[i]);
    }
}