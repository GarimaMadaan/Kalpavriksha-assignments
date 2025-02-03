#include<stdio.h>
#include<stdbool.h>

int solve(int i,int j,int* score){
    if(i>j){
        return 0;
    }
    if(i == j){
        return score[i];
    }
    int take_i = score[i] + ((solve(i+2,j,score) < solve(i+1,j-1,score)) ? solve(i+2,j,score) : solve(i+1,j-1,score));
    int take_j = score[j] + ((solve(i,j-2,score) < solve(i+1,j-1,score)) ? solve(i+2,j,score) : solve(i+1,j-1,score));

    return (take_i<take_j ? take_j : take_i);

}

bool predict_winner(int *score,int n){
    int total_score=0;
    for(int i=0;i<n;i++){
        total_score += score[i];
    }
    int player1 = solve(0,n-1,score);
    int player2 = total_score - player1;

    return player1 >=player2;
}
int main(){
    int n;
    scanf("%d",&n);
    int score[n];
    for(int i=0;i<n;i++){
        scanf("%d",&score[i]);
    }
    if(predict_winner(score,n)){
        printf("Player 1 is the winner");
    }
        else{
            printf("Player 2 is the winner");
        }
    
}