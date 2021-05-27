1.  对于栈的实现，除了用STL，可直接用类：
    ```C++
    class Stack
    {
        private:
            char A[101];
            int head;
        public:
            Stack(){
                head = -1;
            }
            void push(char x){
                A[++head] = x;
            }
            void pop(){
                --head;
            }
            int top(){
                return A[head];
            }
            bool empty(){
                if(head == -1)
                    return true;
                else
                    return false;
            }
    };
    ```
        这里只实现了最基本的操作，没有考虑数组越界情况，如果考虑template，应该为：
    ```C++
    template <class T> class Stack
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
    template <class T> Stack<T>::Stack()       //构造函数，无需函数类型
    {
        head = -1;
        MAX_SIZE = 50;
        //C = new T[MAX_SIZE];    //C++风格的内存申请
        
        C = (T*)malloc(MAX_SIZE * sizeof(T));    //C风格的内存申请
    }
    template <class T> void Stack<T>::push(T x)     //需要函数类型
    {
        head ++;
        C[head] = x;
    }
    template <class T> void Stack<T>::pop()
    {
        head--;
    }
    template <class T> T Stack<T>::top()
    {
        return C[head];
    }
    template <class T> bool Stack<T>::Empty()
    {
        return (head == -1);
    }
    ```
    同样没有考虑其他情况，这种情况跟STL中的`<stack>`用法类似；