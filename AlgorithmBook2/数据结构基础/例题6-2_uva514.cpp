#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1000 + 10;
int b[maxn];
int main()
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int num;
    while (scanf("%d", &num) == 1)
    {
        stack<int> s;
        while (1)
        {
            scanf("%d", &b[1]);
            if (b[1] == 0)
                break;
            for (int i = 2; i <= num; i++)
                scanf("%d", &b[i]);
            int A = 1, B = 1, ok = 1;
            while (B <= num)
            {
                if (A == b[B])
                {
                    A++, B++;
                }
                else if (!s.empty() && s.top() == b[B])
                {
                    s.pop();
                    B++;
                }
                else if (A <= num)
                    s.push(A++);
                else
                {
                    ok = 0;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}