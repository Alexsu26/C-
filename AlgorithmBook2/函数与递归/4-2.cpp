// 输入包含了多个游戏棋盘。
// 每个棋盘包含了 n ^ 2 个点的正方形矩阵(其中 2 ≤ n ≤ 9) ，
// 以及一些起连接作用的横向或纵向的线段。
// 棋盘的的 n ^ 2 个点和 m 条连接线段，格式如下：
#define LOCAL
#include <stdio.h>
#include <string.h>

int check(int x, int y, int size);

int H[10][10], V[10][10];

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    int count = 0;
    while (scanf("%d", &n) == 1)
    {
        if (count)
            printf("\n**********************************\n\n");
        int num;
        scanf("%d", &num);
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        int flag = 0;
        while (num--)
        {
            char x;
            int h, v;
            getchar();
            scanf("%c%d%d", &x, &h, &v);
            if (x == 'H')
                H[h][v] = 1;
            else
                V[v][h] = 1;
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (check(i, j, k))
                    {
                        cnt[k]++;
                        flag = 1;
                    }
                }
            }
        printf("Problem #%d\n\n", ++count);
        if (flag)
        {
            for (int i = 1; i <= n; i++)
            {
                if (cnt[i] > 0)
                    printf("%d square (s) of size %d\n", cnt[i], i);
            }
            // printf("\n");
        }
        else
            printf("No completed squares can be found.\n");
    }
    return 0;
}
int check(int x, int y, int size)
{
    int flagx = 0, flagy = 0, i;
    for (i = y; i < y + size; i++)
    {
        if (H[x][i] == 0 || H[x + size][i] == 0)
            break;
    }
    if (i == (y + size))
        flagx = 1;
    for (i = x; i < x + size; i++)
    {
        if (V[i][y] == 0 || V[i][y + size] == 0)
            break;
    }
    if (i == (x + size))
        flagy = 1;
    if (flagx && flagy)
        return 1;
    else
        return 0;
}