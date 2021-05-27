//stack - array based implementation
//并不算完整stack，只实现了其功能；
#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    A[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("No element to pop!\n");
        return;
    }
    top--;
}

int Top()
{
    return A[top];
}

void Print()
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    push(2);
    Print();
    push(4);
    Print();
    pop();
    Print();
    push(10);
    Print();

    printf("top = %d\n", Top());
    return 0;
}