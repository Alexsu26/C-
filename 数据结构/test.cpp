#include <bits.\stdc++.h>
using namespace std;

int sumx(int x)
{
    if( x == 1) 
        return 1;
    else
        return x * sumx(--x);
}

int main()
{
    int x = 5;
    cout<<sumx(x)<<endl;
    return 0;
}