#include <bits.\stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //sprintf
    char name[78];
    char x[20];
    scanf("%s", x);
    sprintf(name, "x = %s\n", x);
    printf(name);

    //fprintf
    FILE *src;
    src = fopen(".\files.txt","w");
    int a = 100;
    char b[23] = "hello world!";
    fprintf(src,"a = %d,b = %s\n",a,b);
    fclose(src);
    system("type files.txt");

    //fgets
    FILE *fg;
    fg = fopen("files.txt","r");
    char test[85];
    fgets(test,85,fg);
    printf("%s\n",test);
    fclose(fg);
    return 0;
}
