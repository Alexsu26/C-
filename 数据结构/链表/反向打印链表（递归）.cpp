//Print linked list using recursion
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Reverse(struct Node *head)
{
    // if(head->next != NULL)
    //     Reverse(head->next);
    // printf("%d ",head->data);
    if (head == NULL)
    {
        // printf("\n");
        return;
    }
    Reverse(head->next);
    printf("%d ", head->data);
}

struct Node *Insert(struct Node *head, int data)
{
    Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp;
    }
    return head;
}

void Print(struct Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    Print(head->next);
}

int main()
{
    struct Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 5);
    head = Insert(head, 7);
    Print(head);

    Reverse(head);
    return 0;
}