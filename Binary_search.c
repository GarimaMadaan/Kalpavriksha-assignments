#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr,int size,int key){
    int low = 0;
    int high = size - 1;
    int mid = low +(high -low)/2;
    
    while(low < high){
        int mid = low +(high -low)/2;
        if(arr[mid] == key){
            return mid + 1;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else {
            high = mid -1; 
        }
    }
    return -1;
}
int main(){
    int size,key;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    if(size<=0){
        printf("Invalid Input");
        return 0;
    }
    printf("Enter the elements of the array in sorted order :");
    int * input = (int *)malloc(size * sizeof(int));
    for(int i =0;i<size;i++){
        scanf("%d",&input[i]);
    }
    printf("Enter the elememt to search : ");
    scanf("%d",&key);
    
    int result = binarySearch(input,size,key);
    if(result == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d",result);
    }
}