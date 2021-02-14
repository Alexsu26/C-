#include <iostream>
#include <cstring>
using namespace std;

const int maxv = 100;
int sum[maxv];

void build_substree(int root)
{
    int v;
    cin >> v;
    if(v == -1)
        return;
    sum[root] += v;
    build_substree(root-1);
    build_substree(root+1);
}

bool init()
{
    memset(sum,0,sizeof(sum));
    int v;
    cin >> v;
    if(v == -1)
        return false;
    int root = maxv/2;
    sum[root] = v;
    build_substree(root-1);
    build_substree(root+1);
    return true;            //bool函数的返回值
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int kase = 0;
    while(init())
    {
        int p = 0;
        while(sum[p] == 0)
            p++;
        cout << "Case " << ++kase << ":\n" 
        << sum[p++];        //sum[p++]让p继续向后移动
        while(sum[p] != 0)
            cout << " " << sum[p++];
        cout << "\n\n";
    }
    return 0;
}