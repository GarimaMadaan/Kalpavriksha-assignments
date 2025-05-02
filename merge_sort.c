#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int low,int mid,int high){
    int left = low;
    int right = mid+1 ;
    int *temp = (int *)malloc((high -low +1) *sizeof(int));
    int index= 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[index++] = arr[left];
            left++;
        }
        else{
            temp[index++] = arr[right];
            right++;
        }
    }
    while(left<=mid){
            temp[index++] = arr[left];
            left++;
        }
    while(right <= high){
        temp[index++] = arr[right];
        right++;
            
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i -low];
    }    
}
void MergeSort(int *arr,int low,int high){
    if(low >= high){
        return;
    }
    int mid = low +(high - low)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    
    MergeSort(input,0,size-1);
    printf("Sorted Array \n");
    for(int i = 0;i < size; i++){
        printf("%d ",input[i]);
    }
}