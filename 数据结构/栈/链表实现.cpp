//也是实现基础功能
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
        return;
    struct Node *temp = top;
    top = top->link;
    free(temp);
}

int Top()
{
    return top->data;
}

bool isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

void Print()
{
    struct Node *temp = top;
    printf("stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    push(2);
    Print();
    push(4);
    Print();
    push(6);
    Print();
    pop();
    Print();
    printf("top = %d\n", Top());

    return 0;
}