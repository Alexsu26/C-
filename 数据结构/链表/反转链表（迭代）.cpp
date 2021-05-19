//reverse a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

struct Node *Reverse(struct Node *head)
{
    struct Node *current, *pre, *next;
    current = head;
    pre = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
    return head;
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
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 5);
    head = Insert(head, 7);
    Print(head);
    head = Reverse(head);
    Print(head);
    return 0;
}