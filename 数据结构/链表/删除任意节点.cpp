//Delete a node at Nth position
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int data) //insert an int at end
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;
    struct Node *temp2 = head;
    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        return;
    }
    while (temp2->next != NULL) //不能直接temp ！= NULL，导致下面不能赋值
        temp2 = temp2->next;
    temp2->next = temp;
}

void Print() //print all elements
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n) //Delete node at n
{
    struct Node *temp = head;
    if (n == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < n - 2; i++)
        temp = temp->next;           //n-1 th
    struct Node *temp2 = temp->next; //n th
    temp->next = temp2->next;
    free(temp2);
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(6); //list:2 5 4 6
    int n;
    Print();
    printf("Enter a position:\n");
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}