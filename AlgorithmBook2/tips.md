# tips

>   用于存放《算法竞赛入门经典》第二版书中所作习题时的感悟，也有相当一部分的解题技巧和C、C++语言的语法知识

*   可引用`time.h`和`(double)clock()/CLOCKS_PER_SEC`返回程序所运行的时间，但需要在命令行运行`echo 值 | 程序名`,若在VScode的终端中运行`echo 值 | .\程序名`才能运行

*   `while(scanf("%d",&x) == 1)`会返回成功输入的变量个数，输入结束时将返回0；输入时应先`Enter`,再`Ctrl+Z`,再`Enter`

*   `scanf("%s",str)`可以读入一个不含空格、TAB、回车的字符串

*   `sprinf`：写入字符串
    ```C++
        char name[78];
        char x[20];
        scanf("%s", x);
        sprintf(name, "x = %s\n", x);
        printf(name);
    ```
*   `fprintf`：写入文件
    ```C++
        FILE *src;
        src = fopen(".\files.txt","w");
        int a = 100;
        char b[23] = "hello world!";
        fprintf(src,"a = %d,b = %s\n",a,b);
        fclose(src);
        system("type files.txt");
    ```
*   `fgets`：从文件读入
    ```C++
        FILE *fg;
        fg = fopen("files.txt","r");
        char test[85];
        fgets(test,85,fg);
        printf("%s\n",test);
        fclose(fg);
    ```
*   `floor(double)`函数的作用是向下取整，即取不大于该浮点数的整数
*   **gdb**中使用`gcc Name.c -std=c99 -g`生成调试程序，并通过`gdb a.exe`开始调试；部分命令如下
    | 命令 | 作用 |
    | ------- | ------ |
    | r | 运行至断点 |
    |b|设置断点，后加行号或函数名|
    |l|显示前10行源代码|
    |c|继续|
    |s|单步进入|
    |bt|显示调用栈的栈帧|
    |p|后加变量，显示变量的值|
    |q|退出调试|

*   使用`size name.exe`命令可得到可执行文件各个段的大小
    |text|data|bss|hex|filename|
    |------|------|------|------|------|
    |正文（指令）|数据（已初始化的全局变量）|BSS（为初始化的全局变量）|总大小（十六进制）|文件名|
    而调用栈的段在运行是创建，局部变量和递归都将在堆栈段增加栈帧，若超过大小则称为**栈溢出(Stack Overflow)**

*   移动数组时，可用`(A+1)%n+1`进行，可排除负数和防止越界；也可写成`A=A+1==n+1?1:A+1`

*   输入输出重定向可通过
    1.  `freopen("name.xxx","r",stdin)`定义输入，此后的标准输入都从文件读取；
    
    2.  `freopen("name.xxx","w",stdout)`定义输出，此后的标准输出都输出至文件
    
    并且应写在`main`函数中，紧接着`int main()`语句；

*   可通过`pair<int,int>`的形式关联两个类型的变量，并将关联后的变量以整体形式放入`map`等数据结构中；例如下
    ```C++
    typedef pair<int,int> P;
    map<P,int>ans;
    //来自STL入门中的例题5-9
    ```
    就可将map当中的P映射到一个单独的整型中

*   函数中若存在循环，应注意循环变量与函数的参数不能重名，否则易出现数组越界的问题；如习题5-1：
    ```C++
    void printnull(int i,int j,int long_str)
    {
        cout << code[i][j];
        for(int i=0; i<long_str - code[i][j] + 1; i++)
            cout << " ";
    }
    ```
    由于函数的参数与循环变量i重名，使用时数组越界；

*   对输出有要求的题目，如对二维数组输出时，除最后一行外的其他行要求换行，可单独处理最后一行；
    ```C++
    for(int i=0; i<rows; i++)
    {
        int j;
        for(j=0; j<cols - 1; j++)
            cout << num[i][j] << "\n";
        cout << num[i][j];
    }
    ```

*   对于同一行输出有要求，如：
Discarded cards: 1, 3, 5, 7, 4, 2
的情况，可以用flag标志第一次，然后输出后续；
    ```C++
    cout << "Discarded cards:";
    bool flag = true;
    if(flag)
    {
        cout << " ";
        flag = false;
    }
    else
        cout << ", ";
    ```
    同上一个点一样，可以将最后一个数的输出单独处理；

*   对于字符串string类型，可切片运算，指令如下：
    ```C++
    string str = "hello";
    string str1 = str.substr(0,2);  //两个参数，则是[0,2),即str1 = "he"
    string str2 = str.substr(2);    //一个参数，即是(2:],即str2 = "llo"
    ```

*   对于`sort`函数，有两个重载，一个仅有两个参数，即排序的起始位置，例如
    ```C++
    int x[5] = {5,4,3,2,1};
    sort(x,x+5);
    //此时数组x为{1,2,3,4,5}
    ```
    而三个参数的形式，可以指定排序方式，例如
    ```C++
    bool cmp(int x,int y)
    {
        return x > y;
    }
    int x[5] = {1,2,3,4,5};
    sort(x,x+5,cmp);
    //此时数组x为{5，4，3，2，1}
    ```
    当然对于习题5-6所构造的结构体
    ```C++
    struct dot{
        int x;
        int y;
    };
    ```
    而言，可以通过重载`<`运算符进行排序：
    ```C++
    struct dot
    {
        int x;
        int y;
        bool operator < (const dot& b) const {
            if(x == b.x)
                return y < b.y;
            else
                return x < b.x;
        }
    };
    sort(dot x,dot x+size);//可直接调用sort
    ```

*   udebug网站对于uva的检索规则不明，应先选择uva online judge，再直接输入题号进行检索而不是再输入uva+题号

*   对于bool类型的函数，在vscode中进行编译，即使不包括返回值，也会自动返回1，例如例题6-10中的函数：
    ```C++
    bool init()
    {
        memset(sum,0,sizeof(sum));
        int v;
        cin >> v;
        if(v == -1)
            return false;
        int root = maxv/2;
        sum[root] = v;
        build_substree(root-1);
        build_substree(root+1);
        // return true;  OJ中这条语句不可少
    }
    ```
    在编译器中结尾自动添加`return true`语句，使得调用`while(init())`的循环语句得以继续，但是在OJ中，没有返回值的函数是不允许的，至少bool函数不允许没有返回值；

*   在C语言中，存在有`index`函数，参数为：`index(const char* s , char ch)`，用于返回字符串s中第一次出现字符ch的指针；但在vscode中编译，会将用户定义的`index`函数顶替掉预定义的函数，但是在OJ上并不会，因此最好不要自定义同名函数，即使可以重载，可将`index`改为`idx`；

*   2021.02.16  由于进入6.4 图 部分，但基础知识与章节要求相差较大，暂停./AlgorithmBook2/数据结构基础 相关章节的学习，原有的计划暂且搁置，由[OI-wiki](https://oi-wiki.org/basic/) 以及 [MOOC](https://www.icourse163.org/learn/ZJU-93001?tid=1461682474#/learn/content) 上的数据结构和算法基础部分代替，时间暂定为10天；