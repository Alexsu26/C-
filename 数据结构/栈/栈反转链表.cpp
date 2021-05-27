#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void listpush(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct Node *temp2 = head;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp;
}

void Print()
{
    struct Node *temp = head;
    printf("linked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse()
{
    if (head == NULL)
        return;
    stack<struct Node *> s;
    struct Node *temp = head;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    s.pop();
    head = temp;
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    head = NULL;
    listpush(2);
    listpush(4);
    listpush(6);
    listpush(8);
    listpush(10);
    Print();

    Reverse();
    Print();
    return 0;
}
