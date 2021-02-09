#include <bits./stdc++.h>
using namespace std;

const int maxn = 20;
int s[1<<maxn];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int D, I;
        //算法一，标准的模拟算法
        while (scanf("%d%d", &D, &I) == 2)
        {
            memset(s, 0, sizeof(s));
            int k, n = (1 << D) - 1;
            for (int i = 0; i < I; i++)
            {
                k = 1;
                for (;;)
                {
                    s[k] = !s[k];
                    k = s[k] ? 2 * k : 2 * k + 1;
                    if (k > n)
                        break;
                }
            }
            printf("%d\n", k / 2);
        }
        //算法二，减少了s[1<<maxn]数组的建立和每次初始化，更加简单高效
        while (scanf("%d%d", &D, &I) == 2)
        {
            int k = 1;
            for (int i = 0; i < D - 1; i++)
            {
                if (I % 2)
                {
                    k = 2 * k;
                    I = (I + 1) / 2;
                }
                else
                {
                    k = 2 * k + 1;
                    I = I / 2;
                }
            }
            printf("%d\n", k);
        }
    }
    // printf("%.8f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}