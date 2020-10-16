#include <bits.\stdc++.h>
using namespace std;

void printN(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", i);
    return;
}

double myTime(int n)
{
    time_t start = clock();
    printN(n);
    time_t end = clock();
    double time = (start-end)/CLOCKS_PER_SEC;
    return time;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    printf("%f\n",myTime(N));
    return 0;
}
