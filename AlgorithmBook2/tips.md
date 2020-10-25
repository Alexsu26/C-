# tips

### C

*   ##### 可引用`time.h`和`(double)clock()/CLOCKS_PER_SEC`返回程序所运行的时间，但需要在命令行运行`echo 值 | 程序名`,若在VScode的终端中运行`echo 值 | .\程序名`才能运行

*   ##### `while(scanf("%d",&x) == 1)`会返回成功输入的变量个数，输入结束时将返回0；输入时应先`Enter`,再`Ctrl+Z`,再`Enter`

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

