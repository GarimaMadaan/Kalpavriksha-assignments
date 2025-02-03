#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


bool isSafe(int row,int col,int **board,int size){
    int duprow = row;
    int dupcol = col;
    while(row >=0 && col >= 0){
        if(board[row][col] == 1)
        return false;
        row--;
        col--;
    }
    col = dupcol;
    row = duprow;
    while(col >= 0){
        if(board[row][col] == 1) return false;
        col--;
    }
    row = duprow;
    col = dupcol;
    while(row <size && col>=0){
        if(board[row][col] == 1)return false;
        row++;
        col--;

    }
    return true;
}

void solveNQ(int col,int size,int **board){
    if(col == size ){
        for(int i=0;i<size;i++){
            for(int j = 0;j<size;j++){
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }
    for(int row=0;row<size;row++){
        if(isSafe(row,col,board,size)){
            board[row][col] = 1;
            solveNQ(col+1,size,board);
            board[row][col] = 0;
        }
    }
}
int main() {
    int size;
    printf("Enter the size of the board : ");
    scanf("%d", &size);
    int **board = (int **)malloc (size*(sizeof(int)));
    for(int i =0;i<size;i++){
        board[i] = (int *)malloc(size * sizeof(int));
    }
    for(int i =0;i<size;i++)
    {
        for(int j =0;j<size;j++){
            board[i][j] = 0;
        }
    }

    solveNQ(0,size,board);
    return 0;
}