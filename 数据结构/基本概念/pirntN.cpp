#include <bits.\stdc++.h>
using namespace std;
#define func1 printN1(n);
#define func2 printN2(n);
void printN1(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    return;
}

void printN2(int n)
{
    if(n){
        printN2(n-1);
        printf("%d\n",n);
    }
}

double myTime(int n)
{
    time_t start = clock();
    // printN(n);
    func1;
    time_t end = clock();
    double time = (start - end) / CLOCKS_PER_SEC;
    return time;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    printf("%f\n", myTime(N));
    return 0;
}
/*
递归要占用的内存更高，一旦超出则程序崩溃
*/