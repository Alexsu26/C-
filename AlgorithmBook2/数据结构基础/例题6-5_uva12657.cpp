#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
int _left_[maxn], _right_[maxn];

void link(int l, int r)
{
    _right_[l] = r;
    _left_[r] = l;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    int kase = 0;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            _left_[i] = i - 1;
            _right_[i] = (i + 1) % (n + 1);
        }
        _left_[0] = n;
        _right_[0] = 1;

        int op;
        bool inv = false;
        int X, Y;
        while (m--)
        {
            scanf("%d", &op);
            if (op == 4)
                inv = !inv;
            else
            {
                scanf("%d%d", &X, &Y);
                if (inv && op != 3)
                    op = 3 - op;
                if (op == 3 && _right_[Y] == X)
                    swap(X, Y);//简化后面的代码，可以将x在y两侧的情况简化为只在一侧的情况
                if (op == 1 && X == _left_[Y])
                    continue;
                if (op == 2 && X == _right_[Y])
                    continue;

                int LX = _left_[X], RX = _right_[X];
                int LY = _left_[Y], RY = _right_[Y];
                if (op == 1)
                {
                    link(LX, RX);
                    link(LY, X);
                    link(X, Y);
                }
                else if (op == 2)
                {
                    link(LX, RX);
                    link(Y, X);
                    link(X, RY);
                }
                else if (op == 3)
                {
                    if (_right_[X] != Y)
                    {
                        link(LX, Y);
                        link(Y, RX);
                        link(LY, X);
                        link(X, RY);
                    }
                    else
                    {
                        link(LX, Y);
                        link(Y, X);
                        link(X, RY);
                    }
                }
            }
        }

        int x = 0;
        long long ans = 0;//n可达100000，int型不足以存储
        for (int i = 1; i <= n; i++)
        {
            x = _right_[x];
            if (i % 2 == 1)
                ans += x;
        }
        if (inv && n % 2 == 0)//n为奇偶会影响正反时奇数的编号
            ans = (long long)n * (n + 1) / 2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);//longlong型输出用%lld
    }
    return 0;
}