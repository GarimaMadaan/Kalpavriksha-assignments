#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solve(int i,int j,int **maze,int size,char*move,int **visited){
    if(i == size-1 && j == size-1){
        int index =0;
        while(move[index] != '\0'){
            printf("%c",move[index]);
            index++;
        }
        printf("\n");
        return ;
    }
    
    // down
    if((i+1 < size) && (maze[i+1][j] == 1) && visited[i+1][j] == 0 ){
        visited[i][j] = 1;
        solve(i+1,j,maze,size,strcat(move,"D"),visited);
        move[strlen(move)-1] = '\0';
        visited[i][j] = 0;
    }
    
    // left
    if((j-1 >=0) && (maze[i][j-1] == 1) && visited[i][j-1] == 0 ){
        visited[i][j] = 1;
        solve(i,j-1,maze,size,strcat(move,"L"),visited);
        move[strlen(move)-1] = '\0';
        visited[i][j] = 0;
    }
    
    // right
    if((j+1 < size) && (maze[i][j+1] == 1) && visited[i][j+1] == 0 ){
        visited[i][j] = 1;
        solve(i,j+1,maze,size,strcat(move,"R"),visited);
        move[strlen(move)-1] = '\0';
        visited[i][j] = 0;
    }
    
    // up
    if((i-1 >= size) && (maze[i-1][j] == 1) && visited[i-1][j] == 0 ){
        visited[i][j] = 1;
        solve(i-1,j,maze,size,strcat(move,"U"),visited);
        move[strlen(move)-1] = '\0';
        visited[i][j] = 0;
    }
}
void findpath(int **maze,int size){
    int **visited = (int **)malloc(size*sizeof(int*));
    for(int i=0;i<size;i++){
        visited[i] = (int *)malloc(size*sizeof(int));
    }
    for(int i =0;i<size;i++){
        for(int j=0;j<size;j++){
            visited[i][j] = 0;
        }
    }
    char *move = (char *)malloc((size*size)*sizeof(char));
    solve(0,0,maze,size,move,visited);
}
int main(){
    int size;
    scanf("%d",&size);
    int **maze = (int **)malloc(size*(sizeof(int *)));
    for(int i =0;i<size;i++){
        maze[i] = (int *)malloc(size*sizeof(int));
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    findpath(maze,size);
}