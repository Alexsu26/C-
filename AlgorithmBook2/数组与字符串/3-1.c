// 给出TT 个由OO 和XX 组成的字符串，长度小于等于80，统计所有字符的得分和。
// 每个OO 的得分为目前连续出现的O的个数，X的得分为0 。
// 例如，OOXXOXXOOOOOXXOXXOOO 的得分1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3
// = 101 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3 = 10 。

#include <stdio.h>
#include <string.h>
#define maxn 85
int main()
{
    int num;
    scanf("%d", &num);
    int s[maxn];
    int cnt = 0;
    while (num--)
    {
        char str[maxn];
        int sum = 0;
        int n = 0;

        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == 'O')
                n++;
            sum += n;
            if (str[i + 1] != 'O')
                n = 0;
            /*精简写法
            if (str[i] == 'O'){
                n++;
                sum += n;
            }
            else
                n = 0;
            */
        }
        s[cnt++] = sum;
    }
    for (int i = 0; i < cnt; i++)
        printf("%d\n", s[i]);
    return 0;
}