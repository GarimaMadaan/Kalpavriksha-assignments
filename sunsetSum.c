#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void findsum(int *arr,int n,int index,int target,int subsetSize,int *subset,int sum){
    if(sum == target){
        for(int i=0;i<subsetSize;i++){
            printf("%d ",subset[i]);
        }
        printf("\n");
        return;
    }
    for (int i = index; i < n; i++) {
        subset[subsetSize] = arr[i];
        findsum(arr,n,i+1,target,subsetSize+1,subset,sum + arr[i]);
    }
}
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] ='\0';

    int target;
    scanf("%d",&target);

    int index =0,input[100];
    char *token = strtok(str," ");
    while(token != NULL){
        input[index++] = atoi(token);
        token = strtok(NULL," ");
    }
    
    int subset[index];
    findsum(input,index,0,target,0,subset,0);


}