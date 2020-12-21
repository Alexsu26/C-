#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    const int maxn = 10000;
    int n,q,x,a[maxn],flag=0;
    while(cin>>n>>q && n)
    {
        cout << "CASE# " << ++flag <<":\n";
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a,a+n);
        while(q--)
        {
            cin >> x;
            int p = lower_bound(a,a+n,x) - a ;
            if( a[p] == x )
                cout<< x <<" found at " << p+1 <<endl;
            else
                cout<< x << " not found\n";
        }
    }
    return 0;
}