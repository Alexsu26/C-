//doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node *GetNewNode(int num)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = num;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

void InsertAtHead(int x)
{
    struct Node *temp = GetNewNode(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void InsertAtTail(int x)
{
    struct Node *temp = GetNewNode(x);
    struct Node *last = head;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->prev = last;
}

void Print()
{
    struct Node *temp = head;
    printf("Normal: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    InsertAtHead(2);
    Print();
    ReversePrint();
    InsertAtTail(4);
    Print();
    ReversePrint();
    InsertAtHead(6);
    Print();
    ReversePrint();

    return 0;
}