#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool search_word(char **grid,char * word,int i,int j,int row,int col,int word_size,int visited[row][col],int idx){
    if(idx == word_size){
        return true;
    }
    if(i<0 || j<0 || i>=row || j>= col || visited[i][j] == 1){
        return false;
    }
    if(grid[i][j] != word[idx]){
        return false;
    }
    visited[i][j] = 1;

    for(int k =0;k<4;k++){
        int new_i = i+direction[k][0];
        int new_j = j+direction[k][1];
        if(search_word(grid,word,new_i,new_j,row,col,word_size,visited,idx+1))
        return true;
    }
    visited[i][j] =0;
    return false;


}
int main(){
    int rows,cols;
    printf("Enter the number of rows : ");
    scanf("%d",&rows);
    printf("Enter the number of columns : ");
    scanf("%d",&cols);
    char **grid = (char **)malloc(rows * sizeof(char*));
    for(int i =0;i<rows;i++){
        grid[i] = (char *)malloc(cols* sizeof(char));
    }
    printf("Enter the characters for the grid:\n");
    for(int i=0;i<rows;i++){
        scanf("%s",grid[i]);
        getchar();
    }

    int string_size;
    printf("Enter the size of the word\n");
    scanf("%d",&string_size);
    char * word = (char *)malloc(string_size*sizeof(char));
    printf("Enter the word to search : \n");
    scanf("%s",word);

    int visited[rows][cols];
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            visited[i][j] = 0;
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j] == word[0] && search_word(grid,word,i,j,rows,cols,string_size,visited,0)){
                printf("True\n");
                return 0;
            }
        }
    }
    printf("False\n");
    return 0; 

}