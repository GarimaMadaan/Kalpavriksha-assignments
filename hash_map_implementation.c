#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;
typedef struct{
    int capacity;
    Node** arr;
}hashmap;
void initialize_hashmap(hashmap* mp,int capacity)
{
    mp->capacity=capacity;
    mp->arr=(Node**)malloc(capacity*sizeof(Node*));
    for(int i=0;i<capacity;i++)
    {
        mp->arr[i]=NULL;
    }
}
int hashfunction(hashmap* mp,int key)
{
   return key%mp->capacity;   
}
Node* create_node(int t_key,int t_value)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        return NULL;
    }
    newnode->key=t_key;
    newnode->value=t_value;
    newnode->next=NULL;
    return newnode;
}
void insert(hashmap* mp)
{
    int temp_key,temp_value;
    printf("enter key : ");
    scanf("%d",&temp_key);
    printf("enter value : ");
    scanf("%d",&temp_value);
    Node* newnode=create_node(temp_key,temp_value);
    int ind=hashfunction(mp,temp_key);
    if(mp->arr[ind]==NULL)
    {
        mp->arr[ind]=newnode;
    }
    else{
        newnode->next=mp->arr[ind];
        mp->arr[ind]=newnode;
    }
}
void search(hashmap* mp)
{
    int search_key;
    printf("enter key : ");
    scanf("%d",&search_key);
    int search_ind=hashfunction(mp,search_key);
    Node* search_node=mp->arr[search_ind];
    while(search_node!=NULL)
    {
        if(search_node->key==search_key)
        {
            printf("Value :  %d\n",search_key,search_node->value);
            return;
        }
        search_node=search_node->next;
    }
    printf("not found\n");
}
void delete(hashmap* mp)
{
    int delete_key;
    printf("enter key : ");
    scanf("%d",&delete_key);
    int delete_ind=hashfunction(mp,delete_key);
    Node* prev=NULL;
    Node* curr=mp->arr[delete_ind];
    while(curr!=NULL)
    {
        if(curr->key==delete_key)
        {
            if(prev==NULL)
            {
                mp->arr[delete_ind]=curr->next;
            }
            else{
                prev->next=curr->next;
            }
            free(curr);
            printf("deleted\n");
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    printf("not found\n");
}
void display(hashmap* mp)
{
    int found=0;
    for(int i=0;i<mp->capacity;i++)
    {
        Node* curr=mp->arr[i];
        found = 0;
        while(curr!=NULL)
        {
            if(found == 0){
                printf("(%d, %d)",curr->key,curr->value);
            }
            else{
                printf("->");
                printf("(%d, %d)",curr->key,curr->value);
            }
            
            curr=curr->next;
            found=1;
        }
    }
    printf("\n");
    if(found==0)
    {
        printf("map is empty\n");
    }
}
int main()
{
    int n;
    printf("enter size\n");
    scanf("%d",&n);
    hashmap* mp=(hashmap*)malloc(sizeof(hashmap));
    initialize_hashmap(mp,n);
    int choice;
    while(1)
    {
        printf("\nenter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   insert(mp);
                   break;
            case 2:
                   search(mp);
                   break;
            case 3:
                   delete(mp);
                   break;
            case 4:
                   display(mp);
                   break;
            case 5:
                   return 0;
            default:
                    break;
        }
    }
 
    return 0;
}
