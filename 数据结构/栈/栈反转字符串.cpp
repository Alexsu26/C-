#include <iostream>
// #include <stack>
#include <cstring>
using namespace std;

//template测试
template <class T>
class Stack
{
private:
    T *C;
    int head;
    int MAX_SIZE;

public:
    Stack();
    void push(T x);
    void pop();
    T top();
    bool Empty();
};
template <class T>
Stack<T>::Stack() //构造函数，无需函数类型
{
    head = -1;
    MAX_SIZE = 50;
    //C = new T[MAX_SIZE];    //C++风格的内存申请

    C = (T *)malloc(MAX_SIZE * sizeof(T)); //C风格的内存申请
}
template <class T>
void Stack<T>::push(T x) //需要函数类型
{
    head++;
    C[head] = x;
}
template <class T>
void Stack<T>::pop()
{
    head--;
}
template <class T>
T Stack<T>::top()
{
    return C[head];
}
template <class T>
bool Stack<T>::Empty()
{
    return (head == -1);
}

void Reverse(char *C, int len)
{
    Stack<char> S;
    for (int i = 0; i < len; i++)
        S.push(C[i]);

    for (int i = 0; i < len; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];
    printf("Enter a string : ");
    gets(C);
    Reverse(C, strlen(C));
    cout << "Output: " << C;
    return 0;
}