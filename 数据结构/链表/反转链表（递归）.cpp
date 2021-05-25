//Reverse a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Reverse(struct Node *curr)
{
    if (curr->next == NULL)
    {
        head = curr;
        return;
    }
    Reverse(curr->next);
    struct Node *q = curr->next;
    q->next = curr;
    curr->next = NULL;
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

void Print(struct Node *p)
{
    if (p == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    Print(p->next);
}

int main()
{
    head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 5);
    head = Insert(head, 7);
    Print(head);

    Reverse(head);

    Print(head);
    return 0;
}