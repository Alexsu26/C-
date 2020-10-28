// [输入] 输入数据≤40组，对于每组数据，第一行有三个数：
// 第一个数代表红方棋数 N(2≤N≤7) ，第二三个数代表黑将的坐标 接下来N行每行一个字符两个数，代表每个红子的详细信息，
// 字符为棋子种类车((R), 马(H), 炮(C)) ，数字为坐标.输入所有棋子的位置, 
// 保证局面合法并且红方已经将军。
// [输出] 对于每组输出数据，如已经将死 ，输出‘YES’，反之输出‘NO’
// 车、帅；马；炮
#include <stdio.h>
#include <string.h>

struct xiangqi
{
    char name;
    int x;
    int y;
} info[8];

int qipan[11][10];
int RGC = 0, H = 0, i;

int checkinfo(int x, int y)
{
    for (i = 0; i < 10; i++)
    {
        if (info[i].x == x && info[i].y == y)
            return i;
    }
    return -1;
}
int isB(int x, int y)
{
    int k = checkinfo(x, y);
    if (info[k].name == 'B')
        return 1;
    else
        return 0;
}
int checkRGC(int x, int y, char name, int k)
{
    int count = 0;
    int inLine = 0;
    if (info[0].x == x)
    {
        inLine = 1;
        int add = info[0].y > y ? 1 : -1;
        for (i = y + add; i != info[0].y; i += add)
            if (qipan[x][i])
                count++;
    }
    else if (info[0].y == y)
    {
        inLine = 1;
        int add = info[0].x > x ? 1 : -1;
        for (i = x + add; i != info[0].x; i += add)
            if (qipan[i][y])
                count++;
    }
    if ((name == 'R') && inLine)
    {
        if (count)
            RGC = 0;
        else
            RGC = 1;
    }
    else if ((name == 'G') && inLine)
    {
        if (k == 5)
        {
            RGC = -1;
        }
        else
        {
            if (count)
                RGC = 0;
            else
                RGC = 1;
        }
    }
    else if (name == 'C' && inLine)
    {
        if (count == 1)
            RGC = 1;
        else
            RGC = 0;
    }
    else
        RGC = 0;
    return 0;
}
int checkH(int x, int y)
{
    if (isB(x + 2, y + 1) && (qipan[x + 1][y] != 1))
        H = 1;
    else if (isB(x + 2, y - 1) && (qipan[x + 1][y] != 1))
        H = 1;
    else if (isB(x - 2, y + 1) && (qipan[x - 1][y] != 1))
        H = 1;
    else if (isB(x - 2, y - 1) && (qipan[x - 1][y] != 1))
        H = 1;
    else if (isB(x + 1, y + 2) && (qipan[x][y + 1] != 1))
        H = 1;
    else if (isB(x - 1, y + 2) && (qipan[x][y + 1] != 1))
        H = 1;
    else if (isB(x + 1, y - 2) && (qipan[x][y - 1] != 1))
        H = 1;
    else if (isB(x - 1, y - 2) && (qipan[x][y - 1] != 1))
        H = 1;
    else
        H = 0;
    return 0;
}
int legal(int x, int y)
{
    if (y < 4 || y > 6 || x < 1 || x > 3)
        return 0;
    else
        return 1;
}
int clear(int num)
{
    qipan[info[num].x][info[num].y] = 0;
    info[num].name = 'A';
    info[num].x = info[num].y = 0;
    return 0;
}
int add(int x, int y)
{
    info[0].name = 'B';
    info[0].x = x;
    info[0].y = y;
    qipan[x][y] = 1;
    return 0;
}
void print(int n)
{
    for (int i = 0; i < n; i++)
        printf("%c %d %d\n", info[i].name, info[i].x, info[i].y);
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 10; j++)
            printf("%d ", qipan[i][j]);
        printf("\n");
    }
    return;
}
int main(int argc, char const *argv[])
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    memset(qipan, 0, sizeof(qipan));
    int n;
    int move[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
    int x, y;
    while (scanf("%d%d%d", &n, &x, &y) == 3 && n)
    {
        int flag;
        int cnt = 1;
        while (n--)
        {
            getchar();
            scanf("%c%d%d", &info[cnt].name, &info[cnt].x, &info[cnt].y);
            qipan[info[cnt].x][info[cnt].y] = 1;
            cnt++;
        }
        //算出下一步
        for (int k = 0; k < 6; k++)
        {
            int x1, y1;
            flag = 1, RGC = H = 0;
            // add(x,y);
            if (k < 4)
            {
                x1 = x + move[k][0];
                y1 = y + move[k][1];
            }
            if (k == 4)
            {
                x1 = 2;
                y1 = 5;
            }
            if (k == 5)
            {
                x1 = x;
                y1 = y;
            }
            if (legal(x1, y1))
            {
                int num;
                // clear(0);
                int is = checkinfo(x1, y1);
                if (is != -1)
                    clear(is);
                add(x1, y1);
                // print(cnt);
                for (num = 1; num < cnt; num++)
                {
                    switch (info[num].name)
                    {
                    case 'R':
                        checkRGC(info[num].x, info[num].y, 'R', k);
                        break;
                    case 'H':
                        checkH(info[num].x, info[num].y);
                        break;
                    case 'C':
                        checkRGC(info[num].x, info[num].y, 'C', k);
                        break;
                    case 'G':
                        checkRGC(info[num].x, info[num].y, 'G', k);
                        break;
                    }
                    if ((RGC == 1) || (H == 1))
                        break;
                    // if( k==5 && RGC == -1)
                    //     flag = 0;
                }
                if (num == cnt)
                {
                    if (k == 5)
                    {
                        if (RGC == -1)
                            flag = 0;
                        else
                            flag = 1;
                    }
                    else
                        flag = 0;
                }
            }
            clear(0);
            if (!flag)
            {
                printf("NO\n");
                break;
            }
        }

        if (flag)
            printf("YES\n");
        memset(qipan, 0, sizeof(qipan));
    }
    return 0;
}
