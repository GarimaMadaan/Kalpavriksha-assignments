#include<stdio.h>
#include<stdlib.h>
int twoPointer(int *arr,int size,int target){
    int low = 0;
    int high = size - 1;
   
    while(low < high){
        if(arr[low] + arr[high] == target){
            printf("[%d %d]",arr[low],arr[high]);
            low++;high--;
        }
        else if(arr[low] + arr[high] < target){
            low++;
        }
        else{
            high--;
        }
}
}
int main(){
    int size,target;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    if(size<=0){
        printf("Invalid Input");
        return 0;
    }
    printf("Enter the elements of the array");
    int * input = (int *)malloc(size * sizeof(int));
    for(int i =0;i<size;i++){
        scanf("%d",&input[i]);
    }
    printf("Enter the target : ");
    scanf("%d",&target);

    for(int i =0; i < size - 1; i++){
        for(int j = 0; j<size - i - 1; j++){
            if(input[j] > input[j + 1]){
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
    
    twoPointer(input,size,target);
}