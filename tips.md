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
*   

