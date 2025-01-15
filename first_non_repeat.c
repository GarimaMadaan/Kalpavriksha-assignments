#include<stdio.h>
#include<string.h>
int main(){
    char input[100];
    char inputchar;
    fgets(input,sizeof(input),stdin);
    
    scanf("%c",&inputchar);
   int mapp[26]={0};
   for(int i =0; input[i] != '\0'; i++){
       if (input[i] >= 'a' && input[i] <= 'z') {
           mapp[input[i] - 'a']++;
       }
   }
//    for(int i =0;i<26;i++){
//        printf("%d ",mapp[i]);
//    }
   printf("\n");
   for(int i =0; input[i] != '\0'; i++){
       if (input[i] >= 'a' && input[i] <= 'z' && mapp[input[i] - 'a'] == 1){
           printf("First non-repeating character: %c\n", input[i]);
           input[i] = inputchar;
           break;
       }
   }
   printf("%s",input);
   return 0;
}