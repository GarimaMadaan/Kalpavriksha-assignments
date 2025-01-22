#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
} Node;
 
Node *head = NULL;
Node *tail = NULL;
 
Node *addtoStream(int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = num;
    newNode->next = NULL;
 
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
    return head;
}
 
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
int sum_k(int window)
{
    if (window == 0)
        return 0;
    Node *temp = head;
    int cnt = 0, sum = 0;
    while (temp != NULL)
    {
 
        cnt++;
        temp = temp->next;
    }
    temp = head;
    if (window > cnt)
    {
        while (temp != NULL)
        {
            sum += temp->value;
            temp = temp->next;
        }
    }
    else
    {
        for (int i = 0; i < cnt - window; i++)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            sum += temp->value;
            temp = temp->next;
        }
    }
    return sum;
}
 
int main()
{
    int no_of_op, window;
    scanf("%d", &no_of_op);
    scanf("%d", &window);
 
    for (int i = 0; i < no_of_op; i++)
    {
 
        getchar();
        char op;
        scanf("%c", &op);
        if (op == 'A')
        {
            int num;
            scanf("%d", &num);
            addtoStream(num);
            display();
        }
        else if (op == 'S')
        {
            int sum = sum_k(window);
            printf("sum : %d\n", sum);
        }
    }
}