#include <iostream>
using namespace std;

int a[] = {1,2,3,4};
int len = sizeof(a)/sizeof(a[0]) - 1;

int sumx(int* a, int len)
{
    if( len == 0)
        return a[0];
    else
        return a[len] + sumx(a,len-1);
}

int main()
{
    cout<<sumx(a,len);
    return 0;
}