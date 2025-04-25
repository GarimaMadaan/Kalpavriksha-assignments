#include<stdio.h>
#include<stdlib.h>
int linearSearch(int *arr,int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]== key){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int size,key;
    printf("Enter the size of the array :");
    scanf("%d",&size);
    int *input = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array : ");
    for(int i=0;i<size;i++){
        scanf("%d",&input[i]);
    }
    printf("Enter the element to search : ");
    scanf("%d",&key);
    int result = linearSearch(input,size,key);
    printf(" %d",result);

    if(linearSearch(input,size,key) != -1){
        printf("Element found at index %d",linearSearch(input,size,key));
    }
    else{
        printf("Element not found");
    }
}