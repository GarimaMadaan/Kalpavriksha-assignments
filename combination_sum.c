#include<stdio.h>
#include<stdlib.h>

void combination_sum(int index,int *arr,int *ds,int target,int size,int ds_size){
    if(index == size){
        if(target ==0){
            for(int i=0;i<ds_size;i++){
                printf("%d ",ds[i]);
            }
            printf("\n");
        }
        return;
    }
    if(arr[index] <= target){
    ds[ds_size] = arr[index]; 
    combination_sum(index,arr,ds,target - arr[index],size,ds_size +1);
    }
    combination_sum(index + 1,arr,ds,target ,size,ds_size);
}
int main(){
    int size,target;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int *arr = (int *) malloc(size * sizeof(int));
    printf("Enter the elements : \n");
    for(int i =0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the target value : ");
    scanf("%d", &target);
    int *ds = (int*)malloc(size * sizeof(int));
    combination_sum(0,arr,ds,target,size,0);

    return 0;
}