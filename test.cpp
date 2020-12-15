#include <bits.\stdc++.h>
using namespace std;

int sumx(int x)
{
    if( x == 1) 
        return 1;
    else
        return x * sumx(x-1);
}

int main()
{
    printf("%d\n",3>5?3:5);
    return 0;
}