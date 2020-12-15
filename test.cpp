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
    int x = 5;
    
    cout<<x*--x<<endl;
    return 0;
}