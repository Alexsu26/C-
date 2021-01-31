#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
struct dot
{
    int x;
    int y;
};

bool cmp1(dot x, dot y)
{
    if (x.x == y.x)
        return x.y < y.y;
    else
        return x.x < y.x;
}
bool cmp2(dot x1, dot y1)
{
    if (x1.x == y1.x)
        return x1.y < y1.y;
    else
        return x1.x > y1.x;
}
int main()
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n, num;
    cin >> n;
    while (n--)
    {
        dot dots[maxn], dots2[maxn];
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> dots[i].x >> dots[i].y;
            dots2[i].x = dots[i].x;
            dots2[i].y = dots[i].y;
        }

        bool flag = true;
        sort(dots, dots + num, cmp1);
        sort(dots2, dots2 + num, cmp2);
        double mid = (dots[0].x + dots[num - 1].x) / 2.0;
        for (int i = 0; i < num; i++)
        {
            if ((mid - dots[i].x) != (dots2[i].x - mid) || dots[i].y != dots2[i].y)
            {
                flag = false;
                cout << "NO\n";
                break;
            }
        }
        if (flag)
            cout << "YES\n";
    }
    return 0;
}